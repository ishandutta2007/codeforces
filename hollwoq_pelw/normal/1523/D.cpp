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

int n, m, p, mp[66], cnt[1 << 18], res;
string s[MAXN], ans;

void solve(int must) {
    vector<int> bit;
    for (int i = 0; i < m; i++)
        if (s[must][i] == '1') bit.pb(i);
    p = bit.size();
    for (int i = 0; i < (1 << p); i++)
        cnt[i] = 0;

    for (int i = 1; i <= n; i++){
        int mask = 0;
        for (int j = 0; j < p; j++){
            if (s[i][bit[j]] == '1') mask ^= 1 << j;
        }
        cnt[mask] ++;
    }
    
    for (int i = 0; i < p; i++)
        for (int j = 0; j < (1 << p); j++)
            if (j >> i & 1)
                cnt[j ^ (1 << i)] += cnt[j];

    for (int i = 0; i < (1 << p); i++){
        if (cnt[i] >= (n + 1) / 2) {
            if (res < __builtin_popcount(i)) {
                res = __builtin_popcount(i);
                ans = string(m, '0');
                for (int j = 0; j < bit.size(); j++)
                    if (i >> j & 1) ans[bit[j]] = '1';
            }
        }
    }
}

void Hollwo_Pelw() {
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    ans = string(m, '0'), res = 0;
    for (int _ = 0; _ < 30; _++) {
        solve(rng() % n + 1);
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