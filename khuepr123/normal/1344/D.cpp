/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option
 
#include<bits/stdc++.h>
using namespace std;
 
#define all(flg) flg.begin(), flg.end()
#define ctz __builtin_ctzll
#define clz __builtin_clzll
#define popcnt __builtin_popcountll
#define int long long
#define pb push_back
#define fi first
#define se second
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
 
int b[maxN];
int buoi[maxN];
 
int calc(int id, int val){
    y = val + 1;
    x = y * (a[id] - y * y);
    x -= val * (a[id] - val * val);
    return x;
}
 
int solve(int turn){
    int accu = 0;
    for1(i, 1, n){
        int ri = a[i], le = 0;
        // find largest point that ascend mean death
        while(ri != le){
            int mid = (le + ri) / 2;
            if(turn > calc(i, mid)) ri = mid;
            else le = mid + 1;
        }
        b[i] = le;
        accu += le;
    }
    return accu;
}
 
signed main(){
// freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for1(i, 1, n) cin >> a[i];
 
 
 
    int ri = 4.3e18;
    int le = -4.3e18;
    // cout << le << " " << ri << endl;
    while(ri != le){
        int mid = le + (ri - le + 1) / 2;
        if(solve(mid) >= k) le = mid;
        else ri = mid - 1;
        // cout << le << " " << ri << endl;
    }
    solve(le);
    for1(i, 1, n){
        buoi[i] = b[i];
        k -= buoi[i];
    }
    solve(le + 1);
    for1(i, 1, n){
        x = buoi[i] - b[i];
        if(x && k){
            ++k;
            cout << buoi[i] - x << " ";
        }
        else cout << buoi[i] << " ";
    }
}