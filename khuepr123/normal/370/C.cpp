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
int n; ii a[maxN];
int x, y, z, k;

int b[maxN];
int ans[maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> x;
    for1(i, 1, n){
        cin >> a[i].fi;
        a[i].se = i;
        b[i] = a[i].fi;
    }
    sort(a + 1, a + n + 1);
    int df = n / 2;
    for1(i, 1, n){
        int j = i - df;
        j = (j % n + n) % n;
        if(j == 0) j = n;
        ans[a[i].se] = a[j].fi;
    }
    int cnt = 0;
    for1(i, 1, n){
        if(ans[i] != b[i]) ++cnt;
    }
    cout << cnt << endl;
    for1(i, 1, n){
        cout << b[i] << " " << ans[i] << endl;
    }

}