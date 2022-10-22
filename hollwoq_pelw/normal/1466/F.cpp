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
const int MAXN = 5e5 + 5 , MAXM = 3e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define left node << 1, tl, tm
#define right node << 1 | 1, tm + 1, tr
#define int long long

int m, n, P1[MAXN], T = 1, odd[MAXN], sz[MAXN];

int binpow(int a, int x){
    int r = 1;
    while(x){
        if (x & 1) r = r * a % mod;
        a = a * a % mod; x >>= 1;
    }
    return r;
}

int find(int u){
    return P1[u] = (P1[u] == u) ? u : find(P1[u]);
}

bool join(int u, int v){
    int x = find(u), y = find(v);
    if (x == y || (odd[x] && odd[y])) return 0;
    sz[x] += sz[y];
    odd[x] |= odd[y];
    P1[y] = x;
    return 1;
}

void Solve(){
    cin >> m >> n;
    for (int i = 1; i <= n; i++){
        P1[i] = i;
        sz[i] = 1;
    }
    vector<int> S;
    for (int i = 1, k, u, v; i <= m; i++){
        cin >> k >> u;
        if (k == 1){
            v = u;
            if (odd[find(u)] != 1){
                odd[find(u)] = 1;
                S.pb(i);
            }
        }else{
            cin >> v;
            if (join(u, v)){
                S.pb(i);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        if (P1[i] == i){
            T = T * binpow(2, sz[i] - 1 + odd[i]) % mod;
        }
    }
    // for (int i = 0; i < m; i++){
    //     auto [u, v] = S[i];
    //     if (u == v){
    //         if (odd[find(u)]){
    //             if (!chk[find1(u)]){
    //                 chk[find1(u)] = 1;
    //                 SS.pb(i + 1);
    //             }
    //         }
    //     }else{
    //         if (join1(u, v)){
    //             SS.pb(i + 1);
    //         }
    //     }
    // }
    cout << T << ' ' << S.size() << endl;
    for (auto v : S) cout << v << ' ';
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