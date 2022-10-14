#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 5005;

int t, n;
int tag[MAXN], s[MAXN];
llint lo[MAXN], hi[MAXN], prosli_lo[MAXN], prosli_hi[MAXN], val[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> tag[i];
        for (int i = 1; i <= n; i++) cin >> s[i];
        for (int i = 1; i <= n; i++) val[i] = 0;
        llint sol = 0;
        for (int b = n; b >= 1; b--) {
            for (int a = 1; a < b; a++) {
                if (b < n) {
                    lo[a] = prosli_lo[a];
                    if (tag[a] != tag[b + 1]) {
                        lo[a] = max(lo[a], prosli_hi[a] + abs(s[a] - s[b + 1]));
                    }
                } else {
                    lo[a] = 0;
                }
            }
            for (int a = 1; a < b; a++) {
                if (a > 1) {
                    hi[a] = hi[a - 1];
                    if (tag[a - 1] != tag[b]) {
                        hi[a] = max(hi[a], lo[a - 1] + abs(s[a - 1] - s[b]));
                    }
                } else {
                    hi[a] = 0;
                }
                hi[a] = max(hi[a], val[b]);
                if (tag[a] != tag[b]) val[a] = max(val[a], hi[a] + abs(s[a] - s[b]));
            }
            for (int a = 1; a < b; a++) {
                prosli_lo[a] = lo[a];
                prosli_hi[a] = hi[a];
                if (tag[a] != tag[b]) {
                    sol = max(sol, lo[a] + abs(s[a] - s[b]));
                    sol = max(sol, hi[a] + abs(s[a] - s[b]));
                }
            }
        }
        cout << sol << '\n';
    }
    return 0;
}