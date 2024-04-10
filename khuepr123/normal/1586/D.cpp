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

void prt(int nm){
    cout << nm + 1 << " ";
}

int qr(int num){
    cout << "? ";
    if(num < 0){
        for1(i, 1, n - 1) prt(0);
        prt(-num);
    }
    else{
        for1(i, 1, n - 1) prt(num);
        prt(0);
    }
    cout << endl;
    cin >> num; return num;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for1(i, -n + 1, n - 1) if(i){
        int val = qr(i); if(val){
            a[val] = -i;
        }
    }
    int mn = oo;
    for1(i, 1, n) mn = min(mn, a[i]);
    for1(i, 1, n) a[i] = a[i] - mn + 1;
    cout << "! ";
    for1(i, 1, n) cout << a[i] << " ";
    cout << endl;
}