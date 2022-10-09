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
        int n, m, k;
        cin >> n >> m >> k;
        vector<string> a(n);
        for (auto& s : a) cin >> s;

        bool ok = true;

        for (int i=n-1; i>=0; i--) {
            for (int j=0; j<m; j++) {

                auto dokle_moze = [&]() {
                    int moze = 0;
                    for (int l=0;; l++) {
                        int x = i-l, y1 = j+l, y2 = j-l;
                        if (x < 0 || y1 >= m || y2 < 0) {
                            break;
                        }

                        if (a[x][y1] == '.' || a[x][y2] == '.') {
                            break;
                        }

                        moze = l;
                    }

                    return moze;
                };

                auto farbaj = [&](int dokle) {
                    for (int l=0; l<=dokle; l++) {
                        int x = i-l, y1 = j+l, y2 = j-l;
                        a[x][y1] = a[x][y2] = 'p';
                    }
                };

                if (a[i][j] == '*') {
                    // obavezno farbanje
                    int moze = dokle_moze();
                    if (moze < k) {
                        ok = false;
                    } else {
                        farbaj(moze);
                    }
                } else if (a[i][j] == 'p') {
                    int moze = dokle_moze();
                    if (moze >= k) {
                        farbaj(moze);
                    }
                }
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j] == '*') {
                    ok = false;
                }
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}