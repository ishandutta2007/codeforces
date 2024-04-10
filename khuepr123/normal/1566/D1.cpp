/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

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

ii pr[maxN];
bool occ[maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n >> n;
        for1(i, 1, n){
            cin >> pr[i].fi; pr[i].se = i;
            pr[i].fi = -pr[i].fi;
            occ[i] = 0;
        }
        sort(pr + 1, pr + n + 1, greater<ii>());
        for1(i, 1, n) a[i] = pr[i].se;
        int ans = 0;
        for1(i, 1, n){
            bool isd = 0;
            for2(j, n, 1){
                if(isd && occ[j]) ++ans;
                if(a[j] == i){
                    isd = 1;
                    occ[j] = 1;
                }
            }
        }
        cout << ans << endl;
    }
}