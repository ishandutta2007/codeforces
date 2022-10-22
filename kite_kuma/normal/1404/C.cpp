/*	author:  Kite_kuma
	created: 2020.09.06 23:30:19 */

#include <bits/stdc++.h>
using namespace std;

#pragma region aliases

#define rep(i, n) for(long long i = 0; i < (n); i++)
#define rrep(i, n) for(long long i = (n)-1; i > -1; i--)
#define Rep(i, m, n) for(long long i = (m); i < (n); i++)
#define rRep(i, m, n) for(long long i = (n)-1; i >= (m); i--)
#define REP(i, m, n, p) for(long long i = m; i < n; i += p)
#define foa(s, v) for(auto &s : v)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define bcnt(n) __builtin_popcountll(n)
#define endk endl
#define ednl endl
#define enld endl

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using vb = vector<bool>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using mll = map<long long, long long>;
using pll = pair<long long, long long>;
using qll = queue<long long>;
using sll = set<long long>;
using vpll = vector<pair<long long, long long>>;
template <class T = ll>
using V = vector<T>;
template <class T = ll>
using VV = V<V<T>>;
template <class T = ll>
using VVV = V<V<V<T>>>;
//pq()
template <class T = ll>
using pqup = priority_queue<T, vector<T>, greater<T>>;
//pq()
template <class T = ll>
using pqdn = priority_queue<T>;

#pragma endregion

#pragma region constants

long long const limLL = 9223372036854775807;  // POW(2,63)-1 ~ 9.22e18
long long const dekai = 3e16;
const long double pi = acos(-1);
const char el = '\n';
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ddx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int ddy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

const int mod = 1000000007;
// const int mod = 998244353;

#pragma endregion

#pragma region basic_procedure

template <class T>
inline bool isin(T x, T lef, T rig) {
	return ((lef <= x) && (x < rig));
}

