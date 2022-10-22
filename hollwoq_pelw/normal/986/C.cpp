/*
 /+===================================================+\
//+---------------------------------------------------+\
|.|\...>>>>>>> Hollwo_Pelw's 2nd template<<<<<<<...//|.|
\+---------------------------------------------------+//
 \+===================================================+/
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
// I/O
#define setpre(n)           fixed << setprecision(n)
#define Ptest(x)            return cout << x << endl, (void) 0;
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
void debug(){
    cout << endl;
}
template <typename H, typename... T>
void debug(H a, T... b){
    cout << a << ' ';
    debug(b...);
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

void FAST_IO(string filein = "", string fileout = "", string fileerr = ""){
    if (fopen(filein.c_str(), "r")){
        freopen(filein.c_str(), "r", stdin);
        freopen(fileout.c_str(), "w", stdout);
        #ifdef hollwo_pelw_local
            freopen(fileerr.c_str(), "w", stderr);
        #endif
    }
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
    #ifdef hollwo_pelw_local
        FAST_IO("input.inp", "output.out", "error.err");
        auto start = chrono::steady_clock::now();
    #else
        FAST_IO(".inp", ".out");
    #endif
    int testcases = 1;
    // cin >> testcases;
    for (int test = 1; test <= testcases; test++){
        // cout << "Case #" << test << ": ";
        Hollwo_Pelw();
    }
    #ifdef hollwo_pelw_local
        auto end = chrono::steady_clock::now();
        cout << endl;
        cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
    #endif
    return 0;
}

// constant
const int allmod[3] = {(int) 1e9 + 7, 998244353, (int) 1e9 + 9};
const int mod = allmod[0];
const int MAXN = 2e5 + 6;
const int inf = 2e9;
const ll linf = 1e18;
const ld eps = 1e-9;
// #define int long long

int n, m, chk[1 << 22], a[1 << 22], f[1 << 22];

int inverse(int mask) {
    return ~ mask & ((1 << n) - 1); 
}

int par[1 << 22], ans;

struct disjoint_set_union {
    disjoint_set_union () {
        for (int i = 0; i < (1 << 22); i++)
            par[i] = i;
    }
    int find(int u) {
        return par[u] = (par[u] == u ? u : find(par[u]));
    }
    void merge(int u, int v){
        // cout << "merge " << u << ' ' << v << endl;
        u = find(u), v = find(v);
        if (u == v) return ;
        par[u] = v;
    }
} dsu;

void Hollwo_Pelw() {
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a[i];
        f[a[i]] ++;
    }
    for (int i = 0; i < n; i++){
        for (int mask = 0; mask < (1 << n); mask++){
            if (mask >> i & 1) {
                f[mask] += f[mask ^ (1 << i)];
            }
        }
    }
    for (int i = 0; i < m; i++){
        if (f[inverse(a[i])]){
            dsu.merge(a[i], inverse(a[i]));
            chk[a[i]] = 1;
        }else{
            ans ++;
        }
    }

    for (int i = 0; i < n; i++){
        for (int mask = 0; mask < (1 << n); mask++){
            if (mask >> i & 1){
                chk[mask] |= chk[mask ^ (1 << i)];
            }
        }
    }

    for (int mask = 0; mask < (1 << n); mask++){
        if (!chk[mask]) f[inverse(mask)] = 0;
    }

    for (int i = 0; i < n; i++){
        for (int mask = 0; mask < (1 << n); mask++){
            if (mask >> i & 1){
                if (f[mask] && f[mask ^ (1 << i)])
                    dsu.merge(mask, mask ^ (1 << i));
            }
        }
    }

    for (int i = 0; i < (1 << n); i++){
        if (par[i] == i) ans += f[i] > 0;
    }
    
    cout << ans;
}

/*

./-=====>>><<<-------- DEBUG -------->>><<<=====-\.
/.................................................\
+====================== INP ======================+



+====================== OUT ======================+



+======================*****======================+
\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.

*/