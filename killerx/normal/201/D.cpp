#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

void upd(int &x, int y) {
    if (y < x) x = y;
}

int n, m, k;
vector <string> s, t;
int dp[1 << 15][15 * 14 / 2 + 1];
int nex[500005][15];

int main() {
    cin >> n;
    s.resize(n);
    rep(i, n) cin >> s[i];
    cin >> m;
    pair <int, int> ans(0, -1);
    rep(tc, m) {
        cin >> k;
        t.resize(k);
        rep(i, k) cin >> t[i];
        rep(i, n) nex[k][i] = k;
        for (int i = k - 1; ~i; -- i) {
            rep(j, n) nex[i][j] = nex[i + 1][j];
            rep(j, n) if (t[i] == s[j]) nex[i][j] = i;
        }
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = -1;
        rep(S, 1 << n) {
            rep(invs, n * (n - 1) / 2 + 1) {
                rep(i, n) if (!(S >> i & 1)) {
                    int ninvs = invs;
                    ninvs += __builtin_popcount(S >> i);
                    if (dp[S][invs] + 1 < k) {
                        upd(dp[S | 1 << i][ninvs], nex[dp[S][invs] + 1][i]);
                    }
                }
            }
        }
        int p = 0;
        rep(invs, n * (n - 1) / 2 + 1) {
            if (dp[(1 << n) - 1][invs] < k) {
                p = max(p, n * (n - 1) / 2 - invs + 1);
            }
        }
        if (p > 0) ans = max(ans, mp(p, -tc));
    }
    if (ans.first == 0) {
        cout << "Brand new problem!" << endl;
        return 0;
    }
    cout << -ans.second + 1 << endl;
    cout << "[:";
    rep(i, ans.first) cout << "|";
    cout << ":]";
    return 0;
}