#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int N = 100005;

int n, m, a[N], b[N], du[N];
vector<int> g[N];
queue<int> Q;

bool judge(int k) {
    while (!Q.empty()) Q.pop();
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        du[i] = 0;
    }
    for (int i = 1; i <= k; i++) {
        g[a[i]].push_back(b[i]);
        du[b[i]]++;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (du[i] == 0) Q.push(i);
        if (Q.size() > 1) return false;
    }
    if (Q.size() != 1) return false;
    int tot = 0;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        tot++;
        int cnt = 0;
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            du[v]--;
            if (du[v] == 0) {
                Q.push(v);
                cnt++;
            }
            if (cnt == 2) return false;
        }
    }
    return tot == n;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d%d", &a[i], &b[i]);
    if (!judge(m)) {
        printf("-1\n");
        return 0;
    }
    int l = 0, r = m;
    while (l < r) {
        int mid = (l + r)>>1;
        if (judge(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}