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
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n; bool a[25][25];
int x, y, z, k;
int m;

void dw(int cl){
    for1(i, 3, n - 2){
        if(i % 2) a[i][cl] = 1;
    }
}

void up(int rw){
    for1(i, 3, m - 2){
        if(i % 2) a[rw][i] = 1;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n >> m;
        memset(a, 0, sizeof(a));
        dw(1); dw(m);
        up(1); up(n);
        a[1][1] = 1;
        a[n][1] = 1;
        a[1][m] = 1;
        a[n][m] = 1;
        for1(i, 1, n){
            for1(j, 1, m) cout << a[i][j];
            cout << endl;
        }
        cout << endl;
    }
}