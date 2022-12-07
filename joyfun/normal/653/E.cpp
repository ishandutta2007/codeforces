#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

const int N = 300005;
set<int> s;
int n, m, k, vis[N], tmp[N], tn;
set<int> g[N];

bool judge() {
    int sb = 0, sum = 0;
    for (int i = 2; i <= n; i++) {
        if (s.find(i) == s.end()) continue;
        sb++;
        if (sb > k) return false;
        queue<int> Q;
        Q.push(i);
        s.erase(s.find(i));
        int cnt = 0;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            if (vis[u]) cnt++;
            tn = 0;
            for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
                if (g[u].find(*it) != g[u].end()) continue;
                Q.push(*it);
                tmp[tn++] = *it;
            }
            for (int i = 0; i < tn; i++) s.erase(s.find(tmp[i]));
        }
        if (cnt == 0) return false;
        sum += cnt;
    }
    return sum >= k;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 2; i <= n; i++) {
        s.insert(i);
        vis[i] = 1;
    }
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        if (u > v) swap(u, v);
        if (u == 1) vis[v] = 0;
        else g[u].insert(v), g[v].insert(u);
    }
    printf("%s\n", judge() ? "possible" : "impossible");
    return 0;
}