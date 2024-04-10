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

int ans = 0;

int pre[25][maxN];
int suf[25][maxN];
int lg2[maxN];

int funcpre(int l, int r){
    int pin = pre[0][l - 1];
    ++r;
    int ds = lg2[r - l];
    return max(pre[ds][l], pre[ds][r - (1 << ds)]) - pin;
}

int funcsuf(int l, int r){
    int pin = suf[0][r + 1];
    ++r;
    int ds = lg2[r - l];
    return max(suf[ds][l], suf[ds][r - (1 << ds)]) - pin;
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> z;
    pre[0][0] = 0; suf[0][n + 1] = 0;
    lg2[0] = -1;
    priority_queue<ii> pq;
    for1(i, 1, n){
        lg2[i] = lg2[i / 2] + 1;
        cin >> a[i] >> y; y = z - y; x = abs(a[i] - a[i - 1]);
        ans = max(ans, y);
        pre[0][i] = pre[0][i - 1] + y;
        if(i > 1) pq.push(ii(x, i));
    }
    for1(i, 1, n) suf[0][i] = pre[0][n] - pre[0][i - 1];
    for1(i, 1, n){
        // cout << pre[0][i] << " " << suf[0][i] << endl;
    }
    for1(ds, 0, 20){
        for1(i, 1, n - (1 << (ds + 1)) + 1){
            pre[ds + 1][i] = max(pre[ds][i], pre[ds][i + (1 << ds)]);
            suf[ds + 1][i] = max(suf[ds][i], suf[ds][i + (1 << ds)]);
        }
    }
    set<int> wall;
    wall.insert(1);
    wall.insert(n);
    while(!pq.empty()){
        ii p1 = pq.top(); pq.pop();
        int pn = p1.se;
        int l = *--wall.upper_bound(pn - 1);
        int r = *wall.lower_bound(pn);
        y = funcpre(pn, r) + funcsuf(l, pn - 1) - p1.fi * p1.fi;
        ans = max(ans, y);
        wall.insert(pn);
        wall.insert(pn - 1);
    }
    cout << ans << endl;
}