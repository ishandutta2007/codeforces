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

vector<int> vc;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n; vc.clear();
        for1(i, 0, n - 1){
            cin >> x; vc.pb(x);
        }
        sort(all(vc));
        vc.pb(oo);
        int ans = 0;
        for1(i, 0, n - 1){
            int idx = upper_bound(all(vc), vc[i]) - vc.begin();
            assert(vc[idx] > vc[i]);
            int res = idx - i;
            while(idx != n){
                int sax = lower_bound(all(vc), vc[idx] * 2 - vc[i]) - vc.begin();
                ++res;
                idx = sax;
            }
            ans = max(ans, res);
        }
        cout << n - ans << endl;
    }
}