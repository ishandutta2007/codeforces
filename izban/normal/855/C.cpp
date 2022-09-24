#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = (int)1.01e9;
const int N = 1 << 17;
const int MOD = (int)1e9 + 7;
const int K = 11;

int n, m;
vector<int> e[N];
int k, x;

int dp[N][K][3];
int ndp[K];

void add(int &x, ll y) {
    x = (x + y) % MOD;
}

void dfs(int v, int pr) {
    memset(dp[v], 0, sizeof(dp[v]));

    for (int to : e[v]) {
        if (to == pr) continue;
        dfs(to, v);
    }

    for (int cur = 0; cur < 3; cur++) {
        for (int i = 0; i <= x; i++) dp[v][i][cur] = 0;

        int cf1 = 0;
        if (cur == 0) cf1 = k;
        if (cur == 1) cf1 = 1;
        if (cur == 2) cf1 = m - k - 1;

        dp[v][(int)(cur == 1)][cur] = cf1;


        for (int to : e[v]) {
            if (to == pr) continue;
            for (int i = 0; i <= x; i++) ndp[i] = 0;
            for (int my = 0; my <= x; my++) {
                if (dp[v][my][cur] == 0) continue;

                for (int ecur = 0; ecur < 3; ecur++) {
                    if (cur == 1 && ecur != 0 || ecur == 1 && cur != 0) continue;
                    /*int cf2 = 0;
                    if (ecur == 0) cf2 = k;
                    if (ecur == 1) cf2 = 1;
                    if (ecur == 2) cf2 = m - k - 1;*/
                    for (int th = 0; my + th <= x; th++) {
                        //add(ndp[my + th], 1LL * dp[v][my][cur] * dp[to][th][ecur] % MOD * cf2);
                        add(ndp[my + th], 1LL * dp[v][my][cur] * dp[to][th][ecur]);
                    }
                }
            }
            for (int i = 0; i <= x; i++) dp[v][i][cur] = ndp[i];
        }
    }
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 0; i < n; i++) {
            e[i].clear();
        }
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            --u; --v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        scanf("%d%d", &k, &x);
        k--;

        dfs(0, -1);
        int ans = 0;
        for (int i = 0; i <= x; i++) {
            for (int j = 0; j < 3; j++) {
                add(ans, dp[0][i][j]);
            }
        }
        printf("%d\n", ans);
    }

#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}