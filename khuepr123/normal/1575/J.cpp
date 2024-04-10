/*#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")*/
// only when really needed

/* GNU G++17 7.3.0: No long long for faster code
   GNU G++17 9.2.0 (64 bit, msys 2): Long long only for faster code */
 
#include <bits/stdc++.h>
  
#define for1(i,a,b) for (int i = a; i <= b; i++)
#define for2(i,a,b) for (int i = a; i >= b; i--)
#define int long long

#define sz(a) (int)a.size()
#define pii pair<int,int>
#define pb push_back
 
/*
__builtin_popcountll(x) : Number of 1-bit
__builtin_ctzll(x) : Number of trailing 0
*/
 
#define PI 3.1415926535897932384626433832795
#define INF 1000000000000000000
#define MOD 998244353
#define MOD2 1000000009
#define EPS 1e-6

using namespace std;

int n, m, k;
int a[1005][1005];

signed main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // freopen("cf.inp", "r", stdin);
    // freopen("cf.out", "w", stdout);

    cin >> n >> m >> k;

    for1(i,1,n) {
        for1(j,1,m) cin >> a[i][j];
    }

    while (k--) {
        int x = 1, y;
        cin >> y;
        while (x <= n) {
            if (a[x][y] == 1) {
                a[x][y] = 2;
                y++;
            }
            else if (a[x][y] == 3) {
                a[x][y] = 2;
                y--;
            }
            else x++;
        }
        cout << y << " ";
    }
    
}