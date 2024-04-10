#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 100000;

map <int, ll> q[N+5];
int gde[N+5];
int t[N+5], val[N+5];

vector <int> graf[N+5];

void dfs(int v){
    int mx = 0;
    for(auto c : graf[v]){
        dfs(c);
        if(!mx || q[gde[c]].size() > q[gde[mx]].size()) mx = c;
    }
    if(!mx){
        gde[v] = v;
        if(val[v]) q[v][t[v]] += val[v];
        return;
    }
    gde[v] = gde[mx];
    for(auto c : graf[v]){
        if(c == mx) continue;
        for(auto h : q[gde[c]]) q[gde[v]][h.first] += h.second;
    }
    if(val[v]){
        q[gde[v]][t[v]] += val[v];
        auto x = q[gde[v]].upper_bound(t[v]);
        x->second -= val[v];
        while(x != q[gde[v]].end()){
            auto y = x;
            y++;
            if(x->second >= 0) break;
            if(y != q[gde[v]].end()) y->second += x->second;
            q[gde[v]].erase(x->first);
            x = y;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m, k;
    cin >> n >> m >> k;
    for(int i=2; i<=n; i++){
        int x;
        cin >> x;
        graf[x].push_back(i);
    }
    for(int i=1; i<=m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        t[a] = b, val[a] = c;
    }
    dfs(1);
    ll res = 0;
    for(auto c : q[gde[1]]) res += c.second;
    cout << res << "\n";
    return 0;
}