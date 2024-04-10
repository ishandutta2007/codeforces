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
int pre[maxN];
 
int spmax[25][maxN];
int spmin[25][maxN];
int lg2[maxN];
 
int rg_max(int l, int r){
    ++r;
    int ds = lg2[r - l];
    return max(spmax[ds][l], spmax[ds][r - (1 << ds)]);
}
 
int rg_min(int l, int r){
    ++r;
    int ds = lg2[r - l];
    return min(spmin[ds][l], spmin[ds][r - (1 << ds)]);
}
 
vector<ii> chist(){
    pre[0] = 0;
    for1(i, 1, n){
        pre[i] = pre[i - 1];
        if(i & 1){
            pre[i] += a[i];
            spmin[0][i] = pre[i];
            spmax[0][i] = -oo;
        }
        else{
            pre[i] -= a[i];
            spmin[0][i] = oo;
            spmax[0][i] = pre[i];
        }
    }
    for1(ds, 0, 25){
        for1(i, 1, n - (1 << (ds + 1)) + 1){
            spmin[ds + 1][i] = min(spmin[ds][i], spmin[ds][i + (1 << ds)]);
            spmax[ds + 1][i] = max(spmax[ds][i], spmax[ds][i + (1 << ds)]);
        }
    }
    map<int, int> mp;
    vector<ii> res;
    for2(i, n, 0){
        if((i % 2 == 0) && (mp.find(pre[i]) != mp.end())){
            int idx = mp[pre[i]];
            if(rg_max(i + 1, idx) <= pre[i] && rg_min(i + 1, idx) >= pre[i]){
                res.pb(ii(i, idx));
            }
        }
        mp[pre[i]] = i;
    }
    return res;
}
 
vector<int> vc[maxN];
int dp[maxN];
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    lg2[0] = -1;
    for1(i, 1, maxN - 1) lg2[i] = lg2[i / 2] + 1;
    while(o--){
        cin >> n;
        for1(i, 1, n){
            cin >> a[i];
            dp[i] = 1;
            vc[i].clear();
        }
        if(n == 1){
            bool cl = (a[1] == 0);
            cout << cl << endl;
            continue;
        }
        dp[0] = 1;
        vc[0].clear();
        vector<ii> v1 = chist();
        for1(i, 1, n - 1) a[i] = a[i + 1];
        --n;
        vector<ii> v2 = chist();
        ++n;
        for(ii pr : v1) vc[pr.fi    ].pb(pr.se    );
        for(ii pr : v2) vc[pr.fi + 1].pb(pr.se + 1);
        int ans = 0;
        for2(i, n, 0){
            for(int cc : vc[i]) dp[i] += dp[cc];
            ans += dp[i];
        }
        cout << ans - n - 1 << endl;
    }
}