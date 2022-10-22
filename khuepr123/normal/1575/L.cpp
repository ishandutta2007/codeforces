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
    cin >> n;
    vector<ii> ele;
    for1(i, 1, n){
        cin >> x;
        if(x <= i){
            ele.pb(ii(i - x, x));
        }
    }
    sort(all(ele));
    vector<int> lis;
    lis.pb(-oo);
    int bonus = 0;
    for(ii ccc : ele){
        int cc = ccc.se;
        // cout << ccc.fi << " " << cc << endl;
        if(cc > lis.back()) lis.pb(cc);
        else{
            x = lower_bound(all(lis), cc) - lis.begin();
            lis[x] = min(lis[x], cc);
        }
    }
    cout << lis.size() - 1 << endl;
}