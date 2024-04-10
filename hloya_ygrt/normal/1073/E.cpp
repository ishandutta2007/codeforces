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
using namespace std;
  
bool dbg = 0;
  
clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC
  
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
  
#define ll long long int
#define ld long double
#define pii pair<int,int>
#define umap unordered_map<int, int>
  
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
  
#define endl '\n'
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
void amax(T& x, T y) {
    x = max(x, y);
}
  
template<typename T>
void amin(T& x, T y) {
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

ll gcd (ll a, ll b) { while (b) { a %= b; swap (a, b); } return a; }
  
template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }
  
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = (int)5e5 + 12, base = 1e9 + 7;
const ll llinf = 2e18 + 5;
  
template<typename T>
T binpow(T n, T s)
{
    if (s <= 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2);
        return ( 1LL * b * b ) % base;
    } else {
        return (1LL* binpow(n, s - 1) * n) % base;
    }
}

ll dp[20][2][1200], cnt[20][2][1200];
const int mod = 998244353;

void add(ll& x, ll y) {
	// assert(y >= 0 && y < mod);
	x += y;
	if (x >= mod) x -= mod;
}

ll calcdp(const vector<int>& dig, int k) {
	memset(dp, 0, sizeof(dp));
	memset(cnt, 0, sizeof(cnt));

	cnt[0][1][0] = 1;
	for (int i = 0; i < dig.size(); i++)
		for (int msk = 0; msk < 1024; msk++)
			for (int j = 0 + (i == 0); j < 10; j++) {
				add(dp[i + 1][0][msk | (1 << j)], (dp[i][0][msk] * 10ll % mod + 1ll * j * cnt[i][0][msk] % mod) % mod);
				add(cnt[i + 1][0][msk | (1 << j)], cnt[i][0][msk]);

				if (dig[i] == j) {
					add(dp[i + 1][1][msk | (1 << j)], (dp[i][1][msk] * 10ll % mod + 1ll * j * cnt[i][1][msk] % mod) % mod);
					add(cnt[i + 1][1][msk | (1 << j)], cnt[i][1][msk]);
				} else if (j < dig[i]) {
					add(dp[i + 1][0][msk | (1 << j)], (dp[i][1][msk] * 10ll % mod + 1ll * j * cnt[i][1][msk] % mod) % mod);
					add(cnt[i + 1][0][msk | (1 << j)], cnt[i][1][msk]);					
				}
			}
	ll res = 0;
	for (int msk = 0; msk < (1 << 10); msk++)
		if (__builtin_popcount(msk) <= k){
			add(res, dp[dig.size()][0][msk]), add(res, dp[dig.size()][1][msk]);
		}
	return res;
}

int len;
ll calc(ll r, int k) {
	if (r == 0) return 0;
	vector<int> dig;
	ll x = r; while (x) dig.pb(x % 10), x /= 10;
	len = dig.size();
	reverse(all(dig));
	return calcdp(dig, k);
}

ll calc2(ll r, int k) {
	if (r == 0) return 0;
	ll res = calc(r, k);

	vector<int> dig;
	for (int i = 0; i + 1 < len; i++) {
		dig.pb(10);
		add(res, calcdp(dig, k));
	}

	return res;
}

int main() {
	ll l, r;
	int k;
	// files1;
	cin >> l >> r >> k;
	ll res = calc2(r, k) - calc2(l - 1, k);
	if (res >= mod)
		res -= mod;
	if (res < 0)
		res += mod;
	cout << res;
	// cout << calc(500, 3);
	return 0;
}