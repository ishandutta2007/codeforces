#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

map<int, vector<ii>> dumb;

int par[maxN];
int find(int i){
    if(i == par[i]) return i;
    else return par[i] = find(par[i]);
}

bool unite(int i, int j){
    i = find(i); j = find(j); if(i == j) return 0;
    par[i] = j; return 1;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> n >> o;
    for1(i, 0, n) par[i] = i;
    while(o--){
        cin >> x >> y >> z;
        dumb[z].pb(ii(x, y));
    }
    int ans = 0;
    for(auto childofdumb : dumb){
        vector<ii> ed = childofdumb.se;
        for1(i, 0, ed.size() - 1){
            if(find(ed[i].fi) == find(ed[i].se)) ed[i].fi = 0;
        }
        for(ii child : ed){
            if(child.fi == 0) continue;
            if(!unite(child.fi, child.se)) ++ans;
        }
    }
    cout << ans << endl;
}