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
const int maxn = (int)3e5 + 12, base = 1e9 + 7;
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

int dp[100][100];

int maxbit(int x) {
    if (x == 0) return 35;
    return __builtin_clz(x);
}

int solve(int d) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    int ans = 0;
    for (int n = 0; n <= d; n++) {
        for (int last = 0; last <= d; last++) {
            ans += dp[n][last];
            for (int nw = last + 1; nw <= d; nw++) {
                if (maxbit(last) > maxbit(nw)) {
                    dp[n + 1][nw] += dp[n][last];
                }
            }
        }
    }
    return ans - 1;
}

ll norm(ll d, ll m) {
    vector<ll> x(35);
    vector<ll> dp(35);
    dp[0] = 1;

    ll nxp = 1;
    ll i = 0;

    while (2 * nxp <= d) {
        x[i + 1] = 1 << i;
        i++;
        nxp *= 2;
    }

    x[i + 1] = d - nxp + 1;
    ll ans = 0;

    for (ll i = 1; i < 35; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += 1ll * dp[j] * x[i] % m;
            dp[i] %= m;
        }
        ans += dp[i];
        ans %= m;
    }
    return ans;
}

int main() {
    fast_io;
    // files1;

    int t;
    cin >> t;

    while (t--) {
        int d, m;
        cin >> d >> m;
        cout << norm(d, m) << "\n";
    }
    return 0;
}