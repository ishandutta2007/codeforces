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

int st[MAXN << 2], lz[MAXN << 2];
int n, arr[MAXN], m;

void add(int node, int val){
    st[node] += val;
    lz[node] += val;
}

void push(int node){
    add(node << 1, lz[node]);
    add(node << 1 | 1, lz[node]);
    lz[node] = 0;
}

void build(int node = 1, int tl = 1, int tr = n){
    if (tl == tr){
        st[node] = arr[tl];
        return ;
    }
    int tm = (tl + tr) >> 1;
    build(node << 1, tl, tm);
    build(node << 1 | 1, tm + 1, tr);
    st[node] = min(st[node << 1], st[node << 1 | 1]);
}

void upd(int l, int r, int val, int node = 1, int tl = 1, int tr = n){
    if (l > r || tl > r || l > tr)
        return ;
    if (l <= tl && tr <= r){
        add(node, val);
        return ;
    }
    push(node);
    int tm = (tl + tr) >> 1;
    upd(l, r, val, node << 1, tl, tm);
    upd(l, r, val, node << 1 | 1, tm + 1, tr);
    st[node] = min(st[node << 1], st[node << 1 | 1]);
}

int query(int l, int r, int node = 1, int tl = 1, int tr = n){
    if (tl > r || l > tr || l > r) return linf;
    if (l <= tl && tr <= r) return st[node];
    push(node);
    int tm = (tl + tr) >> 1;
    return min(query(l, r, node << 1, tl, tm),
            query(l, r, node << 1 | 1, tm + 1, tr));
}

void Solve() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    build();
    cin >> m;
    cin.ignore(256, '\n');
    while(m --){
        string s; getline(cin, s);
        vector<int> tmp; s += ' ';
        int val = 0, sg = 1;
        for (char c : s){
            if (c == ' '){
                tmp.pb(val * sg);
                val = 0, sg = 1;
            }else{
                if (c == '-'){
                    sg *= -1;
                }else{
                    val = val * 10 + c -'0';
                }
            }
        }
        int l = tmp[0] + 1, r = tmp[1] + 1;
        if (tmp.size() > 2){
            int v = tmp[2];
            (l > r ? upd(l, n, v), upd(1, r, v) : upd(l, r, v));
        }else{
            cout << (l > r ? min(query(l, n), query(1, r)) : query(l, r)) << "\n";
        }
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

\/-=====>>><<<-------- DEBUG -------->>><<<=====-\/
/\.............................................../\
+====================== INP ======================+

7 8
1 2
2 3
2 4
3 4
3 5
5 6
6 7
5 7

+====================== OUT ======================+


+======================*****======================+
\/...............................................\/
/\-=====>>><<<--------= END =-------->>><<<=====-/\

*/