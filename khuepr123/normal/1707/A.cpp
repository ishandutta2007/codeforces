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
int n, a[maxN];
int x, y, z, k;


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o; while(o--){
    cin >> n >> k;
    for1(i, 1, n) cin >> a[i];
    int l = 1, r = n + 1;
    while(l != r){
        int mid = (l + r) / 2;
        int val = k;
        for1(i, mid, n){
            if(val < a[i]) --val;
        }
        if(val >= 0) r = mid;
        else l = mid + 1;
    }
    int sum = 0;
    for1(i, 1, l - 1) cout << (k >= a[i]);
    for1(i, l, n) cout << 1;
    cout << endl;
    // cout << sum << endl;
    }
}