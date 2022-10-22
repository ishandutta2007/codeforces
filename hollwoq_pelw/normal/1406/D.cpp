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
const int MAXN = 2e5 + 6 , MAXM = 5e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define int long long

int st[MAXN * 8], a[MAXN], b[MAXN], n, q, f;

void build(int node, int tl, int tr){
    if (tl > tr) return;
    if (tl == tr){
        st[node] = max(0ll, b[tl]);
        return ;
    }
    int tm = (tl + tr) >> 1;
    build(node << 1, tl, tm);
    build(node << 1 | 1, tm + 1, tr);
    st[node] = st[node << 1] + st[node << 1 | 1];

}

void upd(int p, int v, int node = 1, int tl = 1, int tr = n){
    if (p > tr || p < tl) return ;
    if (tl == tr){
        b[tl] += v;
        st[node] = max(0ll, b[tl]);
        return;
    }
    int tm = (tl + tr) >> 1;
    upd(p, v, node << 1, tl, tm);
    upd(p, v, node << 1 | 1, tm + 1, tr);
    st[node] = st[node << 1] + st[node << 1 | 1];
}

void Solve () {
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (!i) f = a[i];
        else b[i] = a[i] - a[i-1];
    }
    n --;
    build(1, 1, n);
    
//    for (int i = 1; i <= n; i++) cout << b[i] << ' '; cout << endl;
//    cout << "dsid: " << st[1] << ' ' << f << endl;
    int ans = (st[1] + f) / 2;
    cout << max(st[1] + f - ans, ans) << endl;
    
    cin >> q;
    while(q--){
        int l, r, x;
        cin >> l >> r >> x;
        if (l == 1) f += x;
        else upd(l - 1, x);
        if (r <= n) upd(r, -x);
        
//        for (int i = 1; i <= n; i++) cout << b[i] << ' '; cout << endl;
//        cout << f << ' '; for (int i = 1; i <= n; i++) {x += b[i]; cout << x << ' ';} cout << endl;
//        cout << "dsid: " << st[1] << ' ' << f << endl;
        int ans = (st[1] + f) / 2;
        cout << max(st[1] + f - ans, ans) << endl;
    }
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
//    cin >> TC;
    while(TC--) Solve();
    return 0;
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