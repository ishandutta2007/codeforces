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

int main() {
	fast_io;
	// files1;
	int n;
	cin >> n;
	vector<ll> a(n);

	for (int i = 0; i < n; i++) cin >> a[i];

	ll sec = -1;
	map<ll, int> cnt;
	map<ll, vector<ll> > d;

	for (int i = 0; i < n; i++) {
		ll x = a[i];
		vector<ll> cur;

		if (d.count(x)) {
			cur = d[x];
		} else {
			ll sq = sqrt(x);
			while (sq * sq > x) sq--;
			while (sq * sq < x) sq++;

			ll cb = cbrt(x);
			while (cb * cb * cb > x) cb--;
			while (cb * cb * cb < x) cb++;

			ll qb = sqrt(sq);
			while (qb * qb * qb * qb > x) qb--;
			while (qb * qb * qb * qb < x) qb++;

			if (qb * qb * qb * qb == x) {
				cur.pb(qb);
				cur.pb(qb);
				cur.pb(qb);
				cur.pb(qb);
			} else if (cb * cb * cb == x) {
				cur.pb(cb);
				cur.pb(cb);
				cur.pb(cb);
			} else if (sq * sq == x) {
				cur.pb(sq);
				cur.pb(sq);
			} else {
				ll any = 1;
				for (int j = 0; j < n; j++) if (a[i] != a[j]) {
					ll m = gcd(a[i], a[j]);
					if (m > 1) {
						any = m;
						break;
					}
				}
				if (any != 1) {
					cur.pb(any);
					cur.pb(x / any);
				} else {
					cur.pb(sec--);
					cur.pb(sec--);
				}
			}
			d[a[i]] = cur;
		}
		// for (auto e : cur) cout << e << ' ';
		// cout << endl;
		for (auto e : cur) cnt[e] += 1;
	}
	const int mod = 998244353;
	int ans = 1;
	for (auto e : cnt) {
		ans = 1ll * ans * (e.s + 1) % mod;
	}
	cout << ans << "\n";
}