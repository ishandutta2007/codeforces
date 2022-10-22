/*
 /+==================================================+\
//+--------------------------------------------------+\\
|.|\\...>>>>>>> Hollwo_Pelw(ass) 's code <<<<<<<...//|.|
\\+--------------------------------------------------+//
 \+==================================================+/
*/
#include <bits/stdc++.h>
using namespace std;
// type
typedef long long ll;
typedef long double ld;
// loop
//#define For(i, l, r)        for (int i = l; i < r; i++)
//#define ForE(i, l, r)       for (int i = l; i <= r; i++)
//#define Ford(i, r, l)       for (int i = r; i > l; i--)
//#define FordE(i, r, l)      for (int i = r; i >= l; i--)
//#define Fora(i, a)          for (auto i : a)
// I/O
#define open(file, in, out) if (fopen(file in, "r")) {        \
                                freopen(file in, "r", stdin);  \
                                freopen(file out, "w", stdout); \
                            }
#define FAST_IO             std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define setpre(n)           fixed << setprecision(n)
// pair
#define F                   first
#define S                   second
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pdd                 pair<ld, ld>
// vector & !!?(string)
#define eb                  emplace_back
#define pb                  push_back
#define all(a)              a.begin(), a.end()
#define rall(a)             a.rbegin(), a.rend()
#define sz(a)               a.size()
#define len(a)              a.length()
// geometry calculate
#define pi                  acos(-1.0)
#define g_sin(a)            sin(a*pi/180)
#define g_cos(a)            cos(a*pi/180)
#define g_tan(a)            tan(a*pi/180)
// set val
#define ms0(a)              memset(a,        0, sizeof(a));
#define ms1(a)              memset(a,        1, sizeof(a));
#define msn1(a)             memset(a,       -1, sizeof(a));
#define msinf(a)            memset(a, 0x3f3f3f, sizeof(a));
// constant
const int mod1 = 998244353, mod = 1e9 + 7;
const int MAXN = 1e5 + 6 , MAXM = 2e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define int long long

const int S = 2;

struct Mat{
    int a[S][S];
    int* operator [] (int x) {return a[x];}
    const int* operator [] (int x) const {return a[x];}
    friend Mat operator * (const Mat& a, const Mat& b){
        Mat r;
        for (int i = 0; i < S; i ++){
            for (int j = 0; j < S; j ++){
                r[i][j] = 0;
                for (int k = 0; k < S; k ++){
                    r[i][j] = r[i][j] + a[i][k] * b[k][j];
                }
            }
        }
        return r;
    }
    friend Mat operator % (const Mat& a, const int x){
        Mat r;
        for (int i = 0; i < S; i ++){
            for (int j = 0; j < S; j ++){
                r[i][j] = a[i][j] % x;
            }
        }
        return r;
    }
} base;

template<typename T>
T binpow(T a, int x, int md){
    if (x == 1) return a % md;
    T t = binpow(a, x / 2, md);
    if (x & 1) return t * t % md * a % md;
    else return t * t % md;
}

void Solve() {
    int n, k, l, md; 
    cin >> n >> k >> l >> md;
    base[0][0] = base[0][1] = base[1][0] = 1;
    base = binpow(base, n + 1, md);
    int c[2];
    c[0] = base[0][0];
    c[1] = (binpow(2ll, n, md) + md - c[0]) % md;
    // cout << c[0] << ' ' << c[1] << endl;
    int ans = 1 % md;
    for (int i = 0; i < l; i++){
        int x = (k >> i) & 1;
        ans = ans * c[x] % md;
        k ^= (x << i);
    }
    if (k) cout << 0;
    else cout << ans;
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
//    cin >> TC;
    while(TC--) Solve();
    return 0;
}
/*

./-=====>>><<<-------- DEBUG -------->>><<<=====-\.
/.................................................\


+====================== INP ======================+


+====================== OUT ======================+


\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.

*/