#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
const int N = 300005;
const int MOD = 1000000007;
int n, Q, i, nod, vis[N];
__int64 kbit[N], sbit[N], cnt = 0, l[N], r[N], dep[N];
vector<int> g[N];
void dfs(int u, __int64 d) {
    vis[u] = 1; dep[u] = d;
    cnt++; l[u] = cnt;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (vis[v]) continue;
        dfs(v, d + 1);
    }
    r[u] = cnt;
}

void Is(__int64 value, int x, __int64 *num) {
    while (x <= N) {
        num[x] = (num[x] + value) % MOD;
        x += (x&(-x));
    }
}

__int64 Sum(int x, __int64 *num) {
    __int64 ans = 0;
    while (x > 0) {
        ans = (ans + num[x]) % MOD;
        x -= (x&(-x));
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    for (i = 2; i <= n; i++) {
        scanf("%d", &nod);
        g[nod].push_back(i);
    }
    dfs(1, 0);
    scanf("%d", &Q);
    while (Q--) {
        int type, v;
        scanf("%d%d", &type, &v);
        if (type == 1) {
            __int64 x, k;
            scanf("%I64d%I64d", &x, &k);
            __int64 val = (x + dep[v] * k) % MOD;
            Is(k, l[v], kbit);
            Is(-k, r[v] + 1, kbit);
            Is(val, l[v], sbit);
            Is(-val, r[v] + 1, sbit);
        }
        else printf("%I64d\n", ((Sum(l[v], sbit) - dep[v] * Sum(l[v], kbit)) % MOD + MOD) % MOD);
    }
    return 0;
}