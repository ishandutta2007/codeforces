#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 300000;

vector <pair <int, int>> graf[N+5];
vector <pair <int, int>> gn[N+5];

int par[N+5];
bool visited[N+5];
bool used[N+5];
int depth[N+5];
int col[N+5];

void dfs(int v, int p, int dt){
    visited[v] = 1;
    depth[v] = dt;
    for(auto c : graf[v]){
        if(visited[c.first]) continue;
        par[c.first] = v;
        gn[v].push_back({c.first, c.second});
        used[c.second] = 1;
        dfs(c.first, p, dt + 1);
    }
}

void paint(int v, int cl){
    for(auto c : gn[v]){
        col[c.second] = cl;
        paint(c.first, cl);
    }
}

int ea[N+5], eb[N+5];

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        graf[i].clear();
        gn[i].clear();
        visited[i] = 0;
    }
    for(int i=1; i<=m; i++){
        cin >> ea[i] >> eb[i];
        if(ea[i] > eb[i]) swap(ea[i], eb[i]);
        used[i] = 0;
        col[i] = 0;
        graf[ea[i]].push_back({eb[i], i});
        graf[eb[i]].push_back({ea[i], i});
    }
    dfs(1, 0, 0);
    vector <int> vec;
    for(int i=1; i<=m; i++){
        if(!used[i]) vec.push_back(i);
    }
    set <pair <int, int>> q;
    for(auto c : vec){
        q.insert({depth[ea[c]], ea[c]});
        q.insert({depth[eb[c]], eb[c]});
    }
    if(vec.size() <= 2 || q.size() > 3){
        for(int i=1; i<=m; i++){
            if(used[i]) cout << "0";
            else cout << "1";
        }
        cout << "\n";
        return;
    }
    assert(q.size() == 3);
    int p = q.begin()->second;
    q.erase(q.begin());
    int d = q.begin()->second;
    q.erase(q.begin());
    int t = q.begin()->second;
    q.erase(q.begin());
    //for(int i=2; i<=n; i++) cout << i << " do " << par[i] << endl;
    //cout << p << " i " << d << " i " << t << endl;
    paint(1, 0);
    int x = par[d];
    paint(x, 1);
    for(auto c : vec){
        if(depth[ea[c]] > depth[eb[c]]) swap(ea[c], eb[c]);
        if(ea[c] == p && eb[c] == d) col[c] = 1;
    }
    for(int i=1; i<=m; i++) cout << col[i];
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}