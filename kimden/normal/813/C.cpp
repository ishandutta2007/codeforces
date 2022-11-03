#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int MAXN = 200005;
vector<int> g[MAXN];
int h[MAXN];
int maxh[MAXN];

int x, y = -1;
vector<int> path;

int dfs(int v, int p = -1){
    path.push_back(v);
    if(x == v){
        y = path[path.size() - path.size() / 2];
    }
    int ans = 0;
    for(auto u: g[v]){
        if(u == p){
            continue;
        }
        h[u] = h[v] + 1;
        ans = max(ans, dfs(u, v) + 1);
    }
    path.pop_back();
    return maxh[v] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n >> x;
    --x;
    int a, b;
    for(int i = 0; i < n - 1; ++i){
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    h[0] = 0;
    dfs(0);
    cout << (maxh[y] + h[y]) * 2 << endl;
    return 0;
}