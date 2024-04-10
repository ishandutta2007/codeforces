// #pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
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
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
  
#define ll long long
#define ld long double
#define pii pair<int,int>
#define umap unordered_map<int, int>
  
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("out2.txt","w",stdout)
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
bool upmin(T& x, T y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
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
  
const int inf = 2e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-6;
const int maxn = (int)4e6 + 12, base = 1e9 + 7;
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

int h, g, n, m;
int a[maxn];

vector<int> order;

vector<int> path;
void find_path(int v) {
    int l = v<<1;
    int r = v<<1|1;
    path.push_back(v);
    if (a[l] == 0 && a[r] == 0) {
        return;
    } else if (a[l] > a[r]) {
        find_path(l);
    } else {
        find_path(r);
    }
}

void dfs(int v) {
    while (a[v] > 0) {
        path.clear();
        find_path(v);
        if (path.back() <= m) {
            break;
        } else {
            order.push_back(v);
            for (int i = 0; i + 1 < path.size(); i++) {
                a[path[i]] = a[path[i + 1]];
            }
            a[path.back()] = 0;
        }
    }
    if (a[v << 1]) dfs(v << 1);
    if (a[v << 1|1]) dfs(v<<1|1);
}

void solve() {
    cin >> h >> g;
    n = (1 << h) - 1;
    m = (1 << g) - 1;

    for (int i = 1; i <= 2 * n + 10; i++) {
        a[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    order.clear();
    dfs(1);

    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += a[i];
    }
    cout << ans << "\n";
    for (int ind : order) {
        cout << ind << ' ';
    }
    cout << "\n";
}

int main() {
    fast_io;
    // files1;

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}