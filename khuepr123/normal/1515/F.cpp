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
// #define endl "\n"
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
int m, need;

set<ii> st[maxN];
int par[maxN];
priority_queue<ii> pq;

int find(int i){
    if(i == par[i]) return i;
    return par[i] = find(par[i]);
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> need;
    x = 0;
    for1(i, 1, n){
        cin >> a[i];
        x += a[i];
        pq.push(ii(a[i], i));
    }
    if(x < (n - 1) * need){
        cout << "NO\n"; exit(0);
    }
    for1(i, 1, m){
        cin >> x >> y;
        z = x * mod + y;
        st[x].insert(ii(z, i));
        st[y].insert(ii(z, i));
    }
    for1(i, 1, n) par[i] = i;
    // value = a[i]; god = par[i];
    cout << "YES\n";
    while(!pq.empty()){
        ii pr = pq.top();
        int node = pr.se;
        if(par[node] != node || a[node] != pr.fi){
            pq.pop(); continue;
        }
        if(st[node].empty()) break;
        ii cac = *st[node].begin(); st[node].erase(st[node].begin());
        x = cac.fi; y = x % mod; x = x / mod;
        // cout << x << " " << y << " " << cac.se << endl;
        if(find(y) != find(x)){
            x = find(x); y = find(y);
            cout << cac.se << endl;
            if(st[x].size() < st[y].size()) swap(st[x], st[y]);
            for(ii cc : st[y]) st[x].insert(cc);
            par[y] = x; a[x] = a[x] + a[y] - need;
            pq.push(ii(a[x], x));
        }
    }
}