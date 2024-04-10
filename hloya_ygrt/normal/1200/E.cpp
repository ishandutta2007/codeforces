// #pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
// hloya template v27
 
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
 
#define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]
 
void bad(string mes = "Impossible") {cout << mes;exit(0);}
void bad(int mes) {cout << mes;exit(0);}
 
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
 
inline int popcount(int x){
    int count = 0;
    __asm__ volatile("POPCNT %1, %0;":"=r"(count):"r"(x):);
    return count;
}
 
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
 
const int inf = 2e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = (int)2e6 + 450, base = 1e9 + 7;
const ll llinf = 2e18 + 5;
 
const int mod = 998244353;
 
ll binpow (ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1)
			res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}
 
#define norm sdgjkljkdgs
 
int norm(ll x) {
    // cout << x << endl;
    x %= mod;
    if (x >= mod)
        x -= mod;
    if (x < 0)
        x += mod;
    return x;
}
 
int p = 229;
 
int pp[maxn];
 
int main() {
    int n;
    // files1;
    cin >> n;
 
    pp[0] = 1;
    for (int i = 1; i < maxn; i++) {
        pp[i] = 1ll * pp[i - 1] * p % mod;
    }
 
    vector<int> h;
    string res;
 
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
 
        vector<int> ch(s.size(), 0);
        for (int j = 0; j < s.size(); j++) {
            ch[j] = 1ll * pp[j] * (int)s[j] % mod;
 
            if (j != 0) {
                ch[j] += ch[j - 1];
                ch[j] %= mod;
            }
        }
 
 
        int cut = 0;
        for (int j = s.size(); j > 0; j--) {
            if (h.size() < j) continue;
            // cout << h.back() << ' ' << (j == h.size() ? 0 : h[h.size() - j - 1]) << endl;
            // cout << norm(h.back() - (j == h.size() ? 0 : h[h.size() - j - 1])) << endl;
            if (norm(h.back() - (j == h.size() ? 0 : h[h.size() - j - 1])) == 1ll * ch[j - 1] * pp[h.size() - j] % mod) {
                cut = j;
                break;
            }
        }
 
        for (int j = cut; j < s.size(); j++) {
            res += s[j];
            int reval = norm(1ll * pp[h.size()] * s[j] % mod + (h.empty() ? 0ll : 1ll * h.back()));
            h.push_back(reval);
        }
    }
 
    cout << res;
    return 0;
}