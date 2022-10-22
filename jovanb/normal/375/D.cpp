#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
 
template <class T> using ordered_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
 
map <int, int> ima[100005];
ordered_set <pair <int, int>> q[100005];
int col[100005];
vector <int> graf[100005];
vector <pair <int, int>> queries[100005];
int sz[100005];
int res[100005];
int u[100005];
 
void dfs(int v, int parent){
    int tren = 0;
    for(auto c : graf[v]){
        if(c == parent) continue;
        dfs(c, v);
        if(sz[c] > sz[tren]) tren = c;
        sz[v] += sz[c];
    }
    sz[v]++;
    u[v] = u[tren];
    if(!u[v]) u[v] = v;
    int r = u[v];
    q[r].erase({ima[r][col[v]], col[v]});
    ima[r][col[v]]++;
    q[r].insert({ima[r][col[v]], col[v]});
    for(auto c : graf[v]){
        if(c == parent || c == tren) continue;
        for(auto x : ima[u[c]]){
            q[r].erase({ima[r][x.first], x.first});
            ima[r][x.first] += x.second;
            q[r].insert({ima[r][x.first], x.first});
        }
    }
    for(auto par : queries[v]){
        int ind = par.second;
        int k = par.first;
        res[ind] = q[r].size() - q[r].order_of_key({k, 0});
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
 
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> col[i];
    }
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        queries[a].push_back({b, i});
    }
    dfs(1, 0);
    for(int i=1; i<=m; i++){
        cout << res[i] << "\n";
    }
    return 0;
}