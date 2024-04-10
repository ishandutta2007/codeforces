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
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;

        vector<int> dl(n, -1), dr(n, -1);

        for (int i=0; i<n; i++) {
            if (s[i] == '1') {
                dl[i] = 0;
            } else if (i > 0) {
                if (dl[i-1] != -1) {
                    dl[i] = dl[i-1] + 1;
                }
            }
        }

        for (int i=n-1; i>=0; i--) {
            if (s[i] == '1') {
                dr[i] = 0;
            } else if (i < n - 1) {
                if (dr[i+1] != -1) {
                    dr[i] = dr[i+1] + 1;
                }
            }
        }

        for (int i=0; i<n; i++) {
            if (dl[i] != dr[i]) {
                int tl = dl[i], tr = dr[i];
                if (tl == -1) tl = 1123123123;
                if (tr == -1) tr = 1123123123;
                int t = min(tl, tr);
                if (t <= m) {
                    s[i] = '1';
                }
            }
        }

        cout << s << '\n';
    }
}