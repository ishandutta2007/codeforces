#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int powerTwo = 0, powerThree = 0;
        while (n % 2 == 0) {
            n /= 2;
            powerTwo++;
        }
        while (n % 3 == 0) {
            n /= 3;
            powerThree++;
        }
        if (n != 1) {
            cout << "-1\n";
        } else {
            if (powerTwo > powerThree) {
                cout << "-1\n";
            } else {
                cout << 2 * powerThree - powerTwo << "\n";
            }
        }
    }
}