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

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<ii> vc;
    for1(i, 1, n){
        cin >> x;
        pr[i].fi = x;
        pr[i].se = i;
    }
    sort(pr + 1, pr + n + 1);
    for1(i, 1, n) a[i] = pr[i].se;
    while(n > 1){
        for1(i, 1, n) if(a[i] == n) x = i;
        while(x != n){
            vc.pb(ii(a[x + 1], a[x]));
            swap(a[x + 1], a[x]);
            ++x;
        }
        --n;
    }
    cout << vc.size() << endl;
    for(ii cc : vc) cout << cc.fi << " " << cc.se << endl;
}