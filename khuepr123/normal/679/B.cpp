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

int cop[maxN];
int best[maxN];

ii track(int num){
    if(num < maxN) return ii(cop[best[num]], best[num]);
    int val = cbrt(num);
    ii p1 = track(num - val * val * val);
    p1.fi++; p1.se += val * val * val;
    num = val * val * val - 1;
    --val;
    ii p2 = track(num - val * val * val);
    p2.fi++; p2.se += val * val * val;
    return max(p1, p2);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cop[0] = 0;
    for1(i, 1, maxN - 1){
        x = cbrt(i);
        cop[i] = cop[i - x * x * x] + 1;
    }
    best[0] = 0;
    for1(i, 1, maxN - 1){
        best[i] = best[i - 1];
        if(cop[i] >= cop[best[i]]) best[i] = i;
    }
    cin >> x; ii pr = track(x);
    cout << pr.fi << " " << pr.se << endl;
}