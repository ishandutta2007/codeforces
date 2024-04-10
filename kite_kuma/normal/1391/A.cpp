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
long long const dekai = 3e16;
const long double pi = acos(-1);
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int ddx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int ddy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

const int mod = 1000000007;
// const int mod = 998244353;

#pragma endregion

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
int sgn(T x) {	//
	if(x < 0) return -1;
	if(x == 0) return x;
	return 1;
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
					cout << "\n";
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
#pragma endregion

//////////////////  //////////////////////
#pragma region memo

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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// cout << fixed << setprecision(15);
	ll t;
	cin >> t;
	vvll ans(t);
	rep(i, t) {
		ll n;
		cin >> n;
		rep(j, n) { ans[i].push_back(j + 1); }
	}
	rep(i, t) vout(ans[i]);
}