#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        // check if k exists
        if (n == 1) {
            if (a[0] == k) {
                cout << "yes\n";
            } else {
                cout << "no\n";
            }
        } else {
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (a[i] == k) {
                    found  = true;
                    break;
                }
            }
            if (!found) {
                cout << "no\n";
            } else {
                int oldPos = -4;
                bool found = false;
                for (int i = 0; i < n; i++) {
                    if (a[i] >= k) {
                        if (i - oldPos <= 2) {
                            cout << "yes\n";
                            found = true;
                            break;
                        }
                        oldPos = i;
                    }
                }
                if (!found) {
                    cout << "no\n";
                }
            }
        }
    }
    return 0;
}