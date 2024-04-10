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
int n, a[maxN][6];
int x, y, z, k;


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n;
        x = 1;
        for1(i, 1, n){
            for1(j, 1, 5) cin >> a[i][j];
        }
        for1(i, 2, n){
            int wn = 0;
            for1(j, 1, 5){
                if(a[x][j] < a[i][j]) ++wn;
            }
            if(wn < 3) x = i;
        }
        bool win = 1;
        for1(i, 1, n){
            if(i == x) continue;
            int wn = 0;
            for1(j, 1, 5){
                if(a[x][j] < a[i][j]) ++wn;
            }
            if(wn < 3) win = 0;
        }
        if(win) cout << x << endl;
        else cout << "-1\n";
    }
}