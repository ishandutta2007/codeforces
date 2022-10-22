/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define endl "\n"
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

int p1[2][maxN];
int p2[2][maxN];

inline void up(int &v1, int &v2){
    v1 = max(v1, v2);
}
inline void dw(int &v1, int &v2){
    v1 = min(v1, v2);
}

void unite(int id){
    up(p1[0][0], p1[0][id]);
    dw(p2[0][0], p2[0][id]);
    up(p1[1][0], p1[1][id]);
    dw(p2[1][0], p2[1][id]);
}

void intex(int id){
    int v1, v2, v3, v4;
    v1 = max(p1[0][0], p1[0][id]);
    v2 = min(p2[0][0], p2[0][id]);
    v3 = max(p1[1][0], p1[1][id]);
    v4 = min(p2[1][0], p2[1][id]);
    if(v1 > v2 || v3 > v4) return;
    unite(id);
    cout << p1[0][0] << " " << p1[1][0] << endl;
    exit(0);
}

void solving(int i1, int i2){
    for1(i, 1, n){
        if(i != i1 && i != i2) unite(i);
    }
    intex(i1);
    intex(i2);
}

void solve(int id){
    map<int, int> mp;
    mp[mod] = 0;
    for1(i, 1, n){
        mp[p1[id][i]] = i;
    }
    for1(i, 1, n){
        auto itr = mp.upper_bound(p2[id][i]);
        if(itr->se) solving(i, itr->se);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for1(i, 1, n){
        for1(j, 0, 1) cin >> p1[j][i];
        for1(j, 0, 1) cin >> p2[j][i];
    }
    p1[0][0] = -mod; p1[1][0] = -mod;
    p2[0][0] =  mod; p2[1][0] =  mod;
    solve(0);
    solve(1);
    solving(1, 2);
}