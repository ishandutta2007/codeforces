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

int S;

struct Mat{
    int a[101][101];
    Mat () { }
    Mat (int x) { 
        for (int i = 0; i < S; i++){
            for (int j = 0; j < S; j++){
                a[i][j] = i == j;
            }
        }
    }
    int* operator [] (int x) {return a[x];}
    const int* operator [] (int x) const {return a[x];}
    friend Mat operator * (const Mat& a, const Mat& b){
        Mat r;
        for (int i = 0; i < S; i ++){
            for (int j = 0; j < S; j ++){
                r[i][j] = 0;
                for (int k = 0; k < S; k ++){
                    r[i][j] = r[i][j] + a[i][k] * b[k][j] % (mod1 - 1);
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
T binpow(T a, int x, int md = mod1 - 1){
    if (x == 0) return T(1);
    if (x == 1) return a % md;
    T t = binpow(a, x / 2, md);
    if (x & 1) return t * t % md * a % md;
    else return t * t % md;
}

void calc(int a, int k, int n){
    // x ^ k == a (mod n)
    int g = 3;
    if (a == 0){
        cout << -1;
        return;
    }
    n = mod1;
    // cout << a << ' ' << k << ' ' << n << endl;
    int sq = (int) sqrt (n + .0) + 1;
    vector<pair<int, int>> dec(sq);
    for (int i = 1; i <= sq; ++i)
        dec[i-1] = {binpow(g, i * sq * k % (n - 1), n), i};
    sort(all(dec));
    int any_ans = -1;
    for (int i = 0; i < sq; ++i) {
        int my = binpow(g, i * k % (n - 1), n) * a % n;
        auto it = lower_bound(all(dec), make_pair(my, 0ll));
        if (it != dec.end() && it->F == my) {
            any_ans = it->S * sq - i;
            break;
        }
    }
    // cout << any_ans << endl;
    if (any_ans == -1){
        cout << any_ans;
        return ;
    }
    int delta = (n - 1) / __gcd(k, n - 1);
    int cur = any_ans % delta;
    cout << binpow(g, cur, n);
    // for (; cur < n-1; cur += delta)
    //     ans.push_back(binpow(g, cur, n));
    // sort(ans.begin(), ans.end());
    // printf("%d\n", ans.size());
    // for (int answer : ans)
    //     printf("%d ", answer);
    // cout << ans[0];
}

void Solve() {
    cin >> S;
    for (int i = 0; i < S; i++){
        cin >> base[i][0];
    }
    for (int i = 0; i < S; i++){
        base[i][i + 1] = 1;
    }
    int n, a;
    cin >> n >> a;
    // cout << base[0][0] << ' ' << n - S << endl;
    base = binpow(base, n - S);
    int k = base[0][0];
    // cout << k << endl;
    // x ^ k == m [998244353];
    calc(a, k, mod1);
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