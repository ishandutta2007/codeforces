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
#define debug(x)            cout << #x << " : " << endl << x << endl;
#define Ptest(x)            return cout << x << endl, (void) 0;
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
const int MAXN = 1e6 + 5 , MAXM = 3e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define left node << 1, tl, tm
#define right node << 1 | 1, tm + 1, tr
#define int long long

int k, l, r;
int t;
int x, y;

bool surv[MAXN];
int nxt[MAXN];
int s[MAXN];

void Solve(){
    cin >> k >> l >> r >> t >> x >> y;
    r -= l; k -= l; l = 0;
    if (x >= y){
        if (k + y <= r) k += y;
        int ls = x - y;
        int range = k - x + 1;
        int d = 0;
        if (range > 0){
            if (ls) {
                d = (range - 1) / ls + 1;
            }else {
                Ptest("Yes");
            }
        }
        // cout << d << endl;
        if (d < t) {
            Ptest("No");
        }else {
            Ptest("Yes");
        }
    }else{
        int low = r - y;
        for (int i = 0; i <= min(low, x - 1); i++){
            surv[i % x] = 1;
        }
        for (int i = 0; i < x; i++){
            nxt[i] = (i + y) % x;
            s[i] = (i + y - nxt[i]) / x;
            // cout << "debug : " << i << endl;
            // cout << nxt[i] << ' ' << s[i] << ' ' << surv[i] << endl;
        }
        int cur = k % x, d = k / x;
        set<int> vis;
        while(true){
            if (!surv[cur]) break;
            if (vis.count(cur)){
                Ptest("Yes");
            }
            vis.insert(cur);
            d += s[cur];
            cur = nxt[cur];
        }
        if (d >= t)
            cout << "Yes";
        else
            cout << "No";   
    }
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
    // cin >> TC;
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