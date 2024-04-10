#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
// #define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN], m;
int x, y, z, k;

bool used[maxN];
int par[maxN];
vector<int> vc[maxN];

int dia;
int pvt;

int find(int i){
    // cout << i << endl;
    if(par[i] <= 0) return i;
    else return par[i] = find(par[i]);
}
void unite(int i, int j){
    i = find(i); j = find(j);
    if(i == j) return;
    int mx = (-par[i] + 1) / 2 + (-par[j] + 1) / 2 + 1;
    par[j] = min({par[j], par[i], -mx});
    par[i] = j;
}

int dfs(int node){
    used[node] = 1;
    if(node != pvt) par[node] = pvt;
    int hei = 0;
    for(int child : vc[node]){
        if(used[child]) continue;
        int gg = dfs(child);
        dia = max(dia, gg + hei);
        hei = max(hei, gg);
    }
    return (hei + 1);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(used, 0, sizeof(used));
    int o; cin >> n >> m >> o;
    for1(i, 1, m){
        cin >> x >> y;
        vc[x].pb(y);
        vc[y].pb(x);
    }
    for1(i, 1, n){
        if(!used[i]){
            dia = 0;
            pvt = i;
            dfs(i);
            par[i] = -dia;
        }
    }
    while(o--){
        cin >> z >> x;
        if(z == 1) cout << -par[find(x)] << endl;
        else{
            cin >> y;
            unite(x, y);
        }
        // for1(i, 1, n){
        //     cout << par[i] << " ";
        // }
        // cout << endl;
    }
}