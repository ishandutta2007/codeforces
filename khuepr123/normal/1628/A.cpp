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

vector<int> vc[maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        vector<int> ans;
        for1(i, 0, n) vc[i].clear();
        for1(i, 1, n){
            cin >> a[i];
            vc[a[i]].pb(i);
        }
        int pot = 1;
        while(pot <= n){
            int mxe = pot;
            for1(i, 0, n){
                int id = lower_bound(all(vc[i]), pot) - vc[i].begin();
                if(id == vc[i].size()){
                    ans.pb(i); break;
                }
                mxe = max(mxe, vc[i][id]);
            }
            pot = mxe + 1;
        }
        cout << ans.size() << endl;
        for(int cc : ans) cout << cc << " ";
        cout << endl;
    }
}