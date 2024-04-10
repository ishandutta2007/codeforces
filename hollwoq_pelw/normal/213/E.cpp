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
const int MAXN = 2e5 + 5;
const int inf = 2e9;
const ll linf = 1e18;
const ld eps = 1e-9;
#define int long long

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int X, Y, powX[MAXN], powY[MAXN];

int rnd(int l, int r){
    return rng() % (r - l) + l;
}

inline int mul(int x, int y){
    return x * y % mod;
}

inline int add(int x, int y){
    return x + y >= mod ? x + y - mod : x + y;
}

inline int sub(int x, int y){
    return add(x, mod - y);
}

struct __initial__ {
    __initial__ (){
        // X = rnd(MAXN, mod);
        // Y = rnd(MAXN, mod);
        X = 7, Y = 11;
        powX[0] = powY[0] = 1;
        for (int i = 1; i < MAXN; i++){
            powX[i] = mul(powX[i - 1], X);
            powY[i] = mul(powY[i - 1], Y);
            // if (i < 4)
            //     cout << powX[i] << ' ' << powY[i] << "\n"; 
        }
    }
} __init__;

int n, m;

struct segment_tree {
    int hashX[MAXN << 2], hashY[MAXN << 2], sz[MAXN << 2];

    void upd(int p, int x, int id = 1, int tl = 1, int tr = m){
        if (tl == tr){
            if (x >= 0){
                sz[id] = 1;
                hashX[id] = hashY[id] = x;
            }
            else{
                sz[id] = 0;
                hashX[id] = hashY[id] = 0;
            }
        }else{
            int tm = tl + tr >> 1;
            if (p > tm)
                upd(p, x, id << 1 | 1, tm + 1, tr);
            else
                upd(p, x, id << 1, tl, tm);
            int l = id << 1, r = id << 1 | 1;
            sz[id] = sz[l] + sz[r];
            hashX[id] = add(mul(hashX[l], powX[sz[r]]), hashX[r]);
            hashY[id] = add(mul(hashY[l], powY[sz[r]]), hashY[r]);
        }
    }
} hsh;

int hshX, sX, hshY, sY, q[MAXN];

void Hollwo_Pelw() {
    cin >> n >> m;
    for (int i = 0, a; i < n; i++){
        cin >> a; --a;
        hshX = add(mul(hshX, X), a);
        hshY = add(mul(hshY, Y), a);
        sX = add(sX, powX[i]);
        sY = add(sY, powY[i]);
    }
    for (int i = 1, x; i <= m; i++)
        cin >> x, q[x] = i;
    int cnt = 0;
    for (int i = 1; i <= m; i++){
        hsh.upd(q[i], i - 1);
        if (i >= n){
            if (hsh.hashX[1] == add(hshX, mul(sX, i - n))
                && hsh.hashY[1] == add(hshY, mul(sY, i - n))) cnt ++;
            hsh.upd(q[i - n + 1], -1);
        }
    }
    cout << cnt;
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