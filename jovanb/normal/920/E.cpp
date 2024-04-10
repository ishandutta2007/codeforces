#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

set <int> graf[200005];
int cnt;

set <int> unvisited;
bool visited[200005];

void dfs(int v){
    unvisited.erase(v);
    visited[v] = 1;
    cnt++;
    int lastvis = 0;
    for(;;){
        auto x = unvisited.upper_bound(lastvis);
        if(x == unvisited.end()) break;
        int c = *x;
        lastvis = c;
        if(graf[v].find(c) == graf[v].end()) dfs(c);
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) unvisited.insert(i);
    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        graf[a].insert(b);
        graf[b].insert(a);
    }
    vector <int> comps;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            cnt = 0;
            dfs(i);
            comps.push_back(cnt);
        }
    }
    cout << comps.size() << "\n";
    sort(comps.begin(), comps.end());
    for(auto c : comps) cout << c << " ";
    return 0;
}