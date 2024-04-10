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
int n, a[maxN], m;
int b[maxN];
int x, y, z, k;

bool solve(){
    int ans = 0;
    bool saved = 0;
    for1(i, 1, k){
        int vl = a[i] / n * n;
        if(vl > n){
            ans += vl;
            if(vl > n * 2) saved = 1;
        }
    }
    if((ans >= n * m) && (saved || (m % 2 == 0))) return 1;
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n >> m >> k;
        for1(i, 1, k) cin >> a[i];
        bool b1 = solve();
        swap(n, m);
        if(solve()) b1 = 1;
        if(b1) cout << "Yes\n";
        else cout << "No\n";
    }
}