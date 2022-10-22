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


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        map<int, vector<int>> mp;
        for1(i, 1, n){
            cin >> x; mp[x].pb(i);
            a[i] = x;
        }
        while(!mp.empty()){
            vector<ii> bru;
            vector<int> sus;
            for(auto& cac : mp){
                x = (cac.se).back();
                (cac.se).pop_back();
                bru.pb(ii(cac.fi, x));
                sus.pb(cac.fi);
            }
            for(int c : sus){
                if(mp[c].empty()) mp.erase(c);
            }
            // num, pos;
            for(int i = 1; i < bru.size(); ++i){
                swap(bru[i].fi, bru[i - 1].fi);
            }
            for(ii pr : bru){
                a[pr.se] = pr.fi;
            }
        }
        for1(i, 1, n) cout << a[i] << " ";
        cout << endl;
    }
}