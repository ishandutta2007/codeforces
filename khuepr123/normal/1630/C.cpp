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
int n;
int x, y, z, k;

int mx[maxN];
int mn[maxN];
map<int, int> mp;
int ans = 0;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for1(i, 1, n){
        mx[i] = 0;
        mn[i] = oo;
        // cout << mn[i] << " " << mx[i] << endl;
    }
    for1(i, 1, n){
        cin >> x;
        mx[x] = max(mx[x], i);
        mn[x] = min(mn[x], i);
    }
    for1(i, 1, n){
        if(mn[i] < mx[i]) mp[mn[i]] = mx[i];
        // cout << mn[i] << " " << mx[i] << endl;
    }
    // for(ii cc : mp) cout << cc.fi << " " << cc.se << endl;
    mp[oo] = oo;
    while(mp.size() > 1){
        auto itr = mp.begin();
        x = itr->fi; y = itr->se;
        mp.erase(mp.begin());
        // cout << x << " " << y << endl;
        while(mp.begin()->fi < y){
            int vlg = 0;
            while(mp.begin()->fi < y){
                vlg = max(vlg, mp.begin()->se);
                mp.erase(mp.begin());
            }
            if(vlg <= y) break;
            --ans; y = vlg;
            // cout << x << " " << y << endl;
        }
        ans += (y - x - 1);
    }
    cout << ans << endl;
}