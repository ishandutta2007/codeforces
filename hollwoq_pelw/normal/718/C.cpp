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
const int MAXN = 1e5 + 5;
const int inf = 2e9;
const ll linf = 1e18;
const ld eps = 1e-9;
// #define int long long

inline int add(int a, int b) {
    a += b; return a < mod ? a : a - mod;
}

inline int sub(int a, int b) {
    return add(a, mod - b);
}

inline int mul(int a, int b) {
    return 1ll * a * b % mod;
}

int n, a[MAXN], q;

struct node {
    int a[2][2];
    int * operator [] (int x) {return a[x];}
    const int * operator [] (int x) const {return a[x];}
    node () {
        for (int i = 0; i < 2; i++){
            a[i][i] = 1, a[i][i ^ 1] = 0;
        }
    }
    node (int x) {
        for (int i = 0; i < 2; i++)
            a[i][0] = a[i][1] = x;
    }
    friend node operator + (node l, node r) {
        node m;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                m[i][j] = add(l[i][j], r[i][j]);
        return m;
    }
    friend node operator * (node l, node r) {
        node m;
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                m[i][j] = add(mul(l[i][0], r[0][j]), mul(l[i][1], r[1][j]));
            }
        }
        return m;
    }
    friend node operator ^ (node x, int y) {
        node r;
        while (y) {
            if (y&1) r = r * x;
            y >>= 1; x = x * x;
        }
        return r;
    }
} base, st[MAXN << 2], lz[MAXN << 2];

#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

void apply(int id, node val){
    st[id] = st[id] * val;
    lz[id] = lz[id] * val;
}

void push(int id){
    apply(id << 1, lz[id]);
    apply(id << 1 | 1, lz[id]);
    lz[id] = node();
}

void build(int id = 1, int tl = 1, int tr = n){
    if (tl == tr) {
        st[id] = base ^ a[tl];
        return ;
    }
    int tm = tl + tr >> 1;
    build(left), build(right);
    st[id] = st[id << 1] + st[id << 1 | 1];
}

void upd(int l, int r, node val, int id = 1, int tl = 1, int tr = n){
    if (l > tr || tl > r) return ;
    if (l <= tl && tr <= r) 
        return apply(id, val);
    int tm = tl + tr >> 1; push(id);
    upd(l, r, val, left), upd(l, r, val, right);
    st[id] = st[id << 1] + st[id << 1 | 1];
}

node query(int l, int r, int id = 1, int tl = 1, int tr = n){
    if (tl > r || l > tr || l > r) return node(0);
    if (l <= tl && tr <= r) return st[id];
    int tm = tl + tr >> 1; push(id);
    return query(l, r, left) + query(l, r, right);
}

#undef left
#undef right

void Hollwo_Pelw() {
    base[1][0] = base[0][1] = 1, base[1][1] = 0;
    cin >> n >> q;
    for (int i = 1, t; i <= n; i++)
        cin >> a[i];
    build();
    for (int i = 1, t, l, r; i <= q; i++){
        cin >> t >> l >> r;
        if (t == 1) {
            cin >> t, upd(l, r, base ^ t);
        }else{
            cout << query(l, r)[0][1] << "\n";
        }
    }
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