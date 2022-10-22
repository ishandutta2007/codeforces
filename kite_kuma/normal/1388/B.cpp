#include <bits/stdc++.h>
using namespace std;
#pragma region all
///////////// ,  /////////////////
#pragma region macros_and_aliases
#define rep(i, n) for(long long i = 0; i < (n); i++)
#define rrep(i, n) for(long long i = (n)-1; i > -1; i--)
#define Rep(i, m, n) for(long long i = (m); i < (n); i++)
#define rRep(i, m, n) for(long long i = (n)-1; i >= (m); i--)
#define REP(i, m, n, p) for(long long i = m; i < n; i += p)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pq priority_queue
#define bcnt(n) __builtin_popcountll(n)
#define endk endl
#define ednl endl
#define enld endl
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using mii = map<int, int>;
using pqll = priority_queue<long long>;
using pqllg = priority_queue<long long, vector<long long>, greater<long long>>;
using mll = map<long long, long long>;
using pll = pair<long long, long long>;
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

/////////////  /////////////////
#pragma region constants

long long const limLL = 9223372036854775807;  // POW(2,63)-1 ~ 9.22e18
long long const dekai = 1e15;
const long double pi = acos(-1);
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int ddx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int ddy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

const int mod = 1000000007;
// const int mod = 998244353;

#pragma endregion

// // 
// /* ----------------------  ---------------------- */
// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision;
// // 
// using Bint = mp::cpp_int;
// // 1024(TLE)
// using Real = mp::number<mp::cpp_dec_float<1024>>;
// /* ----------------------  ---------------------- */

///////////////////  ////////////////////
#pragma region basic_procedure

template <class T>
inline bool isin(T x, T lef, T rig) {
	return ((lef <= x) && (x < rig));
}
template <class T>
inline bool isin(T x, T y, T lef, T rig) {
	return isin(x, lef, rig) && isin(y, lef, rig);
}
template <class T>
inline bool isin(T X, T lefX, T rigX, T Y, T lefY, T rigY) {
	return isin(X, lefX, rigX) && isin(Y, lefY, rigY);
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

#define debug(var)                  \
	do {                            \
		std::cout << #var << " : "; \
		view(var);                  \
	} while(0)

template <typename T>
void view(T e) {
	std::cout << e << std::endl;
}
template <typename T>
void view(const std::vector<T> &v) {
	for(const auto &e : v) {
		std::cout << e << " ";
	}
	std::cout << std::endl;
}
template <typename T>
void view(const std::vector<std::vector<T>> &vv) {
	for(const auto &v : vv) {
		view(v);
	}
}

void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }
void err() { cout << -1 << endl; }

#pragma endregion

////////////////  ///////////////////////
#pragma region math

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
	// POW
	//pow(a,n)
	long long res = 1;
	while(n > 0) {
		if(n & 1) res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res;
}

template <class T>
bool prime(T N) {
	//
	//truefalse
	//false
	//
	if(N <= 1) return false;
	T p = sqrt(N);
	for(long long i = 2; i <= p; i++)
		if(N % i == 0) return false;
	return true;
}

vector<long long> eratos(long long n) {
	//
	//1,0
	assert(n >= 0);
	vll v(n + 1, 1);
	if(n >= 0) v[0] = 0;
	if(n >= 1) v[1] = 0;
	Rep(i, 2, n + 1) {
		if(v[i]) {
			for(ll k = i * 2; k < n + 1; k += i) {
				v[k] = 0;
			}
		}
	}
	return v;
}

vector<long long> primevec(long long n) {  // nvector
	vll v = eratos(n);
	vll ret;
	Rep(i, 2, n + 1) if(v[i]) ret.push_back(i);
	return ret;
}

set<long long> primeset(long long n) {	// nset
	vll v = eratos(n);
	sll s;
	Rep(i, 2, n + 1) if(v[i]) s.insert(i);
	return s;
}

vector<long long> yakusuu(long long n) {  // n
	vector<long long> ret;
	long long sq = sqrt(n);
	for(long long i = 1; i <= sq; ++i) {
		if(n % i == 0) {
			ret.push_back(i);
			if(i * i != n) {
				ret.push_back(n / i);
			}
		}
	}
	sort(ret.begin(), ret.end());
	return ret;
}

map<long long, long long> soinsuu(long long n) {  // map<,>
	map<long long, long long> m;
	long long p = sqrt(n);
	while(n % 2 == 0) {
		n /= 2;
		if(m.count(2)) {
			m[2]++;
		} else {
			m[2] = 1;
		}
	}
	for(long long i = 3; i * i <= n; i += 2) {
		while(n % i == 0) {
			n /= i;
			if(m.count(i)) {
				m[i]++;
			} else {
				m[i] = 1;
			}
		}
	}
	if(n != 1) m[n] = 1;
	return m;
}

vector<long long> keta(ll x) {
	// 10nx1
	//n
	// 0{}
	vll w;
	while(x > 0) {
		w.push_back(x % 10);
		x /= 10;
	}
	reverse(all(w));
	return w;
}

long long ketasum(ll x) {  //
	ll ret = 0;
	while(x > 0) {
		ret += x % 10;
		x /= 10;
	}
	return ret;
}

string bits(long long n, long long k) {	 // nkbitstring
	string s = "";
	rep(i, k) {
		char c = '0' + (n % 2);
		s += c;
		n /= 2;
	}
	reverse(all(s));
	return s;
}

