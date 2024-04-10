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
//    cin >> testcases;
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
const int mod = allmod[1];
const int MAXN = 2e5 + 6;
const int inf = 2e9;
const ll linf = 1e18;
#define int long long

int n, a[MAXN], c[MAXN];
pii tmp[MAXN];
int bit1[MAXN], bit2[MAXN];
int dp[MAXN];

set<int> allval;
map<int, int> comp;
int cnt = 0;

void add1(int x, int v){
    for (; x < MAXN; x += x & (-x))
        bit1[x] = min(bit1[x], v);
}

void add2(int x, int v){
    x = MAXN - x;
    for (; x < MAXN; x += x & (-x))
        bit2[x] = min(bit2[x], v);
}

int query1(int x){
    int r = linf;
    for (; x; x -= x & (-x))
        r = min(r, bit1[x]);
    return r;
}

int query2(int x){
    x = MAXN - x;
    int r = linf;
    for (; x; x -= x & (-x))
        r = min(r, bit2[x]);
    return r;
}

void Hollwo_Pelw() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> tmp[i];
    }
    sort(tmp + 1, tmp + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++){
        a[i] = tmp[i].F, c[i] = tmp[i].S;
        allval.insert(a[i]);
        allval.insert(a[i] + c[i]);
        ans += c[i];
    }
    for (auto v : allval)
        comp[v] = ++ cnt;

    for (int i = 0; i < MAXN; i++) 
        bit1[i] = bit2[i] = linf;
    for (int i = 1; i <= n; i++){
        // dp[i] = minimum extra cost to reach i
        // dp[i] = dp[j] + max(0, ai - aj - cj);
        // keep aj + cj, 
        // if ai > aj + cj => dp[i] = min(dp[j] - a[j] - c[j]) + a[i];
        // if ai <= aj + cj => dp[i] = min(dp[j])
        if (i != 1){
            dp[i] = min(query1(comp[a[i]]) + a[i], query2(comp[a[i]]));
            // cout << query1(comp[a[i]]) << endl;
            // cout << query2(comp[a[i]]) << endl;
        }
        add1(comp[a[i] + c[i]], dp[i] - a[i] - c[i]);
        add2(comp[a[i] + c[i]], dp[i]);
    }
    cout << dp[n] + ans;
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