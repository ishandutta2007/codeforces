// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }

        int c = 0;

        for (int l=0; l<n; l++) {
            for (int r=l; r<n; r++) {
                bool good = true;
                for (int i=l; i<=r; i++) {
                    for (int j=i+1; j<=r; j++) {
                        for (int k=j+1; k<=r; k++) {
                            if (a[i] <= a[j] && a[j] <= a[k]) {
                                good = false;
                                break;
                            }

                            if (a[i] >= a[j] && a[j] >= a[k]) {
                                good = false;
                                break;
                            }
                        }
                    }
                }

                if (!good) {
                    break;
                } else {
                    c++;
                }
            }
        }

        cout << c << '\n';
    }
}