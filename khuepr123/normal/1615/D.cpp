/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define all(flg) flg.begin(), flg.end()
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define eb emplace_back
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

vector<int> vc[maxN];
map<ii, int> inival;
vector<ii> slop[maxN];
int tag[maxN];
int m;
bool killed;

ii ed[maxN];

void dfs_tag(int node, int tg){
    tag[node] = tg;
    for(ii cc : slop[node]){
        int supp = tg;
        if(cc.fi) supp = 3 - tg;
        if(tag[cc.se] == -1){
            dfs_tag(cc.se, supp);
        }
        else{
            if(tag[cc.se] != supp) killed = 1;
        }
    }
}

void dfs_ans(int node, int par){
    for(int cc : vc[node]) if(cc != par){
        cout << node << " " << cc << " ";
        ii pr = ii(node, cc);
        if(inival.find(pr) != inival.end())
            cout << inival[pr] << endl;
        else cout << (tag[node] != tag[cc]) << endl;
        dfs_ans(cc, node);
    }
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o; while(o--){
        killed = 0;
        cin >> n >> m;
        inival.clear();
        for1(i, 1, n){
            tag[i] = -1;
            slop[i].clear();
            vc[i].clear();
        }
        for1(i, 1, n - 1){
            cin >> x >> y >> z;
            vc[x].pb(y);
            vc[y].pb(x);
            if(z != -1){
                inival[ii(x, y)] = z;
                inival[ii(y, x)] = z;
                z = __builtin_popcount(z);
                z = z & 1;
                slop[x].pb(ii(z, y));
                slop[y].pb(ii(z, x));
            }
        }
        for1(i, 1, m){
            cin >> x >> y >> z;
            slop[x].pb(ii(z, y));
            slop[y].pb(ii(z, x));
        }
        for1(i, 1, n) if(tag[i] == -1){
            dfs_tag(i, 0);
        }
        if(killed){
            cout << "NO\n"; continue;
        }
        cout << "YES\n";
        dfs_ans(1, 1);
    }
}