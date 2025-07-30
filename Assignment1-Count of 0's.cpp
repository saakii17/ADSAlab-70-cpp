//Implement a problem of no of zeros
//Statement:Given array of 1's and 0' which has all is followed by 0's.Find no of 0's and give count of no of 0's in given array.
//Input:Enter size of array: 7
    //Enter elements: 1 1 1 0 0 0 0
//Output:Count of 0's:4

#include<iostream>
using namespace std;

int main() {
    int a[10], n, high = 0, low = 0, mid = 0;
    
    cout << "\nEnter size of array:\t";// Ask user to enter array size
    cin >> n;

    high = n - 1;// Set upper bound for binary search

    cout << "\nEnter elements in sorted order (1's and 0's):\n";// Input array elements - must be sorted (all 1's followed by 0's)
    for(int i = 0; i < n; i++) {
        cin >> a[i];// Read each element into array
    }

    mid = (high + low) / 2;

    cout << "Count of 0's:\n";// Begin binary search to count 0's

    while (low <= high) {
        mid = (low + high) / 2;// Calculate middle index

        if (a[mid] == 1) {  // Check if transition to 0 happens at next position
                      if (mid + 1 < n && a[mid + 1] == 0) {  // Count of 0's = total elements - index of first 0
                cout << n - (mid + 1) << endl;
                break;
            } else { // Move to right half
                low = mid + 1;
            }
        } else if (a[mid] == 0) { / Check if this is the first 0 in the array
            if (mid == 0 || a[mid - 1] == 1) {
                cout << n - mid << endl;// Count of 0's = total elements - index of first 0
                break;
            } else { // Move to left half
                high = mid - 1;
            }
        }
    }

    return 0;
}
