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

map<ii, int> mp1;
map<ii, int> mp2;
map<int, int> mn;
map<int, int> mx;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        mp1.clear();
        mp2.clear();
        mn.clear();
        mx.clear();
        cin >> n;
        for1(i, 1, n){
            cin >> x >> y >> z;
            if(mn[x]) mn[x] = min(mn[x], z);
            else mn[x] = z;
            if(mx[y]) mx[y] = min(mx[y], z);
            else mx[y] = z;
            if(mp1[ii(x, y)]) z = min(z, mp1[ii(x, y)]);
            mp1[ii(x, y)] = z;
            swap(x, y);
            if(mp2[ii(x, y)]) z = min(z, mp2[ii(x, y)]);
            mp2[ii(x, y)] = z;
            auto cl1 = *mp1.begin();
            auto cl2 = *mp2.rbegin();
            int le = cl1.fi.fi;
            int ri = cl2.fi.fi;
            int ans = cl1.se + cl2.se;
            if(mp1.find(ii(le, ri)) != mp1.end()){
                ans = min(ans, mp1[ii(le, ri)]);
            }
            swap(x, y);
            ans = min(ans, mn[le] + mx[ri]);
            cout << ans << endl;
        }
    }
}