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
int x, y, z, k, m;

int ans = 0;

priority_queue<int, vector<int>, greater<int>> pq;

int scan(){
    int res = 0;
    for1(i, 1, n){
        pq.push(a[i]);
        if(i & 1){
            res += pq.top();
            // cout << pq.top() << endl;
            pq.pop();
        }
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for1(i, 1, n) cin >> a[i];
    for1(i, 1, n){
        cin >> x; ans += x;
        a[i] -= x;
    }
    ans *= m;
    // cout << ans << endl;
    if(n & 1){
        for1(i, 1, n) a[i + n] = a[i];
        n *= 2; m /= 2;
    }
    // cout << scan() << endl << scan() << endl;
    // exit(0);
    ans += scan();
    ans += scan() * (m - 1);
    cout << ans << endl;
}