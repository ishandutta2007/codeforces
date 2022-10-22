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
int n, a[maxN], b[maxN];
int x, y, z, k;

bool solve(int rang){
    int accu = 0;
    for1(i, 1, n){
        int vl = min(a[i], accu) + 1;
        if(b[i] + vl >= rang) accu = max(accu, vl);
        if(accu == rang) break;
    }
    return accu >= rang;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        for1(i, 1, n) cin >> b[i] >> a[i];
        int l = 1, r = n;
        while(l != r){
            int mid = (l + r) / 2;
            mid = (l + r) - mid;
            if(solve(mid)) l = mid;
            else r = mid - 1;
        }
        cout << l << endl;
    }
}