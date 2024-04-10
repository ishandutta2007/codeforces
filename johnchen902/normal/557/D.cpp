#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
using namespace std::placeholders;

vector<int> adj[100000];
int vis[100000];

bool dfs(int v, int p, bool odd = false) {
    if(vis[v])
        return odd == (vis[v] == 2);
    vis[v] = odd ? 1 : 2;
    for(int c : adj[v])
        if(c != p && dfs(c, v, !odd))
            return true;
    return false;
}

bool has_odd_cycle(int n) {
    for(int i = 0; i < n; i++)
        if(!vis[i] && dfs(i, -1))
            return true;
    return false;
}

void dfs(int v, int p, int& e, int& o) {
    if(vis[v])
        return;
    vis[v] = true;
    o++;
    for(int c : adj[v])
        if(c != p)
            dfs(c, v, o, e);
}

long long count_1_edge(int n) {
    fill_n(vis, n, false);

    long long ans = 0;
    for(int i = 0; i < n; i++)
        if(!vis[i]) {
            int e = 0, o = 0;
            dfs(i, -1, e, o);
            ans += (e * (e - 1LL) + o * (o - 1LL)) / 2;
        }
    return ans;
}



int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if(has_odd_cycle(n)) {
        puts("0 1");
    } else if(any_of(adj, adj + n, bind(greater_equal<int>(), bind(&vector<int>::size, _1), 2))) {
        printf("1 %I64d\n", count_1_edge(n));
    } else if(m) {
        printf("2 %I64d\n", m * (n - 2LL));
    } else {
        printf("3 %I64d\n", n * (n - 1LL) * (n - 2) / 6);
    }
}