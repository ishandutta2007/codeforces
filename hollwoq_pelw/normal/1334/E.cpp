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
#define print(val, stt)     return cout << val << endl, stt;
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
const int MAXN = 1e6 + 6 , MAXM = 2e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define int long long

int D, C[101][101];
vector<int> primes;
int tmp[101];
void getp(int x){
    if (D % x == 0 && x != 1){
        primes.eb(x);
        while(D % x == 0)
            D /= x;
    }
}

int calc(int x){
    int tot = 0;
    for (int i = 0; i < primes.size(); i++){
        tmp[i] = 0;
        while(x % primes[i] == 0){
            x /= primes[i]; ++tmp[i];
        }
        tot += tmp[i];
    }
    int ans = 1;
    for (int i = 0; i < primes.size(); i++){
        ans = ans * C[tot][tmp[i]] % mod1;
        tot -= tmp[i];
    }
    return ans;
}

void Solve() {
    cin >> D; getp(2); getp(3);
    for (int i = 5; i * i <= D; i+=6){
        getp(i); getp(i+2);
    }
    getp(D);
    C[0][0] = 1;
    for (int i = 1; i <= 100; i++){
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++){
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod1;
        }
    }
    int q; cin >> q;
    while (q--){
        int u, v; cin >> u >> v; int g = __gcd(u, v);
        cout << calc(u/g) * calc(v/g) % mod1 << endl;
    }
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
    //cin >> TC;
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