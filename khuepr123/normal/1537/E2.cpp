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
 
/*
__builtin_popcountll(x) : Number of 1-bit
__builtin_ctzll(x) : Number of trailing 0
*/
 
#define PI 3.1415926535897932384626433832795
#define INF 1000000000000000000
#define MOD 1000000007
#define MOD2 1000000009
#define EPS 1e-6

using namespace std;

int n, k, z[500005];
string s;

signed main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // freopen("cf.inp", "r", stdin);
    // freopen("cf.out", "w", stdout);

    cin >> n >> k >> s;
    s += "~";
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    int pos = n;
    for1(i,0,n - 1) {
        if (s[z[i]] < s[i + z[i]]) {
            pos = i;
            break;
        }
    }
    for1(i,0,k - 1) cout << s[i % pos];
}