long long modpow(long long a, long long n, long long mod) {	 // a^n mod
	long long res = 1;
	while(n > 0) {
		if(n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

long long modinv(long long a, long long mod) {	// a^{-1} mod
	// moda()
	return modpow(a, mod - 2, mod);
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
const ll MAX = 510000;
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

long long next_combination(long long sub) {	 //bit
	long long x = sub & -sub, y = sub + x;
	return (((sub & ~y) / x) >> 1) | y;
}

#pragma endregion

//////////////// vector ///////////////////////
#pragma region vector
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

//
//
// O(nlogn)
template <class T>
vector<T> singlized(vector<T> &v) {
	set<T> s;
	vector<T> ret;
	for(auto seg : v) {
		if(!s.count(seg)) {
			ret.push_back(seg);
			s.insert(seg);
		}
	}
	return ret;
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

//()
//{1,36,1,3,8,-2,-92}
//{2, 6,3,4,5, 1,  0}
template <class T>
vector<long long> ranking(vector<T> &v) {
	vector<pair<T, long long>> r;
	long long n = v.size();
	rep(i, n) r.push_back({v[i], i});
	sort(all(r));
	vll res(n);
	rep(i, n) { res[r[i].second] = i; }
	return res;
}

//
// (sortedplace(v)).[i] = i
template <class T>
vector<long long> sortedplace(vector<T> &v) {
	auto w = ranking(v);
	ll n = v.size();
	vll res(n);
	rep(i, n) res[w[i]] = i;
	return res;
}

// vector map<,>
template <class T>
map<T, long long> countv(vector<T> v) {
	map<T, long long> m;
	for(auto &g : v) {
		if(m.count(g))
			m[g]++;
		else
			m[g] = 1;
	}
	return m;
}

// template <class T>
// ll inversion_number(vector<T> &v) {	 // v()
// 	map<T, ll> m;
// 	for(auto &t : v) {
// 		m[t] = 0;
// 	}
// 	ll i = 0;
// 	for(auto &p : m) {
// 		p.second = i;
// 		i++;
// 	}
// 	vll w;
// 	for(auto &t : v) {
// 		w.push_back(m[t]);
// 	}
// 	BIT<> bit(i);
// 	ll res = 0;
// 	for(auto &n : w) {
// 		res += bit.sum(n + 1, i);
// 		bit.add(n, 1LL);
// 	}
// 	return res;
// }

template <class T>	// WarshallFloyd
void warshall(vector<vector<T>> &v) {
	ll n = v.size();
	rep(i, n) rep(j, n) rep(k, n) v[j][k] = min(v[j][k], v[j][i] + v[i][k]);
	return;
}

#pragma endregion

////////////////  ///////////////////////
#pragma region ruisekiwa

// 1
template <class T>
vector<T> barsuminit(vector<T> &v) {
	ll h = v.size();
	V<T> ret(h + 1);
	ret[0] = 0;
	rep(i, h) ret[i + 1] = v[i] + ret[i];
	return ret;
}
template <class T>
T barsum(vector<T> &v, ll x0, ll x1) {
	if(x1 <= x0) return 0;
	return v[x1] - v[x0];
}
// 2
template <class T>
vector<vector<T>> sheetsuminit(vector<vector<T>> &v) {
	ll h = v.size();
	assert(h != 0);
	ll w = v.at(0).size();
	VV<T> ret(h + 1, V<T>(w + 1));
	rep(i, h + 1) ret[i][0] = 0;
	rep(i, w + 1) ret[0][i] = 0;
	rep(i, h) rep(j, w) ret[i + 1][j + 1] = v[i][j];
	rep(i, h) rep(j, w) ret[i + 1][j + 1] += ret[i + 1][j];
	rep(i, h) rep(j, w) ret[i + 1][j + 1] += ret[i][j + 1];
	return ret;
}
//[x0,y0],(x1,y1)
//(x,y).(x1-x0)*(y1-y0);
template <class T>
T sheetsum(vector<vector<T>> &v, ll x0, ll y0, ll x1, ll y1) {
	if(x0 >= x1 || y0 >= y1) return 0;
	return v[x0][y0] + v[x1][y1] - v[x0][y1] - v[x1][y0];
}
// 3
template <class T>
vector<vector<vector<T>>> cubiodsuminit(vector<vector<vector<T>>> &v) {
	ll h = v.size();
	assert(h != 0);
	ll w = v[0].size();
	assert(w != 0);
	ll z = v[0][0].size();
	VVV<T> ret(h + 1, VV<T>(w + 1, V<T>(z + 1)));
	rep(i, h + 1) rep(j, w + 1) rep(k, z + 1) { ret[i][j][k] = (i == 0 || j == 0 || k == 0 ? 0 : v[i - 1][j - 1][k - 1]); }
	rep(i, h) rep(j, w) rep(k, z) ret[i + 1][j + 1][k + 1] += ret[i + 1][j + 1][k];
	rep(i, h) rep(j, w) rep(k, z) ret[i + 1][j + 1][k + 1] += ret[i + 1][j][k + 1];
	rep(i, h) rep(j, w) rep(k, z) ret[i + 1][j + 1][k + 1] += ret[i][j + 1][k + 1];
	return ret;
}
//[x0,y0],(x1,y1)
//(x,y).(x1-x0)*(y1-y0);
template <class T>
T cubiodsum(vector<vector<vector<T>>> &v, ll x0, ll y0, ll z0, ll x1, ll y1, ll z1) {
	if(x0 >= x1 || y0 >= y1 || z0 >= z1) return 0;
	return v[x1][y1][z1] - v[x1][y1][z0] - v[x1][y0][z1] - v[x0][y1][z1] + v[x1][y0][z0] + v[x0][y1][z0] + v[x0][y0][z1] - v[x0][y0][z0];
}

#pragma endregion

//////////////  ///////////////////////////
#pragma region objects

struct mint {
	// auto mod int
	// https://youtu.be/L8grWxBlIZ4?t=9858
	// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
	// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
	ll x;  // typedef long long ll;
	mint(ll x = 0) : x((x % mod + mod) % mod) {}
	mint operator-() const { return mint(-x); }
	mint &operator+=(const mint a) {
		if((x += a.x) >= mod) x -= mod;
		return *this;
	}
	mint &operator-=(const mint a) {
		if((x += mod - a.x) >= mod) x -= mod;
		return *this;
	}
	mint &operator*=(const mint a) {
		(x *= a.x) %= mod;
		return *this;
	}
	mint operator+(const mint a) const { return mint(*this) += a; }
	mint operator-(const mint a) const { return mint(*this) -= a; }
	mint operator*(const mint a) const { return mint(*this) *= a; }
	mint pow(ll t) const {
		if(!t) return 1;
		mint a = pow(t >> 1);
		a *= a;
		if(t & 1) a *= *this;
		return a;
	}

	// for prime mod
	mint inv() const { return pow(mod - 2); }
	mint &operator/=(const mint a) { return *this *= a.inv(); }
	mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream &operator>>(istream &is, const mint &a) { return is >> a.x; }
ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }

struct UF {						// Union_Find(size)
	vector<long long> par, sz;	// par[i]:i() par[3] = 2 : 32
	// sizei
	UF(long long N) : par(N), sz(N) {  //
		for(long long i = 0; i < N; i++) {
			par[i] = i;
			sz[i] = 1;
		}
	}

	long long root(long long x) {  // xroot(x) = {x}
		if(par[x] == x) return x;
		return par[x] = root(par[x]);
	}

	void unite(long long x, long long y) {	// xy
		long long rx = root(x);				// xrx
		long long ry = root(y);				// yry
		if(rx == ry) return;				// xy(=)
		par[rx] = ry;						// xy(=)xrxyry
		sz[ry] += sz[rx];
		sz[rx] = 0;	 // 0
	}

	bool same(long long x, long long y) {  // 2x, ytrue
		long long rx = root(x);
		long long ry = root(y);
		return rx == ry;
	}
	long long size(long long x) { return sz[root(x)]; }
};

template <class T = ll>
struct BIT {
	//a[i]BITvec[i+1]
	vector<T> vec;
	ll n;
	ll pw2 = 1;	 // n2
	BIT(long long sz) : vec(sz + 1, 0), n(sz) {
		while(pw2 * 2 <= n) {
			pw2 *= 2;
		}
	}
	// 
	void add(long long place, T val, bool index = 0) {
		if(!index) place++;
		for(long long x = place; x <= n; x += x & -x) vec[x] += val;
	}
	//
	T sum0(long long a, bool index = 0) {
		if(index) a--;
		T ret = 0;
		for(int x = a; x > 0; x -= x & -x) ret += vec[x];
		return ret;
	}
	//
	T sum(long long a, long long b) { return sum0(b) - sum0(a); }
	// 
	void update(long long place, T val, bool index = 0) {
		T old = sum(place, place + 1);
		add(place, val - old);
		return;
	}
	ll LowerBound(T val, long long start = 0) {
		// startval0-indexed
		// 
		// [start, ret) >= val startret
		// valn+1
		if(val <= 0) return start;
		val += sum0(start);
		long long x = 0;
		ll p = 1;
		for(long long k = pw2; k > 0; k /= 2) {
			if(x + k <= n && vec[x + k] < val) {
				val -= vec[x + k];
				x += k;
			}
		}
		return max(start, x + 1);
	}
	ll UpperBound(T val, long long start = 0) {
		// startval0-indexed
		// 
		// [start, ret) > val startret
		// valn+1
		if(val < 0 /*LB*/) return start;
		val += sum0(start);
		long long x = 0;
		ll p = 1;
		for(long long k = pw2; k > 0; k /= 2) {
			if(x + k <= n && vec[x + k] <= /*LB*/ val) {
				val -= vec[x + k];
				x += k;
			}
		}
		return max(start, x + 1);
	}
};

template <class T = ll>
struct edge {
	T len;
	ll to;
};

template <class T = ll>
struct graph {	// 0-indexed
	vector<vector<edge<T>>> edges;
	bool directed, weight;
	long long ver;

	// constructor
	graph(long long vertex, bool direction = 0, bool weigh = 0) : edges(vertex) {
		ver = vertex;
		directed = direction;
		weight = weigh;
		edges.resize(vertex);
	}

	// (0-indexed)
	void update(long long from, long long to, T len = 1, bool direction = 1) {
		edge<T> e;
		e.to = to;
		e.len = len;
		edges[from].push_back(e);
		if(!direction) {
			e.to = from;
			edges[to].push_back(e);
		}
	}

	// (1-indexed)
	void input(long long edge_num, long long index = 1) {
		rep(i, edge_num) {
			ll a;
			ll b;
			cin >> a >> b;
			a -= index;
			b -= index;
			T c;
			if(weight)
				cin >> c;
			else
				c = 1;
			update(a, b, c, directed);
		}
	}

	//path<vll> O((ver)log(ver)+(edge))
	vector<T> dijkstra(long long start) {
		vector<T> ret(ver, (T)dekai);
		pqup<pair<T, long long>> p;	 //{dist,place}
		p.push({0, start});
		ret[start] = 0;

		while(!p.empty()) {
			T dist = p.top().first;
			ll place = p.top().second;
			p.pop();
			if(ret[place] < dist) continue;
			for(auto &next : edges[place]) {
				ll nextplace = next.to;
				T dis = next.len;
				if(chmin(ret[nextplace], dist + dis)) {
					p.push({ret[nextplace], nextplace});
				}
			}
		}
		return ret;
	}

	// O((ver)*(edge))
	// ret[i] = -dekai;
	vector<T> BellmanFord(long long start) {
		vector<T> ret(ver, dekai);
		ret[start] = 0;
		rep(loop, ver - 1) {
			rep(v, ver) {
				for(auto &e : edges[v]) {
					chmin(ret[e.to], ret[v] + e.len);
				}
			}
		}

		//
		queue<ll> q;
		vb chk(ver, 0);
		rep(v, ver) {
			for(auto &e : edges[v]) {
				if(chmin(ret[e.to], ret[v] + e.len)) {
					if(!chk[e.to]) {
						q.push(e.to);
						chk[e.to] = 1;
					}
				}
			}
		}
		while(!q.empty()) {
			ll now = q.front();
			q.pop();
			for(auto &e : edges[now]) {
				if(!chk[e.to]) {
					chk[e.to] = 1;
					q.push(e.to);
				}
			}
		}
		rep(i, ver) if(chk[i]) ret[i] = -dekai;

		return ret;
	}

	//
	//ver
	vector<long long> topo_sort() {
		assert(directed);
		vector<long long> num_input(ver);
		// 
		for(long long i = 0; i < ver; i++) {
			for(auto e : edges[i]) {
				num_input[e.to]++;
			}
		}
		// 0queue
		queue<long long> que;
		for(int i = 0; i < ver; i++) {
			if(num_input[i] == 0) {
				que.push(i);
			}
		}
		vector<long long> ans;
		while(!que.empty()) {
			auto node = que.front();
			que.pop();
			ans.push_back(node);
			// 
			for(auto e : edges[node]) {
				num_input[e.to]--;
				// 0queue
				if(num_input[e.to] == 0) {
					que.push(e.to);
				}
			}
		}
		return ans;
	}

	pair<pair<long long, long long>, T> DiameterOfTree() {	//{{},}
		ll v1, v2;											// 0v1
		V<T> dis(ver, -1);
		dis[0] = 0;
		queue<ll> q;
		q.push(0);
		while(!q.empty()) {
			ll now = q.front();
			q.pop();
			for(auto &e : edges[now]) {
				if(dis[e.to] != -1) continue;
				dis[e.to] = dis[now] + e.len;
				q.push(e.to);
			}
			if(q.empty()) v1 = now;
		}
		rep(i, ver) dis[i] = -1;
		dis[v1] = 0;
		q.push(v1);
		while(!q.empty()) {
			ll now = q.front();
			q.pop();
			for(auto &e : edges[now]) {
				if(dis[e.to] != -1) continue;
				dis[e.to] = dis[now] + e.len;
				q.push(e.to);
			}
			if(q.empty()) v2 = now;
		}
		pair<pll, T> ans = {{v1, v2}, dis[v2]};
		return ans;
	}

	//
	graph<T> RootToLeaf(ll root) {	// 0-indexed
		graph<T> ret(ver, 1, weight);
		vb chk(ver, 0);
		chk[root] = 1;
		function<void(ll)> dfs = [&](ll now) {
			for(auto &e : edges[now]) {
				if(chk[e.to] == 1) continue;
				chk[e.to] = 1;
				ret.update(now, e.to, e.len, 1);
				dfs(e.to);
			}
		};
		dfs(root);
		return ret;
	}

	//
	graph<T> LeafToRoot(ll root) {	// 0-indexed
		graph<T> ret(ver, 1, weight);
		vb chk(ver, 0);
		chk[root] = 1;
		function<void(ll)> dfs = [&](ll now) {
			for(auto &e : edges[now]) {
				if(chk[e.to] == 1) continue;
				chk[e.to] = 1;
				ret.update(e.to, now, e.len, 1);
				dfs(e.to);
			}
		};
		dfs(root);
		ret.update(root, root, 0);
		return ret;
	}

	// LeafToRootvector.par[i]=i
	vector<long long> par(ll root) {  // 0-indexed
		vll ret(ver, -1);
		ret[root] = root;  // rootroot
		function<void(ll)> dfs = [&](ll now) {
			for(auto &e : edges[now]) {
				if(ret[e.to] != -1) continue;
				ret[e.to] = now;
				dfs(e.to);
			}
		};
		dfs(root);
		return ret;
	}
	vector<edge<T>> ParentAndDistance(ll root) {  // 0-indexed
		V<edge<T>> ret(ver);
		rep(i, ver) ret[i].to = -1;
		ret[root].to = root;  // rootroot
		ret[root].len = 0;	  // root0
		function<void(ll)> dfs = [&](ll now) {
			for(auto &e : edges[now]) {
				if(ret[e.to].to != -1) continue;
				ret[e.to].to = now;
				ret[e.to].len = e.len;
				dfs(e.to);
			}
		};
		dfs(root);
		return ret;
	}

	//sheet.warshall
	VV<T> GraphArray(void) {
		VV<T> ret(ver, V<ll>(ver, dekai));
		rep(from, ver) {
			for(auto &e : edges[from]) {
				ret[from][e.to] = e.len;
			}
			ret[from][from] = 0;
		}
		return ret;
	}
};

#pragma region Segment_Trees

template <class T = ll>
struct STmax {	//
	ll size;	// tree=m*2-1
	ll m;		// tree
	vector<T> seg;
	STmax(long long n) : size(n), m(n), seg(0) {
		m = 1;
		while(m < n) {
			m *= 2;
		}
		size = m * 2 - 1;
		rep(i, size) { seg.push_back(-dekai); }
	}
	void update(ll i, T k) {  // ik
		ll v = i + m - 1;
		seg[v] = k;
		while(v > 0) {
			v = (v - 1) / 2;
			seg[v] = max(seg[v * 2 + 1], seg[v * 2 + 2]);
		}
	}
	T query(ll a, ll b, ll k, ll l, ll r) {	 //[a,b)
		if(r <= a || b <= l) return -dekai;
		if(a <= l && r <= b) return seg[k];
		T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return max(vl, vr);
	}
	T largest(ll a, ll b) {
		if(a >= b) return -dekai;
		return query(a, b, 0, 0, m);
	}
};

template <class T = ll>
struct STmin {	//
	ll size;	// tree=m*2-1
	ll m;		// tree
	vector<T> seg;
	STmin(long long n) : size(n), m(n), seg(0) {
		m = 1;
		while(m < n) {
			m *= 2;
		}
		size = m * 2 - 1;
		rep(i, size) { seg.push_back(dekai); }
	}
	void update(ll i, T k) {  // ik
		ll v = i + m - 1;
		seg[v] = k;
		while(v > 0) {
			v = (v - 1) / 2;
			seg[v] = min(seg[v * 2 + 1], seg[v * 2 + 2]);
		}
	}
	T query(ll a, ll b, ll k, ll l, ll r) {	 //[a,b)
		if(r <= a || b <= l) return dekai;
		if(a <= l && r <= b) return seg[k];
		// cout << "#" << a << " " << b << " " << k << " " << l << " " << r << endl;
		T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);

		return min(vl, vr);
	}
	T smallest(ll a, ll b) {
		if(a >= b) return dekai;
		return query(a, b, 0, 0, m);
	}
};

template <class T = ll>
struct STsum {	//
	ll size;	// tree=m*2-1
	ll m;		// tree
	vector<T> seg;
	STsum(long long n) : size(n), m(n), seg(0) {
		m = 1;
		while(m < n) {
			m *= 2;
		}
		size = m * 2 - 1;

		rep(i, size) { seg.push_back(0); }
		//
	}
	void update(ll i, T k) {  // ik
		ll v = i + m - 1;
		seg[v] = k;
		while(v > 0) {
			v = (v - 1) / 2;

			seg[v] = seg[v * 2 + 1] + seg[v * 2 + 2];
			//
		}
	}
	T query(ll a, ll b, ll k, ll l, ll r) {	 //[a,b)
		if(r <= a || b <= l) return 0;
		if(a <= l && r <= b) return seg[k];
		T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);

		return vl + vr;	 //
	}
	T sum(ll a, ll b) {
		if(a >= b) return 0;
		return query(a, b, 0, 0, m);
	}
};

template <class T = ll>
struct ST {	 //
	STmax<T> stmax;
	STmin<T> stmin;
	STsum<T> stsum;
	ST(long long n) : stmax(n), stmin(n), stsum(n) {}
	void update(ll place, T val) {
		stmax.update(place, val);
		stmin.update(place, val);
		stsum.update(place, val);
	}
	T largest(ll a, ll b) { return stmax.largest(a, b); }
	T smallest(ll a, ll b) { return stmin.smallest(a, b); }
	T sum(ll a, ll b) { return stsum.sum(a, b); }
};

#pragma endregion

#pragma endregion

//////////////  ////////////////////////
#pragma region making
//
// reach : 2^reach 
// VV<ll> doublize(vll &v, ll reach = 25) {  // vvector
// 	ll n = v.size();
// 	VV<long long> ret(reach + 1, V<>(n));
// 	ret[0] = v;
// 	rep(i, reach) rep(j, n) { ret[i + 1][j] = ret[i][ret[i][j]]; }
// 	return ret;
// }

// vector<long long> DepthOfTree()

// vector<int> z_algorithm(const string &s) {
// 	vector<int> prefix(s.size());
// 	for(int i = 1, j = 0; i < s.size(); i++) {
// 		if(i + prefix[i - j] < j + prefix[j]) {
// 			prefix[i] = prefix[i - j];
// 		} else {
// 			int k = max(0, j + prefix[j] - i);
// 			while(i + k < s.size() && s[k] == s[i + k]) ++k;
// 			prefix[i] = k;
// 			j = i;
// 		}
// 	}
// 	prefix[0] = (int)s.size();
// 	return prefix;
// }

// template <class T = ll>
// struct BITforRange {
// 	// BIT
// 	ll n;
// 	BIT<> p, q;
// 	BITforRange(long long sz) : n(sz) {
// 		p(n + 1);
// 		q(n + 1);
// 	}
// 	// [left,right)  val 
// 	void AddforRange(long long left, long long right, T val, bool index = 0) {
// 		p.add(left, -val * left);
// 		p.add(left, val * right);
// 		q.add(left, val);
// 		q.add(right, -val);
// 	}
// 	//
// 	T sum0(long long a, bool index = 0) { return p.sum0(a) + a * q.sum0(a); }
// 	//
// 	T sum(long long a, long long b) { return sum0(b) - sum0(a); }
// };

////////////////  ////////////
#pragma region geometry
using Real = double;
using Point = complex<Real>;
const Real EPS = 1e-8, PI = acos(-1);

inline bool eq(Real a, Real b) { return fabs(b - a) < EPS; }

Point operator*(const Point &p, const Real &d) { return Point(real(p) * d, imag(p) * d); }

istream &operator>>(istream &is, Point &p) {
	Real a, b;
	is >> a >> b;
	p = Point(a, b);
	return is;
}

ostream &operator<<(ostream &os, Point &p) { return os << fixed << setprecision(10) << p.real() << " " << p.imag(); }

//  p  theta 
Point rotate(Real theta, const Point &p) {
	return Point(cos(theta) * p.real() - sin(theta) * p.imag(), sin(theta) * p.real() + cos(theta) * p.imag());
}

Real radian_to_degree(Real r) { return (r * 180.0 / PI); }

Real degree_to_radian(Real d) { return (d * PI / 180.0); }

// a-b-c 
Real get_angle(const Point &a, const Point &b, const Point &c) {
	const Point v(b - a), w(c - b);
	Real alpha = atan2(v.imag(), v.real()), beta = atan2(w.imag(), w.real());
	if(alpha > beta) swap(alpha, beta);
	Real theta = (beta - alpha);
	return min(theta, 2 * acos(-1) - theta);
}

namespace std {
bool operator<(const Point &a, const Point &b) { return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag(); }
}  // namespace std

struct Line {
	Point a, b;

	Line() = default;

	Line(Point a, Point b) : a(a), b(b) {}

	Line(Real A, Real B, Real C)  // Ax + By = C
	{
		if(eq(A, 0))
			a = Point(0, C / B), b = Point(1, C / B);
		else if(eq(B, 0))
			b = Point(C / A, 0), b = Point(C / A, 1);
		else
			a = Point(0, C / B), b = Point(C / A, 0);
	}

	friend ostream &operator<<(ostream &os, Line &p) { return os << p.a << " to " << p.b; }

	friend istream &operator>>(istream &is, Line &a) { return is >> a.a >> a.b; }
};

struct Segment : Line {
	Segment() = default;

	Segment(Point a, Point b) : Line(a, b) {}
};

struct Circle {
	Point p;
	Real r;

	Circle() = default;

	Circle(Point p, Real r) : p(p), r(r) {}
};

using Points = vector<Point>;
using Polygon = vector<Point>;
using Segments = vector<Segment>;
using Lines = vector<Line>;
using Circles = vector<Circle>;

Real cross(const Point &a, const Point &b) { return real(a) * imag(b) - imag(a) * real(b); }

Real dot(const Point &a, const Point &b) { return real(a) * real(b) + imag(a) * imag(b); }

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
// 
int ccw(const Point &a, Point b, Point c) {
	b = b - a, c = c - a;
	if(cross(b, c) > EPS) return +1;   // "COUNTER_CLOCKWISE"
	if(cross(b, c) < -EPS) return -1;  // "CLOCKWISE"
	if(dot(b, c) < 0) return +2;	   // "ONLINE_BACK"
	if(norm(b) < norm(c)) return -2;   // "ONLINE_FRONT"
	return 0;						   // "ON_SEGMENT"
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
// 
bool parallel(const Line &a, const Line &b) { return eq(cross(a.b - a.a, b.b - b.a), 0.0); }

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
// 
bool orthogonal(const Line &a, const Line &b) { return eq(dot(a.a - a.b, b.a - b.b), 0.0); }

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A
// 
//  l  p 
Point projection(const Line &l, const Point &p) {
	double t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
	return l.a + (l.a - l.b) * t;
}

Point projection(const Segment &l, const Point &p) {
	double t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
	return l.a + (l.a - l.b) * t;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B
// 
//  l  p  
Point reflection(const Line &l, const Point &p) { return p + (projection(l, p) - p) * 2.0; }

bool intersect(const Line &l, const Point &p) { return abs(ccw(l.a, l.b, p)) != 1; }

bool intersect(const Line &l, const Line &m) { return abs(cross(l.b - l.a, m.b - m.a)) > EPS || abs(cross(l.b - l.a, m.b - l.a)) < EPS; }

bool intersect(const Segment &s, const Point &p) { return ccw(s.a, s.b, p) == 0; }

bool intersect(const Line &l, const Segment &s) { return cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < EPS; }

Real distance(const Line &l, const Point &p);

bool intersect(const Circle &c, const Line &l) { return distance(l, c.p) <= c.r + EPS; }

bool intersect(const Circle &c, const Point &p) { return abs(abs(p - c.p) - c.r) < EPS; }

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B
bool intersect(const Segment &s, const Segment &t) {
	return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

int intersect(const Circle &c, const Segment &l) {
	if(norm(projection(l, c.p) - c.p) - c.r * c.r > EPS) return 0;
	auto d1 = abs(c.p - l.a), d2 = abs(c.p - l.b);
	if(d1 < c.r + EPS && d2 < c.r + EPS) return 0;
	if(d1 < c.r - EPS && d2 > c.r + EPS || d1 > c.r + EPS && d2 < c.r - EPS) return 1;
	const Point h = projection(l, c.p);
	if(dot(l.a - h, l.b - h) < 0) return 2;
	return 0;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A&lang=jp
int intersect(Circle c1, Circle c2) {
	if(c1.r < c2.r) swap(c1, c2);
	Real d = abs(c1.p - c2.p);
	if(c1.r + c2.r < d) return 4;
	if(eq(c1.r + c2.r, d)) return 3;
	if(c1.r - c2.r < d) return 2;
	if(eq(c1.r - c2.r, d)) return 1;
	return 0;
}

Real distance(const Point &a, const Point &b) { return abs(a - b); }

Real distance(const Line &l, const Point &p) { return abs(p - projection(l, p)); }

Real distance(const Line &l, const Line &m) { return intersect(l, m) ? 0 : distance(l, m.a); }

Real distance(const Segment &s, const Point &p) {
	Point r = projection(s, p);
	if(intersect(s, r)) return abs(r - p);
	return min(abs(s.a - p), abs(s.b - p));
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D
Real distance(const Segment &a, const Segment &b) {
	if(intersect(a, b)) return 0;
	return min({distance(a, b.a), distance(a, b.b), distance(b, a.a), distance(b, a.b)});
}

Real distance(const Line &l, const Segment &s) {
	if(intersect(l, s)) return 0;
	return min(distance(l, s.a), distance(l, s.b));
}

Point crosspoint(const Line &l, const Line &m) {
	Real A = cross(l.b - l.a, m.b - m.a);
	Real B = cross(l.b - l.a, l.b - m.a);
	if(eq(abs(A), 0.0) && eq(abs(B), 0.0)) return m.a;
	return m.a + (m.b - m.a) * B / A;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C
Point crosspoint(const Segment &l, const Segment &m) { return crosspoint(Line(l), Line(m)); }

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D
pair<Point, Point> crosspoint(const Circle &c, const Line l) {
	Point pr = projection(l, c.p);
	Point e = (l.b - l.a) / abs(l.b - l.a);
	if(eq(distance(l, c.p), c.r)) return {pr, pr};
	double base = sqrt(c.r * c.r - norm(pr - c.p));
	return {pr - e * base, pr + e * base};
}

pair<Point, Point> crosspoint(const Circle &c, const Segment &l) {
	Line aa = Line(l.a, l.b);
	if(intersect(c, l) == 2) return crosspoint(c, aa);
	auto ret = crosspoint(c, aa);
	if(dot(l.a - ret.first, l.b - ret.first) < 0)
		ret.second = ret.first;
	else
		ret.first = ret.second;
	return ret;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E
pair<Point, Point> crosspoint(const Circle &c1, const Circle &c2) {
	Real d = abs(c1.p - c2.p);
	Real a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
	Real t = atan2(c2.p.imag() - c1.p.imag(), c2.p.real() - c1.p.real());
	Point p1 = c1.p + Point(cos(t + a) * c1.r, sin(t + a) * c1.r);
	Point p2 = c1.p + Point(cos(t - a) * c1.r, sin(t - a) * c1.r);
	return {p1, p2};
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F
//  p  c 
pair<Point, Point> tangent(const Circle &c1, const Point &p2) { return crosspoint(c1, Circle(p2, sqrt(norm(c1.p - p2) - c1.r * c1.r))); }

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_G
//  c1, c2 
Lines tangent(Circle c1, Circle c2) {
	Lines ret;
	if(c1.r < c2.r) swap(c1, c2);
	Real g = norm(c1.p - c2.p);
	if(eq(g, 0)) return ret;
	Point u = (c2.p - c1.p) / sqrt(g);
	Point v = rotate(PI * 0.5, u);
	for(int s : {-1, 1}) {
		Real h = (c1.r + s * c2.r) / sqrt(g);
		if(eq(1 - h * h, 0)) {
			ret.emplace_back(c1.p + u * c1.r, c1.p + (u + v) * c1.r);
		} else if(1 - h * h > 0) {
			Point uu = u * h, vv = v * sqrt(1 - h * h);
			ret.emplace_back(c1.p + (uu + vv) * c1.r, c2.p - (uu + vv) * c2.r * s);
			ret.emplace_back(c1.p + (uu - vv) * c1.r, c2.p - (uu - vv) * c2.r * s);
		}
	}
	return ret;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B
// 
bool is_convex(const Polygon &p) {
	int n = (int)p.size();
	for(int i = 0; i < n; i++) {
		if(ccw(p[(i + n - 1) % n], p[i], p[(i + 1) % n]) == -1) return false;
	}
	return true;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
// 
Polygon convex_hull(Polygon &p) {
	int n = (int)p.size(), k = 0;
	if(n <= 2) return p;
	sort(p.begin(), p.end());
	vector<Point> ch(2 * n);
	for(int i = 0; i < n; ch[k++] = p[i++]) {
		while(k >= 2 && cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) < EPS) --k;
	}
	for(int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--]) {
		while(k >= t && cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) < EPS) --k;
	}
	ch.resize(k - 1);
	return ch;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C
// 
enum { OUT, ON, IN };

int contains(const Polygon &Q, const Point &p) {
	bool in = false;
	for(int i = 0; i < Q.size(); i++) {
		Point a = Q[i] - p, b = Q[(i + 1) % Q.size()] - p;
		if(a.imag() > b.imag()) swap(a, b);
		if(a.imag() <= 0 && 0 < b.imag() && cross(a, b) < 0) in = !in;
		if(cross(a, b) == 0 && dot(a, b) <= 0) return ON;
	}
	return in ? IN : OUT;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1033
// 
void merge_segments(vector<Segment> &segs) {
	auto merge_if_able = [](Segment &s1, const Segment &s2) {
		if(abs(cross(s1.b - s1.a, s2.b - s2.a)) > EPS) return false;
		if(ccw(s1.a, s2.a, s1.b) == 1 || ccw(s1.a, s2.a, s1.b) == -1) return false;
		if(ccw(s1.a, s1.b, s2.a) == -2 || ccw(s2.a, s2.b, s1.a) == -2) return false;
		s1 = Segment(min(s1.a, s2.a), max(s1.b, s2.b));
		return true;
	};

	for(int i = 0; i < segs.size(); i++) {
		if(segs[i].b < segs[i].a) swap(segs[i].a, segs[i].b);
	}
	for(int i = 0; i < segs.size(); i++) {
		for(int j = i + 1; j < segs.size(); j++) {
			if(merge_if_able(segs[i], segs[j])) {
				segs[j--] = segs.back(), segs.pop_back();
			}
		}
	}
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1033
// 
// 2
vector<vector<int>> segment_arrangement(vector<Segment> &segs, vector<Point> &ps) {
	vector<vector<int>> g;
	int N = (int)segs.size();
	for(int i = 0; i < N; i++) {
		ps.emplace_back(segs[i].a);
		ps.emplace_back(segs[i].b);
		for(int j = i + 1; j < N; j++) {
			const Point p1 = segs[i].b - segs[i].a;
			const Point p2 = segs[j].b - segs[j].a;
			if(cross(p1, p2) == 0) continue;
			if(intersect(segs[i], segs[j])) {
				ps.emplace_back(crosspoint(segs[i], segs[j]));
			}
		}
	}
	sort(begin(ps), end(ps));
	ps.erase(unique(begin(ps), end(ps)), end(ps));

	int M = (int)ps.size();
	g.resize(M);
	for(int i = 0; i < N; i++) {
		vector<int> vec;
		for(int j = 0; j < M; j++) {
			if(intersect(segs[i], ps[j])) {
				vec.emplace_back(j);
			}
		}
		for(int j = 1; j < vec.size(); j++) {
			g[vec[j - 1]].push_back(vec[j]);
			g[vec[j]].push_back(vec[j - 1]);
		}
	}
	return (g);
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C
// 
//  l.a-l.b 
Polygon convex_cut(const Polygon &U, Line l) {
	Polygon ret;
	for(int i = 0; i < U.size(); i++) {
		Point now = U[i], nxt = U[(i + 1) % U.size()];
		if(ccw(l.a, l.b, now) != -1) ret.push_back(now);
		if(ccw(l.a, l.b, now) * ccw(l.a, l.b, nxt) < 0) {
			ret.push_back(crosspoint(Line(now, nxt), l));
		}
	}
	return (ret);
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A
// 
Real area(const Polygon &p) {
	Real A = 0;
	for(int i = 0; i < p.size(); ++i) {
		A += cross(p[i], p[(i + 1) % p.size()]);
	}
	return A * 0.5;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H
// 
Real area(const Polygon &p, const Circle &c) {
	if(p.size() < 3) return 0.0;
	function<Real(Circle, Point, Point)> cross_area = [&](const Circle &c, const Point &a, const Point &b) {
		Point va = c.p - a, vb = c.p - b;
		Real f = cross(va, vb), ret = 0.0;
		if(eq(f, 0.0)) return ret;
		if(max(abs(va), abs(vb)) < c.r + EPS) return f;
		if(distance(Segment(a, b), c.p) > c.r - EPS) return c.r * c.r * arg(vb * conj(va));
		auto u = crosspoint(c, Segment(a, b));
		vector<Point> tot{a, u.first, u.second, b};
		for(int i = 0; i + 1 < tot.size(); i++) {
			ret += cross_area(c, tot[i], tot[i + 1]);
		}
		return ret;
	};
	Real A = 0;
	for(int i = 0; i < p.size(); i++) {
		A += cross_area(c, p[i], p[(i + 1) % p.size()]);
	}
	return A;
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B
// ()
Real convex_diameter(const Polygon &p) {
	int N = (int)p.size();
	int is = 0, js = 0;
	for(int i = 1; i < N; i++) {
		if(p[i].imag() > p[is].imag()) is = i;
		if(p[i].imag() < p[js].imag()) js = i;
	}
	Real maxdis = norm(p[is] - p[js]);

	int maxi, maxj, i, j;
	i = maxi = is;
	j = maxj = js;
	do {
		if(cross(p[(i + 1) % N] - p[i], p[(j + 1) % N] - p[j]) >= 0) {
			j = (j + 1) % N;
		} else {
			i = (i + 1) % N;
		}
		if(norm(p[i] - p[j]) > maxdis) {
			maxdis = norm(p[i] - p[j]);
			maxi = i;
			maxj = j;
		}
	} while(i != is || j != js);
	return sqrt(maxdis);
}

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A
// 
Real closest_pair(Points ps) {
	if(ps.size() <= 1) throw(0);
	sort(begin(ps), end(ps));

	auto compare_y = [&](const Point &a, const Point &b) { return imag(a) < imag(b); };
	vector<Point> beet(ps.size());
	const Real INF = 1e18;

	function<Real(int, int)> rec = [&](int left, int right) {
		if(right - left <= 1) return INF;
		int mid = (left + right) >> 1;
		auto x = real(ps[mid]);
		auto ret = min(rec(left, mid), rec(mid, right));
		inplace_merge(begin(ps) + left, begin(ps) + mid, begin(ps) + right, compare_y);
		int ptr = 0;
		for(int i = left; i < right; i++) {
			if(abs(real(ps[i]) - x) >= ret) continue;
			for(int j = 0; j < ptr; j++) {
				auto luz = ps[i] - beet[ptr - j - 1];
				if(imag(luz) >= ret) break;
				ret = min(ret, abs(luz));
			}
			beet[ptr++] = ps[i];
		}
		return ret;
	};
	return rec(0, (int)ps.size());
}

#pragma endregion

#pragma endregion

//////////////////  //////////////////////
#pragma region memo

#pragma region update_memo
/// ver12.0
// ilb11
// inversion_number
//()

// lib12
// debug
// Yes,err,etc..
// BIT lower/upper_bound

//
//
///
//class
//(LazyST?)
//Algorithm(Z,KMP)
// wavelet matrix
#pragma endregion

#pragma region programming_memo
// Ctrl+Shift+[
// Ctrl+Shift+]
// Ctrl+k Ctrl+l
// Ctrl+k Ctrl+[
// Ctrl+k Ctrl+]
// Ctrl+k Ctrl+0
// Ctrl+k Ctrl+j
// Ctrl+k Ctrl+11
// Ctrl+k Ctrl+22
// Ctrl+k Ctrl+33
// Ctrl+k Ctrl+8region
// Ctrl+k Ctrl+9region
// Ctrl+k Ctrl+/

// long long int ()
// printf("case3: %lld\n", a);

// C++
// 
// ()

// c char 
// s char *
// d int, short 10
// u unsigned int, unsigned short 10
// o int, short, unsigned int,unsigned short 8
// x int, short, unsigned int,unsigned short 16
// f float 
// e float 
// g float %e %f
// ld long 10
// lu unsinged long 10
// lo long,unsinged long 8
// lf double 
// a double 16
// lld long long
#pragma endregion

#pragma endregion

#pragma endregion

int main() {
	ll t;
	cin >> t;
	vll ans = vin(t);
	rep(i, t) {
		ll k = ans[i];
		ll era = k / 4;
		if(k % 4 > 0) era++;
		rep(j, k - era) { printf("9"); }
		rep(j, era) printf("8");
		printf("\n");
	}
}