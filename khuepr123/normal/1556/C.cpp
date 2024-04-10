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


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n; n -= (n % 2);
    for1(i, 1, n) cin >> a[i];
    int ans = 0;
    for(int i = 1; i <= n; i += 2){
        int mnd = 0;
        int crv = 0;
        for1(j, i + 1, n){
            if(j % 2) crv += a[j];
            else{
                if(mnd <= a[i]){
                    a[i] -= mnd;
                    crv += mnd;
                    int vl = min({oo, a[j] - crv, a[i]});
                    if(abs(i - j) > 1) ++vl;
                    if(vl < 0) vl = 0;
                    ans += vl;
                    crv -= mnd;
                    a[i] += mnd;
                }
                crv -= a[j];
                mnd = max(mnd, -crv);
            }
        }
    }
    cout << ans << endl;
}