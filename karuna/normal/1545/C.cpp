#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

const int M = 510, MOD = 998244353;
int n, G[M << 1][M << 1], X[M][M], A[M << 1][M], B[M], Col[M << 1], Chk[M << 1], Vis[M << 1];
vector<int> Ans;

void dfs(int cur) {
    Vis[cur] = 1;
    for (int i = 1; i <= 2 * n; i++) if (!Chk[i] && !Vis[i]) {
        if (G[cur][i]) Col[i] = !Col[cur], dfs(i);
    }
}
void solve() {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 1; j <= n; j++) cin >> A[i][j];
    }
    for (int i = 1; i <= 2 * n; i++) for (int j = 1; j <= 2 * n; j++) {
        if (i == j) continue;
        int s = 0;
        for (int k = 1; k <= n; k++) {
            if (A[i][k] == A[j][k]) ++s;
        }
        if (s) G[i][j] = 1;
        else G[i][j] = 0;
    }
    Ans.clear(); memset(Chk, 0, sizeof Chk);
    while (1) {
        int s = 0; vector<int> V;
        for (int j = 1; j <= n; j++) {
            memset(B, 0, sizeof B);
            for (int i = 1; i <= 2 * n; i++) if (Chk[i] != 2) {
                int x = A[i][j];
                if (!B[x]) B[x] = i;
                else B[x] = -1;
            }
            for (int i = 1; i <= n; i++) {
                if (B[i] && B[i] != -1 && !Chk[B[i]]) {
                    V.push_back(B[i]); Chk[B[i]] = 1; s += 1;
                }
            }
        }
        if (s == 0) break;
        for (int x : V) for (int i = 1; i <= 2 * n; i++) if (!Chk[i]) {
            if (G[x][i]) Chk[i] = 2;
        }
        while (!V.empty()) Ans.push_back(V.back()), V.pop_back();
    }
    memset(Col, 0, sizeof Col); memset(Vis, 0, sizeof Vis);
    int ret = 1, ans = 0;
    for (int i = 1; i <= 2 * n; i++) if (!Chk[i] && !Vis[i]) {
        dfs(i); ans += 1;
    }
    while (ans--) ret = ret * 2 % MOD;
    for (int i = 1; i <= 2 * n; i++) if (Col[i]) Ans.push_back(i);

    cout << ret << '\n';
    for (int x : Ans) cout << x << ' '; cout << '\n';
}
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}