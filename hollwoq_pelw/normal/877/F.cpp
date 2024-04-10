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
#define int long long

int SZ;
 
struct query {
    int l, r, id;
    query() {}
    query(int _l, int _r, int _id) 
        : l(_l), r(_r), id(_id) {}
 
    int tob() {
        return l / SZ;
    }
    bool operator < (query & oth) {
        if (tob() != oth.tob())
            return tob() < oth.tob();
        return (tob() & 1) ? r > oth.r : r < oth.r; 
    }
};

vector<query> queries;

int n, k, q, t[MAXN], a[MAXN];
map<int, int> cmp;
int l = 0, r = -1;
int res[MAXN], ans, cnt[MAXN * 3];
int cur[MAXN], nxt[MAXN], prv[MAXN];

inline void add(int val, int d){
    ans += d ? cnt[nxt[val]] : cnt[prv[val]];
    cnt[cur[val]] ++;
    // cerr << "add " << val << " => ans = " << ans << "\n";
}

inline void del(int val, int d){
    cnt[cur[val]] --;
    ans -= d ? cnt[nxt[val]] : cnt[prv[val]];
    // cerr << "del " << val << " => ans = " << ans << "\n";
}

void Hollwo_Pelw() {
    cin >> n >> k;
    SZ = sqrt(n);
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1, x; i <= n; i++){
        cin >> x;
        if (t[i] == 1)
            a[i] = a[i - 1] + x;
        if (t[i] == 2)
            a[i] = a[i - 1] - x;
    }

    set<int> st; 
    for (int i = 0; i <= n; i++)
        st.insert(a[i]), st.insert(a[i] - k), st.insert(a[i] + k);

    int allp = 0;
    for (auto v : st) cmp[v] = allp ++;

    for (int i = 0; i <= n; i++){
        cur[i] = cmp[a[i]];
        prv[i] = cmp[a[i] - k];
        nxt[i] = cmp[a[i] + k];
    }

    cin >> q;
    for (int i = 1, ll, rr; i <= q; i++){
        cin >> ll >> rr;
        queries.eb(ll - 1, rr, i);
    }
    sort(all(queries));
    for (auto q : queries){
        int ql = q.l, qr = q.r, id = q.id;
        // cerr << "query " << ql << ' ' << qr << ' ' << id << endl;
        while (r < qr) add(++ r, 0);
        while (l > ql) add(-- l, 1);
        while (l < ql) del(l ++, 1);
        while (r > qr) del(r --, 0);
        res[id] = ans;
    }
    for (int i = 1; i <= q; i++){
        cout << res[i] << "\n";
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