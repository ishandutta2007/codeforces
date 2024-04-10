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
int b[maxN];

int kmp[maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m; --n; --m;
    if(!m){
        cout << n + 1 << endl; exit(0);
    }
    cin >> x;
    for1(i, 1, n){
        cin >> y; a[i] = y - x; x = y;
    }
    cin >> x;
    for1(i, 1, m){
        cin >> y; b[i] = y - x; x = y;
    }
    kmp[0] = -1;
    int x = -1;
    for1(i, 1, m){
        while(x != -1 && b[x + 1] != b[i]) x = kmp[x];
        kmp[i] = ++x;
    }
    x = 0; int ans = 0;
    for1(i, 1, n){
        while(x != -1 && b[x + 1] != a[i]) x = kmp[x];
        ++x; if(x == m){
            ++ans; x = kmp[x];
        }
    }
    cout << ans << endl;
}