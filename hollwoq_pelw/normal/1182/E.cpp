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

struct Mat{
    int a[3][3];
    int* operator [] (int x) {return a[x];}
    const int* operator [] (int x) const {return a[x];}
    friend Mat operator * (const Mat& a, const Mat& b){
        Mat r;
        for (int i = 0; i < 3; i ++){
            for (int j = 0; j < 3; j ++){
                r[i][j] = 0;
                for (int k = 0; k < 3; k ++){
                    r[i][j] = r[i][j] + a[i][k] * b[k][j];
                }
            }
        }
        return r;
    }
    friend Mat operator % (const Mat& a, const int x){
        Mat r;
        for (int i = 0; i < 3; i ++){
            for (int j = 0; j < 3; j ++){
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
    int n, f[3], c;
    cin >> n >> f[0] >> f[1] >> f[2] >> c;
    for (int i = 0; i < 3; i++)
        (f[i] *= binpow(c, i + 1, mod)) %= mod;
    base[0][0] = base[0][1] = base[0][2] = base[1][0] = base[2][1] = 1;
    base = binpow(base, n - 3, mod - 1);
    int ans = binpow(binpow(c, mod - 2, mod), n, mod) % mod;
    for (int i = 0; i < 3; i++){
        (ans *= binpow(f[i], base[0][2 - i], mod)) %= mod;
    }
    cout << ans % mod;

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