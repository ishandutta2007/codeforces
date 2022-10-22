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

int ans = 0;
void solve(vector<int> fl, int acc, int plc){
    if(fl.size() < 3){
        ans = max(ans, (int)fl.size() + acc);
        return;
    }
    vector<int> vc[2];
    for(int cc : fl){
        bool fall = cc & (1 << plc);
        vc[fall].pb(cc);
    }
    solve(vc[0], min((int)vc[1].size(), 1ll) + acc, plc - 1);
    solve(vc[1], min((int)vc[0].size(), 1ll) + acc, plc - 1);

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> fku;
    cin >> k; n = k; while(k--){
        cin >> x; fku.pb(x);
    }
    solve(fku, 0, 30);
    cout << n - ans << endl;
}