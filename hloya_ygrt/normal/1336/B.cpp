// #pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <list>
 
// hloya template v25
  
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
#include <valarray>
using namespace std;
  
bool dbg = 0;
  
clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC
  
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
  
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
  
void bad(string mes = "Impossible"){cout << mes;exit(0);}
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
  
template<typename T>
void upmax(T& x, T y) {
    x = max(x, y);
}
  
template<typename T>
void upmin(T& x, T y) {
    x = min(x, y);
}
 
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
  
template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }
  
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-6;
const int maxn = (int)1e5 + 12;//, base = 1e9 + 7;
const ll llinf = 2e18 + 5;
const double PI = acos(-1.0);
 
const int mod = 998244353;
  
template<typename T>
T binpow(T n, T s)
{
    if (s <= 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2);
        return ( 1LL * b * b ) % mod;
    } else {
        return (1LL* binpow(n, s - 1) * n) % mod;
    }
}

ll sqr(ll x) {
    return x * x;
}

ll solve(vector<int> r, vector<int> g, vector<int> b) {
    sort(all(r));
    sort(all(g));
    sort(all(b));

    auto eval = [&](int i, int j, int k) {
        if (i < 0 || i >= r.size() || j < 0 || j >= g.size() || k < 0 || k >= b.size()) {
            return llinf;
        }
        return sqr(r[i] - g[j]) + sqr(r[i] - b[k]) + sqr(g[j] - b[k]);
    };

    ll ans = llinf;
    for (int i = 0; i < r.size(); i++) {
        int j = lower_bound(all(g), r[i]) - g.begin();
        int k = lower_bound(all(b), r[i]) - b.begin();

        for (int f = -1; f <= 0; f++)
            for (int h = -1; h <= 0; h++) {
                ans = min(ans, eval(i, j + f, h + k));
            }
    }

    for (int j = 0; j < g.size(); j++) {
        int i = lower_bound(all(r), g[j]) - r.begin();
        int k = lower_bound(all(b), g[j]) - b.begin();

        for (int f = -1; f <= 0; f++)
            for (int h = -1; h <= 0; h++) {
                ans = min(ans, eval(i + f, j, h + k));
            }
    }

    for (int k = 0; k < b.size(); k++) {
        int i = lower_bound(all(r), b[k]) - r.begin();
        int j = lower_bound(all(g), b[k]) - g.begin();

        for (int f = -1; f <= 0; f++)
            for (int h = -1; h <= 0; h++) {
                ans = min(ans, eval(i + f, j + h, k));
            }
    }
    return ans;
}

ll brute(vector<int> r, vector<int> g, vector<int> b) {
    sort(all(r));
    sort(all(g));
    sort(all(b));

    auto eval = [&](int i, int j, int k) {
        if (j < 0 || j >= g.size() || k < 0 || k >= b.size()) {
            return llinf;
        }
        return sqr(r[i] - g[j]) + sqr(r[i] - b[k]) + sqr(g[j] - b[k]);
    };

    ll ans = llinf;
    for (int i = 0; i < r.size(); i++)
        for (int j = 0; j < g.size(); j++)
            for (int k = 0; k < b.size(); k++) {
                ans = min(ans, eval(i, j, k));
            }
    return ans;
}

int main() {
    mt19937_64 mt_rand(228);

    // files1;  
    fast_io;

    int t;
    cin >> t;
    while (t--) {
        int nr, ng, nb;
        cin >> nr >> ng >> nb;
        vector<int> r(nr), g(ng), b(nb);
        for (int i = 0; i < nr; i++) {
            cin >> r[i];
        }
        for (int i = 0; i < ng; i++) {
            cin >> g[i];
        }
        for (int i = 0; i < nb; i++) {
            cin >> b[i];
        }

        cout << solve(r, g, b) << "\n";
    }
    return 0;
}