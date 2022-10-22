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
const int MAXN = 1e6 + 6 , MAXM = 2e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define int long long
/*
1 2 3
4 8 12
5 10 15
6
*/

pii uwu(int idx, int bt){
    if (bt == 0) return {1, 2};
    int pr1 = 1ll << (bt - 1);
    int pr2 = 1ll << (bt - 2);
    pii q = uwu(idx % pr2, bt - 2);
    int tmp = idx / pr2;
    if (tmp == 0){
        q.F ^= pr2, q.S ^= pr1;
    }else if (tmp == 1){
        // pass
    }else if (tmp == 2){
        q.F ^= (pr1 ^ pr2);
        q.S ^= pr2;
    }else if (tmp == 3){
        q.F ^= pr1;
        q.S ^= (pr1 ^ pr2);
    }
    q.F ^= (1ll << bt);
    q.S ^= (1ll << (bt + 1));
    return q;
}

void Solve() {
    int n; cin >> n; n --;
    int idx = n / 3, p = n % 3;
    for (int bt = 0; ; bt += 2){
        int cur = 1ll << bt;
        if (cur > idx){
            pii ans = uwu(idx, bt); int a[3];
            a[0] = ans.F, a[1] = ans.S, a[2] = ans.F ^ ans.S;
            cout << a[p] << endl; return;
        }
        idx -= cur;
    }
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
    cin >> TC;
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