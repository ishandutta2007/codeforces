#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

vector<vector<int>> g;
vector<int> mkd;

void dfs(int v){
    mkd[v] = 1;
    for(auto u: g[v]){
        if(mkd[u]){
            continue;
        }
        dfs(u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;
    int x, y;
    g.resize(n + m);
    mkd.resize(n + m, 0);
    for(int i = 0; i < q; ++i){
        cin >> x >> y;
        --x;
        --y;
        g[x].push_back(y + n);
        g[y + n].push_back(x);
    }
    int cnt = -1;
    for(int i = 0; i < n + m; ++i){
        if(!mkd[i]){
            dfs(i);
            ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}