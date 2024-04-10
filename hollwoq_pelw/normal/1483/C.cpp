/*
 /+===================================================+\
//+---------------------------------------------------+\\
|.|\\...>>>>>>> Hollwo_Pelw's 2nd template<<<<<<<...//|.|
\\+---------------------------------------------------+//
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
    FAST_IO("input.inp", "output.out");
    int testcases = 1;
    // cin >> testcases;
    for (int test = 1; test <= testcases; test++){
        // cout << "Case #" << test << ": ";
        Hollwo_Pelw();
    }
    return 0;
}

// constant
const int allmod[3] = {(int) 1e9 + 7, 998244353, (int) 1e9 + 9};
const int mod = allmod[1];
const int MAXN = 3e5 + 5;
const int inf = 2e9;
const ll linf = 1e18;
#define int long long

int lg[MAXN];

struct initial {
    initial () {
        for (int i = 2; i < MAXN; i++)
            lg[i] = lg[i >> 1] + 1;
    }
} __init;

template<typename T, T(*merge)(T, T) > struct rmq {
    T st[MAXN][20];
    rmq () {}
    rmq (int n, T * arr) {
        for (int i = 1; i <= n; i++){
            st[i][0] = arr[i];
        }
        for (int j = 1; j < 20; j++){
            for (int i = 1; i + (1 << j) <= n + 1; i++){
                st[i][j] = merge(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    
    void init(int n, T * arr){
        for (int i = 1; i <= n; i++){
            st[i][0] = arr[i];
        }
        for (int j = 1; j < 20; j++){
            for (int i = 1; i + (1 << j) <= n + 1; i++){
                st[i][j] = merge(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    
    T query(int L, int R){
        if (L > R) return T(0);
        int j = lg[R - L + 1];
        return merge(st[L][j], st[R - (1 << j) + 1][j]);
    }
};

int h[MAXN], b[MAXN], a[MAXN], n;

int Max(int x, int y){
    return h[x] > h[y] ? y : x;
}

rmq<int, Max> st;

int solve(int l, int r){
    if (l > r) return 0;
    int mid = st.query(l, r);
    int lf = solve(l, mid - 1);
    int rt = solve(mid + 1, r);
    int ans = lf + rt + b[mid];
    if (l != 1 && r != n){
        ans = max(0ll, ans);
    }
    if (l != 1){
        ans = max(rt, ans);
    }
    if (r != n){
        ans = max(lf, ans);
    }
    // cout << l << ' ' << r << ' ' << ans << endl;
    return ans;
}

void Hollwo_Pelw() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) a[i] = i;
    st.init(n, a);
    cout << solve(1, n);
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