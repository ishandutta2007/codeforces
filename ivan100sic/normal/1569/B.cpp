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
        string s;
        cin >> n >> s;
        if (s == string(n, '1')) {
            cout << "YES\n";
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    cout << (i == j ? 'X' : '=');
                }
                cout << '\n';
            }
        } else {
            vector<int> dv;
            for (int i=0; i<n; i++) {
                if (s[i] == '2') {
                    dv.push_back(i);
                }
            }

            int k = dv.size();
            if (k >= 3) {
                cout << "YES\n";
                for (int i=0; i<n; i++) {
                    for (int j=0; j<n; j++) {
                        if (i == j) {
                            cout << 'X';
                        } else {
                            int di = find(begin(dv), end(dv), i) - begin(dv);
                            int dj = find(begin(dv), end(dv), j) - begin(dv);
                            if (di < k && dj < k) {
                                if ((di + 1) % k == dj) {
                                    cout << '+';
                                } else if ((dj + 1) % k == di) {
                                    cout << '-';
                                } else {
                                    cout << '=';
                                }
                            } else {
                                cout << '=';
                            }
                        }
                    }
                    cout << '\n';
                }
            } else {
                cout << "NO\n";
            }
        }
    }
}