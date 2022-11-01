#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
namespace {
vector<int> adj[200000];
int newroot = -1;
int dfs(int v, int p) {
    vector<int> d;
    for(int c : adj[v])
        if(c != p) {
            int x = dfs(c, v);
            if(x == -1)
                return -1;
            d.push_back(x + 1);
        }
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    if(d.empty())
        return 0;
    if(d.size() == 1)
        return d[0];
    if(d.size() == 2 && p == -1)
        return d[0] + d[1];
    newroot = v;
    return -1;
}
int solve(int) {
    int ans = dfs(0, -1);
    if(ans < 0 && newroot >= 0)
        ans = dfs(newroot, -1);
    if(ans < 0)
        return -1;
    while(ans % 2 == 0)
        ans /= 2;
    return ans;
}
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
    printf("%d\n", solve(n));
}