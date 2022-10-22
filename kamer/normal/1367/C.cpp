#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> occ(n);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') occ[i] = 0;
            else occ[i] = 1;
        }
        vector<int> newOcc(occ);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (occ[i] == 1) count = k;
            else {
                if (count > 0) {
                    newOcc[i] = 1;
                    count--;
                }
            }
        }
        count = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (occ[i] == 1) count = k;
            else {
                if (count > 0) {
                    newOcc[i] = 1;
                    count--;
                }
            }
        }
        int countZero = 0;
        int lastOcc = - k - 10;
        for (int i = 0; i < n; i++) {
            if (newOcc[i] == 0 && i - lastOcc > k) {
                countZero++;
                lastOcc = i;
            }
        }
        cout << countZero << "\n";
    }
}