#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100005;
const int MOD = 1000000007;

int n, m, h[N * 2], hn;
int dp[N * 2];

struct ST {
    int s, t;

    void read() {
        scanf("%d%d", &s, &t);
        h[hn++] = s;
        h[hn++] = t;
    }

    bool operator < (const ST& c) const {
        return t < c.t;
    }
} st[N];

vector<int> g[N * 2];
int sum[N * 2];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) st[i].read();
    h[hn++] = 0; h[hn++] = n;
    sort(h, h + hn);
    hn = unique(h, h + hn) - h;
    for (int i = 0; i < m; i++) {
        st[i].s = lower_bound(h, h + hn, st[i].s) - h;
        st[i].t = lower_bound(h, h + hn, st[i].t) - h;
        g[st[i].t].push_back(i);
    }
    dp[0] = 1;
    for (int i = 0; i < hn; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            int id = g[i][j];
            dp[i] = (dp[i] + (sum[i - 1] - sum[st[id].s - 1] + MOD) % MOD) % MOD;
        }
        sum[i] = (sum[i - 1] + dp[i]) % MOD;
    }
    printf("%d\n", dp[hn - 1]);
    return 0;
}