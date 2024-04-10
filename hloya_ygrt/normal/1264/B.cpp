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
const int maxn = (int)2e5 + 3, base = 998244353;
const ll llinf = 2e18 + 5;
 
int binpow(int a, int s) { 
    int res = 1;
    while (s) {
        if (s % 2) {
            res = 1ll * res * a % base;
        }
        a = 1ll * a * a % base;
        s /= 2;
    }
    return res;
}

void solve() {

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	vector<int> p1, p2;

	bool okl = false;
	while (a > 0) {
		p1.pb(0);
		a--;

		if (a != 0) {
			p1.pb(1);
			b--;	
		} else {
			if (b > 0) {
				p1.pb(1);
				b--;
				okl = true;
			}
		}
	}

	if (b < 0) {
		bad();
	}

	bool okr = false;
	while (d > 0) {
		p2.pb(3);
		d--;
		if (d != 0) {
			p2.pb(2);
			c--;	
		} else {
			if (c > 0) {
				p2.pb(2);
				c--;
				okr = true;
			}
		}
	}

	if (c < 0) {
		bad();
	}

	reverse(all(p2));

	// cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
	// cout << okr << endl;

	if (p1.size() && p2.size() && (!okl || !okr)) {
		bad();
	}

	// a == 0, d == 0
	if (b > c && p1.size()) {
		p1.insert(p1.begin(), 1);
		b--;
	}
	if (c > b && p2.size()) {
		p2.push_back(2);
		c--;
	}

	// cout << b << ' ' << c << endl;
	if (b != c) {
		if (c == b + 1 && p2.empty() && (okl || p1.empty())) {
			for (int i = 0; i < b; i++) {
				p1.pb(2);
				p1.pb(1);
				// b--;
				// c--;
			}
			c -= b;
			b = 0;
			p1.pb(2);
			c--;
		} else if (b == c + 1 && p1.empty() && (okr || p2.empty())) {
			for (int i = 0; i < c; i++) {
				p1.pb(1);
				p1.pb(2);
				// b--;
				// c--;
			}
			b -= c;
			c = 0;
			p1.pb(1);
			b--;
		} else {
			bad();
		}
	} else {
		for (int i = 0; i < b; i++) {
			p1.pb(2);
			p1.pb(1);
		}
		b = 0;
		c = 0;
	}

	cout << "YES\n";
	for (auto e : p1) {
		cout << e << ' ';
	}
	for (auto e : p2) {
		cout << e << ' ';
	}
}

int main() {
	// files1;
	fast_io;

	solve();

	return 0;
}