template <class T>
inline bool chmin(T &a, T b) {
	if(a > b) {
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool chmax(T &a, T b) {
	if(a < b) {
		a = b;
		return true;
	}
	return false;
}

void Yes(bool f = 1) { cout << (f ? "Yes" : "No") << "\n"; }
void No() { cout << "No\n"; }
void YES(bool f = 1) { cout << (f ? "YES" : "NO") << "\n"; }
void NO() { cout << "NO\n"; }
template <class T>
void drop(T answer) {
	cout << answer << "\n";
	exit(0);
}
void err() {
	cout << -1 << "\n";
	exit(0);
}

vector<long long> vin(long long n) {  //n
	vector<long long> v(n);
	for(long long i = 0; i < n; i++) {
		cin >> v[i];
	}
	return v;
}

//()
// vector 
template <class T>
void vout(vector<T> &v, bool tate = 0) {
	if(v.size() > 0) {
		for(auto it = v.begin(); it < v.end(); it++) {
			cout << *it;
			if(it != v.end() - 1) {
				if(tate)
					cout << endl;
				else
					cout << " ";
			}
		}
	}
	cout << endl;
}

template <class T>
void add(vector<T> &v, T val) {	 //
	for(auto &a : v) a += val;
	return;
}

// vector map<,>
template <class T>
map<T, long long> cntv(vector<T> v) {
	map<T, long long> m;
	for(auto &g : v) {
		if(m.count(g))
			m[g]++;
		else
			m[g] = 1;
	}
	return m;
}

//()
//{1,36,1,3,8,-2,-92}
//{2, 5,2,3,4, 1,  0}
template <class T>
vector<long long> press(vector<T> &v) {
	long long n = v.size();
	vector<long long> w(n);
	map<T, long long> m;
	for(T &p : v) m[p] = 0;
	long long i = 0;
	for(auto &p : m) {
		p.second = i;
		i++;
	}
	for(long long i = 0; i < n; i++) w.at(i) = m[v.at(i)];
	return w;
}

template <class T>
T divup(T a, T b) {
	//
	assert(b != 0);
	T x = abs(a);
	T y = abs(b);
	T z = (x + y - 1) / y;
	if((a < 0 && b > 0) || (a > 0 && b < 0))
		return -z;
	else if(a == 0)
		return 0;
	else
		return z;
}

long long POW(long long a, long long n) {
	long long res = 1;
	while(n > 0) {
		if(n & 1) res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res;
}

template <class T>
int sgn(T x) {	//
	if(x < 0) return -1;
	if(x == 0) return 0;
	return 1;
}

long long modpow(long long a, long long n, long long mod) {	 // a^n mod
	if(mod == 1) return 0LL;
	long long res = 1;
	while(n > 0) {
		if(n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

// a * x % mod == __gcd(a,mod)x
// a  mod
long long modinv(long long a, long long mod) {
	long long b = mod, u = 1, v = 0;
	while(b) {
		long long t = a / b;
		a -= t * b;
		swap(a, b);
		u -= t * v;
		swap(u, v);
	}
	u %= mod;
	if(u < 0) u += mod;
	return u;
}

vvll comb(100, vll(100, -1));
long long com(long long n, long long k) {  //(overflow)
	assert(n < 100 && k < 100);
	if(n < k || k < 0 || n < 0) return 0;
	if(comb[n][k] != -1) return comb[n][k];
	ll res;
	if(n - k < k)
		res = com(n, n - k);
	else if(k == 0)
		res = 1;
	else
		res = com(n - 1, k - 1) + com(n - 1, k);
	comb[n][k] = res;
	return res;
}

// nCk mod
const ll MAX = 5100000;
// 
// MAX=3*10^71900ms
// MAX=5*10^6(300ms)
long long fac[MAX], finv[MAX], inv[MAX];

void cominit() {
	// 
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for(ll i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = mod - inv[mod % i] * (mod / i) % mod;
		finv[i] = finv[i - 1] * inv[i] % mod;
	}
}
long long commod(ll n, ll k) {	// 
	if(n < k) return 0;
	if(n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}
long long pmod(ll n, ll k) {  //
	if(n < k) return 0;
	if(n < 0 || k < 0) return 0;
	return fac[n] * finv[n - k] % mod;
}
long long hmod(ll n, ll k) {  // nHk
	// nok
	//(n+k-1)C(k-1)
	return commod(n + k - 1, n);
}
#pragma endregion

#pragma region input
#define VEC(type, name, size) \
	vector<type> name(size);  \
	INPUT(name)
#define VVEC(type, name, h, w)                     \
	vector<vector<type>> name(h, vector<type>(w)); \
	INPUT(name)
#define INT(...)     \
	int __VA_ARGS__; \
	INPUT(__VA_ARGS__)
#define LL(...)            \
	long long __VA_ARGS__; \
	INPUT(__VA_ARGS__)
#define STR(...)        \
	string __VA_ARGS__; \
	INPUT(__VA_ARGS__)
#define CHAR(...)     \
	char __VA_ARGS__; \
	INPUT(__VA_ARGS__)
#define DOUBLE(...)     \
	double __VA_ARGS__; \
	INPUT(__VA_ARGS__)
#define LD(...)              \
	long double __VA_ARGS__; \
	INPUT(__VA_ARGS__)

template <class T>
void scan(T &a) {
	cin >> a;
}
template <class T>
void scan(vector<T> &a) {
	for(auto &i : a) scan(i);
}
template <class T, class L>
void scan(pair<T, L> &p) {
	scan(p.first);
	scan(p.second);
}
void INPUT() {}
template <class Head, class... Tail>
void INPUT(Head &head, Tail &... tail) {
	scan(head);
	INPUT(tail...);
}
template <class T>
inline void print(T x) {
	cout << x << '\n';
}

template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
	is >> p.first >> p.second;
	return is;
}
#pragma endregion

#pragma region debug

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
	os << p.first << " " << p.second;
	return os;
}

template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
	rep(i, v.size()) {
		if(i) os << " ";
		os << v[i];
	}
	return os;
}

template <typename T>
void view(const std::vector<T> &v) {
	std::cerr << "{ ";
	for(const auto &e : v) {
		std::cerr << e << ", ";
	}
	std::cerr << "\b\b }";
}
template <typename T>
void view(const std::vector<std::vector<T>> &vv) {
	std::cerr << "{\n";
	for(const auto &v : vv) {
		std::cerr << "\t";
		view(v);
		cerr << "\n";
	}
	std::cerr << "}";
}
template <typename T, typename U>
void view(const std::vector<std::pair<T, U>> &v) {
	std::cerr << "{\n";
	for(const auto &c : v) {
		std::cerr << "\t(" << c.first << ", " << c.second << ")\n";
	}
	std::cerr << "}";
}
template <typename T, typename U>
void view(const std::map<T, U> &m) {
	std::cerr << "{\n";
	for(auto &t : m) {
		std::cerr << "\t[" << t.first << "] : " << t.second << "\n";
	}
	std::cerr << "}";
}
template <typename T, typename U>
void view(const std::pair<T, U> &p) {
	std::cerr << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
void view(const std::set<T> &s) {
	std::cerr << "{ ";
	for(auto &t : s) {
		view(t);
		std::cerr << ", ";
	}
	std::cerr << "\b\b }";
}
template <typename T>
void view(T e) {
	std::cerr << e;
}

// when debugging : g++ foo.cpp -DLOCAL
#ifdef LOCAL
void debug_out() {}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	view(H);
	cerr << ", ";
	debug_out(T...);
}
#define debug(...)                                           \
	do {                                                     \
		cerr << __LINE__ << " [" << #__VA_ARGS__ << "] : ["; \
		debug_out(__VA_ARGS__);                              \
		cerr << "\b\b]\n";                                   \
	} while(0)
#define dump(x)                                 \
	do {                                        \
		cerr << __LINE__ << " " << #x << " : "; \
		view(x);                                \
		cerr << "\n";                           \
	} while(0)
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

#pragma endregion

template <class T = long long>
struct BIT {
	//a[i]BITvec[i+1]
	vector<T> vec;
	int n;
	int pw2 = 1;  // n2
	BIT(int sz) : vec(sz + 1, 0), n(sz) {
		while(pw2 * 2 <= n) {
			pw2 *= 2;
		}
	}
	// 
	void add(int place, T val, bool index = 0) {
		if(!index) place++;
		for(int x = place; x <= n; x += x & -x) vec[x] += val;
	}
	//
	T sum0(int a, bool index = 0) {
		if(index) a--;
		T ret = 0;
		for(int x = a; x > 0; x -= x & -x) ret += vec[x];
		return ret;
	}
	//
	T sum(int a, int b) { return sum0(b) - sum0(a); }
	// 
	void update(int place, T val, bool index = 0) {
		T old = sum(place, place + 1);
		add(place, val - old);
		return;
	}
	int LowerBound(T val, int start = 0) {
		// startval0-indexed
		// 
		// [start, ret) >= val startret
		// valn+1
		if(val <= 0) return start;
		val += sum0(start);
		int x = 0;
		for(int k = pw2; k > 0; k /= 2) {
			if(x + k <= n && vec[x + k] < val) {
				val -= vec[x + k];
				x += k;
			}
		}
		return max(start, x + 1);
	}
	int UpperBound(T val, int start = 0) {
		// startval0-indexed
		// 
		// [start, ret) > val startret
		// valn+1
		if(val < 0 /*LB*/) return start;
		val += sum0(start);
		int x = 0;
		for(int k = pw2; k > 0; k /= 2) {
			if(x + k <= n && vec[x + k] <= /*LB*/ val) {
				val -= vec[x + k];
				x += k;
			}
		}
		return max(start, x + 1);
	}
};
template <class T = long long>
struct BIT_Range_Add_Point_Get {
	// 
	//BIT vec[i] = data[i-1]-data[i-2];
	vector<T> vec;
	int n;
	BIT_Range_Add_Point_Get(int sz) : vec(sz + 1, 0), n(sz) {}
	// 
	void add(int lef, int rig, T val, int index = 0) {
		if(!index) {
			lef++;
			rig++;
		}
		for(int x = lef; x <= n; x += x & -x) vec[x] += val;
		for(int x = rig; x <= n; x += x & -x) vec[x] -= val;
	}
	// = 
	T get(int a, int index = 0) {
		a += 1 - index;
		T ret = 0;
		for(int x = a; x > 0; x -= x & -x) ret += vec[x];
		return ret;
	}
};
template <class T = long long>
struct BIT_Range_Add_Range_Get {
	// 
	vector<T> vec1;
	vector<T> vec2;
	int n;
	BIT_Range_Add_Range_Get(int sz) : vec1(sz + 2, 0), vec2(sz + 2), n(sz + 1) {}
	//
	void add(int lef, int rig, T val) {
		lef++;
		rig++;
		for(int x = lef; x <= n; x += x & -x) vec1[x] -= val * lef;
		for(int x = lef; x <= n; x += x & -x) vec2[x] += val;
		for(int x = rig; x <= n; x += x & -x) vec1[x] += val * rig;
		for(int x = rig; x <= n; x += x & -x) vec2[x] -= val;
	}
	//
	T get(int rig) {
		rig += 1;
		T ret = 0;
		for(int x = rig; x > 0; x -= x & -x) ret += vec1[x];
		for(int x = rig; x > 0; x -= x & -x) ret += vec2[x] * rig;
		return ret;
	}
	// 
	T get(int lef, int rig) { return get(rig) - get(lef); }
};

void view(BIT_Range_Add_Range_Get<ll> &bit) {
	cout << "{ ";
	for(int i = 0; i < bit.n - 1; i++) {
		cout << bit.get(i, i + 1) << ", ";
	}
	cout << "\b\b }";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(15);
	srand((unsigned)time(NULL));
	INT(n);
	int q;
	cin >> q;
	vector<int> ans(q);
	VEC(int, a, n);
	rep(i, n) a[i] = i + 1 - a[i];
	// rep(i, n) a[i] -= (i + 1);

	V<pair<pll, int>> r(q);
	for(int i = 0; i < q; i++) {
		INT(x, y);
		r[i] = {{x, n - y}, i};
	}
	using tu = pair<pll, int>;
	sort(all(r), [](tu a, tu b) { return a.first.second < b.first.second; });

	int it = 0;

	BIT_Range_Add_Range_Get<> bit(n + 1);
	pqup<pll> p;

	// vector<int> dp(n + 1,0);
	debug(r);
	rep(rig, n) {
		dump(bit);
		int now = a[rig];
		int ok = -1;
		int ng = rig + 1;
		if(now >= 0) {
			while(abs(ok - ng) > 1) {
				int med = (ok + ng) / 2;
				if(bit.get(med, med + 1) >= now) {
					ok = med;
				} else {
					ng = med;
				}
			}
			debug(ok, ng);
			bit.add(0, ng, 1LL);
		}
		debug(rig, now);
		while(it < q && r[it].first.second == rig + 1) {
			int x, y, num;
			tie(ignore, num) = r[it];
			tie(x, y) = r[it].first;
			debug(x, y, num);
			ans[num] = bit.get(x, x + 1);
			dump(ans[num]);
			it++;
		}

		// rep(i,n+1){
		// 	//bit.get
		// }

		if(it == q) break;
	}

	for(int i = 0; i < q; i++) {
		cout << ans[i] << endl;
	}

	return 0;
}