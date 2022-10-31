#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
 
// hloya template v26
 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
 
#include <bits/stdc++.h>
using namespace std;
 
bool dbg = 0;
  
clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC
  
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define sqr(x) ((x) * (x))
 
#define ull unsigned long long
#define ll long long
#define ld long double
#define pii pair<int,int>
#define umap unordered_map<int, int>
 
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
 
// #define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]
 
void bad(string mes = "NO"){cout << mes;exit(0);}
void bad(int mes){cout << mes;exit(0);}
 
template<typename T>
string bin(T x, int st = 2){
    string ans = "";
    while (x > 0){
        ans += char('0' + x % st);
        x /= st;
    }
    reverse(ans.begin(), ans.end());
    return ans.empty() ? "0" : ans;
}
 
mt19937_64 mt_rand(
    chrono::system_clock::now().time_since_epoch().count()
);
 
template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }
 
// inline int popcount(int x){
//     int count = 0;
//     __asm__ volatile("POPCNT %1, %0;":"=r"(count):"r"(x):);
//     return count;
// }
  
template<typename T>
T input(){
    T ans = 0, m = 1;
    char c = ' ';
  
    while (!((c >= '0' && c <= '9') || c == '-')) {
        c = getchar();
    }
  
    if (c == '-')
        m = -1, c = getchar();
    while (c >= '0' && c <= '9'){
        ans = ans * 10 + (c - '0'), c = getchar();
    }
    return ans * m;
}
 
template<typename T>
T gcd (T a, T b) { while (b) { a %= b; swap (a, b); } return a; }
  
template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }
 
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = (int)2e6 + 3, base = 998244353;
const ll llinf = 2e18 + 5;
const int mod = 1e9 + 7;

int binpow (int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1)
            res = 1ll * res * a % base;
        a = 1ll * a * a % base;
        n >>= 1;
    }
    return res;
}

int last;

map<pair<int, int>, int> us;

int f(int x, int y) {
    if (us.count({x, y})) {
        return us[{x, y}];
    }
    return us[{x, y}] = last++;
}

vector<pii> st;

set<vector<int>> usv;
void brute(vector<int> vals) {
    if (usv.count(vals) || st.size() > 4) {
        return;
    }
    usv.insert(vals);
    if (set<int>(vals.begin(), vals.end()).size() <= 2) {
        for (auto [x, y] : st) {
            cout << x << ' ' << y << endl;
        }
        cout << "fnd";
        exit(0);
    }
    for (int i = 0; i < vals.size(); i++)
        for (int j = i + 1; j < vals.size(); j++) {
            if (vals[i] == vals[j]) {
                continue;
            }
            int t = f(vals[i], vals[j]);
            auto w  = vals;
            w[i] = w[j] = t;
            st.pb({i, j});
            brute(w);
            st.pop_back();
        }
}
    
vector<pii> res;
void solve(int l, int r) {
    if (l == r) {
        return;
    }
    int m = (l + r) >> 1;
    solve(l, m);
    solve(m + 1, r);
    for (int j = 0; j <= m - l; j++) {
        // cout << l + j << ' ' << m + 1 + j << "\n";
        res.push_back({l + j, m + 1 + j});
    }
}

int main() {
    // files1;
    fast_io;

    int n;
    cin >> n;

    int w = 1;
    while (w * 2 < n) {
        w *= 2;
    }

    solve(1, w);
    solve(n - w + 1, n);

    cout << res.size() << endl;
    for (auto [x, y] : res) {
        cout << x << ' ' << y << "\n";
    }
    // int t = 1;
    // // cin >> t;
    // while (t--) {
    //     // solve();
    // }
    return 0;
}