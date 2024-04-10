#include<bits/stdc++.h>

using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define de(x) cout<< #x << ' ' << x << endl;
const int N = 1e6 + 5;
const int inf = 0x3f3f3f3f;

vector<int> g[N];
vector<int> rg[N];
int dis[N];
int cnt[N];

int n, m;

signed main() {

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        rg[v].push_back(u);
        cnt[u]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<>> que;
    for (int i = 1; i <= n; i++) dis[i] = inf;
    dis[n] = 0, que.push({0, n});
    while (!que.empty()) {
        auto [d, pos] = que.top();
        que.pop();
        if (dis[pos] < d) continue;
        for (auto x: rg[pos]) {
            cnt[x]--;
            if (dis[x] > dis[pos] + cnt[x] + 1) {
                dis[x] = dis[pos] + cnt[x] + 1;
                que.push({dis[x], x});
            }
        }
    }

    printf("%d\n", dis[1]);
}