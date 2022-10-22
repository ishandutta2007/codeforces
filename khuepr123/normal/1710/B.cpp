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
#define vi vector<int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define ld long double
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k, m;

int pos[maxN], val[maxN];

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o; while(o--){
        cin >> n >> m;
        vector<ii> cl;
        for1(i, 1, n) cin >> pos[i] >> val[i];
        for1(i, 1, n){
            cl.pb(ii(pos[i] - val[i], 1ll));
            cl.pb(ii(pos[i]         , -2ll));
            cl.pb(ii(pos[i] + val[i], 1ll));
        }
        sort(all(cl));
        vector<ii> bin;
        x = 0;
        int prepos = 0;
        int preval = 0;
        for(ii pr : cl){
            x += preval * abs(pr.fi - prepos);
            prepos = pr.fi;
            preval += pr.se;
            // cout << pr.fi << " " << x << endl;
            if(x > m) bin.pb(ii(pr.fi, x - m));
        }
        // cout << endl;
        cl.clear();
        int v1 = -oo, v2 = -oo;
        for(ii cc : bin){
            v1 = max(v1, cc.se - cc.fi);
            v2 = max(v2, cc.fi + cc.se);
        }
        // cout << v1 << " " << v2 << endl;
        for1(i, 1, n){
            int cl1 = val[i] - pos[i];
            int cl2 = val[i] + pos[i];
            if(cl1 >= v1 && cl2 >= v2)
                cout << 1; else cout << 0;
                // cout << endl;
            // cout << cl1 << " " << cl2 << endl;
        }
        cout << endl;
    }
}