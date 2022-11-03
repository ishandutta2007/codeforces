#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> s(n);
    vector<vector<string>> gs(n);
    vector<vector<int>> gv(n);
    vector<vector<int>> g(n);
    vector<int> v(n), deg(n);
    for(int i = 0; i < n; ++i){
        cin >> s[i] >> v[i];
        cin >> deg[i];
        gs[i].resize(deg[i]);
        gv[i].resize(deg[i]);
        g[i].resize(deg[i]);
        for(int j = 0; j < deg[i]; ++j){
            cin >> gs[i][j] >> gv[i][j];
        }
    }
    map<pair<string, int>, int> mp;
    for(int i = 0; i < n; ++i){
        mp[{s[i], v[i]}] = i;
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < deg[i]; ++j){
            g[i][j] = mp[{gs[i][j], gv[i][j]}];
        }
    }
    map<string, int> res;
    res[s[0]] = 0;
    vector<int> cur = {0};
    vector<string> nxt;
    const int INF = 1000000000;
    vector<int> dist(n, INF);
    dist[0] = 0;
    for(int d = 0; d < 1002; ++d){
        for(auto z: cur){
            for(auto u: g[z]){
                if(dist[u] == INF){
                    dist[u] = dist[z] + 1;
                    auto it = res.find(s[u]);
                    if(it == res.end() || dist[it->second] > dist[u] || (dist[it->second] == dist[u] && v[it->second] < v[u])){
                        res[s[u]] = u;
                        nxt.push_back(s[u]);
                    }
                }
            }
        }
        cur.clear();
        for(auto str: nxt){
            cur.push_back(res[str]);
        }
        nxt.clear();
    }
    cout << res.size() - 1 << endl;
    for(auto p: res){
        if(p.second != 0){
            cout << p.first << " " << v[p.second] << endl;
        }
    }
}