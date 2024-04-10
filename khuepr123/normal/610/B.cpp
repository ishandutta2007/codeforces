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

inline int pre(int val){
    --val; if(val == 0) val = n;
    return val;
}

inline int suf(int val){
    ++val; if(val > n) val = 1;
    return val;
}



signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int mn = oo;
    for1(i, 1, n){
        cin >> a[i];
        mn = min(mn, a[i]);
    }
    for1(i, 1, n){
        a[i] -= mn;
    }
    int ans = 0;
    for1(i, 1, n){
        if(a[i] && (a[pre(i)] == 0)){
            int id = i;
            int tot = 0;
            while(a[id] > 0){
                ++tot;
                id = suf(id);
            }
            ans = max(ans, tot);
        }
    }
    cout << mn * n + ans << endl;
}