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

map<int, vector<int>> mp;
set<int> freeman;
int p1[maxN];

void threw(int nm){
    freeman.insert(nm);
}

void dehuman(int node){
    // cout << node << endl;
    if(mp.find(node) == mp.end()) return;
    vector<int> sus = mp[node];
    mp.erase(node);
    for(int cc : sus){
        if(mp.find(cc) != mp.end()) continue;
        int mn = min(cc, node); cc = max(cc, node);
        while(1){
            mn = mp.lower_bound(mn)->fi;
            if(mn > cc) break;
            dehuman(mn);
        }
    }
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o; while(o--){
        freeman.clear(); mp.clear();
        cin >> n >> z;
        p1[0] = 0;
        for1(i, 0, n) mp[i] = {};
        for1(i, 1, n){
            cin >> x; p1[i] = p1[i - 1] + x;
        }
        y = 0; threw(0);
        for1(i, 1, n){
            cin >> x; y += x; if(y == p1[i]) threw(i);
        }
        mp[mod] = {};
        while(z--){
            cin >> x >> y; --x;
            mp[x].pb(y);
            mp[y].pb(x);
        }
        for(int cc : freeman){
            dehuman(cc);
        }
        if(mp.size() == 1) cout << "YES\n";
        else cout << "NO\n";
    }
}