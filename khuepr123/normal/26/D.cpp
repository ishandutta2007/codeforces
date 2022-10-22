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
#define ld long double
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k, m;


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    vector<int> v1;
    vector<int> v2;
    if(n + k - m < 0){
        cout << "0\n"; return 0;
    }
    for2(i, m, m - k) v1.pb(i);
    for1(i, n + 1, n + k + 1) v2.pb(i);
    ld ans = 1;
    while(v1.size() && v2.size()){
        if(ans < (ld)1){
            ans *= (ld)v1.back(); v1.pop_back();
        }
        else{
            ans /= (ld)v2.back(); v2.pop_back();
        }
    }
    while(v1.size()){
        ans *= (ld)v1.back(); v1.pop_back();
    }
    while(v2.size()){
        ans /= (ld)v2.back(); v2.pop_back();
    }
    cout << (ld)1 - ans << endl;
}