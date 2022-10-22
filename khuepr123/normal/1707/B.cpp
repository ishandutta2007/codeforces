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

int turn;

void exec(){
    if(turn > n){
        a[++n] = 0; sort(a + 1, a + n + 1);
    }
    for1(i, 1, n - 1) a[i] = a[i + 1] - a[i];
    sort(a + 1, a + n);
    --n;
    int cn = 0;
    // for1(i, 1, n) cout << a[i] << " ";
    // cout << endl;
    for1(i, 1, n - 1){
        if(a[i] == 0) ++cn;
        else break;
    }
    for1(i, cn + 1, n) a[i - cn] = a[i];
    n -= cn;
    // for1(i, 1, n) cout << a[i] << " ";
    // cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o; while(o--){
        cin >> n;
        for1(i, 1, n) cin >> a[i];
        a[0] = 0;
        turn = n;
        while(n > 1){
            exec();
            --turn;
        }
        cout << a[1] << endl;
    }
}