#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, P[2020], k[2020];
int x[2020], y[2020];

int find(int u){
    return P[u] = (P[u] == u ? u : find(P[u]));
}

bool join(int u, int v){
    u = find(u),v = find(v);
    P[u] = v; return u != v;
}

int dist(int u, int v){
    return abs(x[u] - x[v]) + abs(y[u] - y[v]); 
}

signed main(){
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
        P[i] = i;
    }
    vector<pair<int, pair<int, int>>> edge;
    for (int i = 1, c; i <= n; i++){
        cin >> c;
        edge.push_back({c, {i, 0}});
    }
    for (int i = 1; i <= n; i++){
        cin >> k[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j < i; j++){
            edge.push_back({(k[i] + k[j]) * dist(i, j), {i, j}});
        }
    }
    sort(edge.begin(), edge.end());
    vector<int> gg; int res = 0;
    vector<pair<int, int>> ans;
    for (auto [c, p] : edge){
        if (join(p.first, p.second)){
            if (p.second){
                ans.push_back(p);
            }else{
                gg.push_back(p.first);
            }
            res += c;
        }
    }
    cout << res << "\n";
    cout << gg.size() << "\n";
    for (auto v : gg) cout << v << ' ';
    cout << "\n";
    cout << ans.size() << "\n";
    for (auto [u, v] : ans)
        cout << u << ' ' << v << "\n";
}