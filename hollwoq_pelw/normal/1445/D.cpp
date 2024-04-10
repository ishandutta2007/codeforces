/*
 /+==================================================+\
//+--------------------------------------------------+\\
|.|\\...>>>>>>> Hollwo_Pelw(ass) 's code <<<<<<<...//|.|
\\+--------------------------------------------------+//
 \+==================================================+/
*/
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
// type
typedef long long ll;
typedef long double ld;
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
// I/O
#define open(file, in, out) if (fopen(file in, "r")) {        \
                                freopen(file in, "r", stdin);  \
                                freopen(file out, "w", stdout); \
                            }
#define FAST_IO             std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define setpre(n)           fixed << setprecision(n)
bool endline = false;
template<class T>
istream& operator >> (istream& inp, vector<T>& v){
    for (auto& it : v) inp >> it;
    return inp;
}
template<class T>
ostream& operator << (ostream& out, vector<T>& v){
    for (auto& it : v) out << it << (endline ? "\n" : " ");
    return out;
}
template<class T, class U>
istream& operator >> (istream& inp, pair<T, U>& v){
    inp >> v.F >> v.S;
    return inp;
}
template<class T, class U>
ostream& operator << (ostream& out, pair<T, U>& v){
    out << v.F << ' ' << v.S;
    return out;
}

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
const int MAXN = 3e5 + 6 , MAXM = 5e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
const int mod2 = 1e9 + 9;
#define int long long

int n, a[MAXN];
int fac[MAXN], inv[MAXN];
 
int C(int n, int k){
    if (k < 0 || k > n) return 0;
    return fac[n] * inv[n - k] % mod1 * inv[k] % mod1;
}

void Solve () {
    cin >> n;
    fac[0] = fac[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i <= 2 * n; i++){
        fac[i] = fac[i - 1] * i % mod1;
        inv[i] = (mod1 - (mod1 / i)) * inv[mod1 % i] % mod1;
    }
    for (int i = 2; i <= 2 * n; i++){
        inv[i] = inv[i - 1] * inv[i] % mod1;
    }
    for (int i = 1; i <= 2 * n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 2 * n + 1);
    int ans = 0;
    for (int i = 1; i <= 2 * n; i++){
        if (i <= n)
            (ans -= a[i]) %= mod1;
        else
            (ans += a[i]) %= mod1;
    }
    if (ans < 0) ans += mod1;
    cout << ans * C(2 * n, n) % mod1;
}

signed main(){
//  open("", ".inp", ".out");
    FAST_IO; int TC = 1;
//    cin >> TC;
    while(TC--) Solve();
    return 0;
}
/*

./-=====>>><<<-------- DEBUG -------->>><<<=====-\.
/.................................................\
+====================== INP ======================+
7
1 3 -4 3 1 -1 6
1 4 0  3 4  3 9


+====================== OUT ======================+




+======================*****======================+
\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.

*/