#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

vector<vector<int>> g;

int sum = 0;
int n, x, y;
int szy = 0;

pair<int, bool> dfs(int v, int prv = -1){
    int sz = 1;
    bool wasy = 0;
    for(auto u: g[v]){
        if(u != prv){
            auto xx = dfs(u, v);
            sz += xx.first;
            wasy = (wasy || xx.second);
            if(v == x && xx.second){
                sum += xx.first;
            }
        }
    }
    if(v == y){
        szy = sz;
        return {sz, 1};
    }
    return {sz, wasy};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> x >> y;
    --x;
    --y;
    int a, b;
    g.resize(n);
    for(int i = 0; i < n - 1; ++i){
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(x);
    cout << (((n * ll(n - 1))) - (n - sum) * ll(szy)) << endl;
}