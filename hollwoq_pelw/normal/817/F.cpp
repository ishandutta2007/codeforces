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

void FAST_IO(string filein = "", string fileout = ""){
    if (fopen(filein.c_str(), "r")){
        freopen(filein.c_str(), "r", stdin);
        freopen(fileout.c_str(), "w", stdout);
    }
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
    #ifdef hollwo_pelw_local
        FAST_IO("input.inp", "output.out");
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
const int MAXN = 6e5 + 6;
const int inf = 2e9;
const ll linf = 1e18;
#define int long long

int n, m, st[MAXN << 2], lz_inv[MAXN << 2], lz_val[MAXN << 2];
#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr
#define tm (tl + tr >> 1)

void apply_inv(int id, int tl, int tr) {
    st[id] = tr - tl + 1 - st[id];
    if (lz_val[id] != -1)
        lz_val[id] ^= 1;
    else
        lz_inv[id] ^= 1;
}

void apply_val(int id, int tl, int tr, int v){
    st[id] = (tr - tl + 1) * v;
    lz_val[id] = v;
}

void push(int id, int tl, int tr){
    if (lz_inv[id]){
        apply_inv(left);
        apply_inv(right);
        lz_inv[id] = 0;
    }
    if (lz_val[id] != -1){
        apply_val(left, lz_val[id]);
        apply_val(right, lz_val[id]);
        lz_val[id] = -1;
    }
}

void upd_inv(int l, int r, int id = 1, int tl = 1, int tr = n){
    push(id, tl, tr);
    if (l > r || l > tr || tl > r) return ;
    if (l <= tl && tr <= r) 
        return apply_inv(id, tl, tr); 
    upd_inv(l, r, left), upd_inv(l, r, right);
    st[id] = st[id << 1] + st[id << 1 | 1];
}

void upd_val(int l, int r, int v, int id = 1, int tl = 1, int tr = n){
    push(id, tl, tr);
    if (l > r || l > tr || tl > r) return ;
    if (l <= tl && tr <= r)
        return apply_val(id, tl, tr, v); 
    upd_val(l, r, v, left), upd_val(l, r, v, right);
    st[id] = st[id << 1] + st[id << 1 | 1];
}

bool check(int id, int tl, int tr){
    return st[id] != tr - tl + 1;
}

int query(int id = 1, int tl = 1, int tr = n){
    push(id, tl, tr);
    if (tl == tr) return tl; 
    if (check(left))
        return query(left);
    return query(right);
}

void print(int id = 1, int tl = 1, int tr = n){
    if (tl == tr) 
        return cout << st[id] << ' ', (void) 0;
    push(id, tl, tr);
    print(left), print(right);
}

#undef left
#undef right

struct query_t {
    int t, l, r;
} q[MAXN];

set<int> allp;
map<int, int> comp;
int decomp[MAXN];

void Hollwo_Pelw() {
    cin >> m;
    for (int i = 1; i <= m; i++){
        cin >> q[i].t >> q[i].l >> q[i].r;
        allp.insert(q[i].l);
        allp.insert(q[i].r);
        allp.insert(q[i].r + 1);
    }
    allp.insert(1);
    for (auto v : allp){
        comp[v] = ++ n; 
        decomp[n] = v;
    }
    for (int i = 1, l, r; i <= m; i++){
        l = comp[q[i].l], r = comp[q[i].r];
        if (q[i].t == 1)
            upd_val(l, r, 1);
        if (q[i].t == 2)
            upd_val(l, r, 0);
        if (q[i].t == 3)
            upd_inv(l, r);
        // print(1, 1, n), cout << "\n";
        cout << decomp[query()] << "\n";
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