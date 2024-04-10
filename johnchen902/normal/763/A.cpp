#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> adj[100000];
int color[100000];
bool same[100000];
void dfs1(int v, int p) {
    same[v] = true;
    for(int c : adj[v])
        if(c != p) {
            dfs1(c, v);
            if(!same[c] || color[v] != color[c])
                same[v] = false;
        }
}
int solve(int v, int p) {
    auto pred1 = [p](int c) { return c != p && !same[c]; };
    if(none_of(adj[v].begin(), adj[v].end(), pred1))
        return v;
    if(count_if(adj[v].begin(), adj[v].end(), pred1) >= 2)
        return -1;
    int u = *find_if(adj[v].begin(), adj[v].end(), pred1);
    auto pred2 = [v, u](int c) { return c != u && color[c] != color[v]; };
    if(any_of(adj[v].begin(), adj[v].end(), pred2))
        return -1;
    return solve(u, v);
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < n; i++)
        scanf("%d", color + i);
    dfs1(0, -1);
    int ans = solve(0, -1);
    if(ans < 0)
        puts("NO");
    else {
        puts("YES");
        printf("%d\n", ans + 1);
    }
}