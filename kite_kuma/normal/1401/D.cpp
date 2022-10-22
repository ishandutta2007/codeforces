#include <bits/stdc++.h>
using namespace std;

#pragma region macros_and_aliases

#define rep(i, n) for(long long i = 0; i < (n); i++)
#define rrep(i, n) for(long long i = (n)-1; i > -1; i--)
#define Rep(i, m, n) for(long long i = (m); i < (n); i++)
#define rRep(i, m, n) for(long long i = (n)-1; i >= (m); i--)
#define REP(i, m, n, p) for(long long i = m; i < n; i += p)
#define foa(s, v) for(auto &s : v)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pq priority_queue
#define bcnt(n) __builtin_popcountll(n)
#define endk endl
#define ednl endl
#define enld endl

using ll = long long;
using ld = long double;
using vb = vector<bool>;
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

#define debug(var)              \
	std::cout << #var << " : "; \
	view(var)
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
	cout << "\n";
	for(const auto &v : vv) {
		view(v);
	}
}

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
	os << p.first << " " << p.second;
	return os;
}
template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
	is >> p.first >> p.second;
	return is;
}
#pragma endregion

#pragma region constants

long long const limLL = 9223372036854775807;  // POW(2,63)-1 ~ 9.22e18
long long const dekai = 3e16;
const long double pi = acos(-1);
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

void Yes(bool f = 1) { cout << (f ? "Yes" : "No") << "\n"; }
void No() { cout << "No\n"; }
void YES(bool f = 1) { cout << (f ? "YES" : "NO") << "\n"; }
void NO() { cout << "NO\n"; }
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

template <class T = long long>
struct edge {
	T len;
	int from;
	int to;
	bool operator<(const edge a) const {
		if(len != a.len) return len < a.len;
		if(from != a.from) return from < a.from;
		return to < a.to;
	}
	bool operator>(const edge a) const {
		if(len != a.len) return len > a.len;
		if(from != a.from) return from > a.from;
		return to > a.to;
	}
};
template <class T = long long>
struct graph {	// 0-indexed
	T const INF = numeric_limits<T>::max() / 3;
	vector<vector<edge<T>>> edges;
	bool directed, weight;
	int ver;

	// constructor
	graph() = default;
	graph(int vertex, bool direction = 0, bool weigh = 0) : edges(vertex) {
		ver = vertex;
		directed = direction;
		weight = weigh;
		edges.resize(vertex);
	}

	// (0-indexed)
	void update(int from, int to, T len = 1, bool direction = 1) {
		edge<T> e;
		e.len = len;
		e.from = from;
		e.to = to;
		edges[from].push_back(e);
		if(!direction) {
			swap(e.to, e.from);
			edges[to].push_back(e);
		}
	}

	// (1-indexed)
	void input(int edge_num, int index = 1) {
		for(int i = 0; i < edge_num; i++) {
			int a;
			int b;
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

	// 1 (INF)
	vector<T> bfs(int start) {
		// https://atcoder.jp/contests/abc007/submissions/me
		vector<T> ret(ver, INF);
		queue<int> q;
		q.push(start);
		ret[start] = 0;
		while(!q.empty()) {
			int now = q.front();
			q.pop();
			for(auto &e : edges[now]) {
				if(ret[e.to] != INF) continue;
				q.push(e.to);
				ret[e.to] = ret[now] + 1;
			}
		}
		return ret;
	}

	//path<vll> O((ver)log(ver)+(edge))
	vector<T> dijkstra(int start) {
		vector<T> ret(ver, (T)INF);
		// pqup<pair<T, int>> p;														   //{dist,place}
		priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> p;  //{dist,place}
		p.push({0, start});
		ret[start] = 0;

		while(!p.empty()) {
			T dist = p.top().first;
			int place = p.top().second;
			p.pop();
			if(ret[place] < dist) continue;
			for(auto &next : edges[place]) {
				int nextplace = next.to;
				T dis = next.len;
				if(ret[nextplace] > dist + dis) {
					ret[nextplace] = dist + dis;
					p.push({ret[nextplace], nextplace});
				}
			}
		}
		return ret;
	}

	// O((ver)*(edge))
	// ret[i] = INF;
	// ret[i] = -INF;
	vector<T> BellmanFord(int start) {
		// https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B
		vector<T> ret(ver, INF);
		ret[start] = 0;
		for(int loop = 0; loop < ver - 1; loop++) {
			for(int v = 0; v < ver; v++) {
				if(ret[v] == INF) continue;
				for(auto &e : edges[v]) {
					ret[e.to] = min(ret[e.to], ret[v] + e.len);
				}
			}
		}

		//
		queue<int> q;
		vector<bool> chk(ver, 0);
		for(int v = 0; v < ver; v++) {
			if(ret[v] == INF) continue;
			for(auto &e : edges[v]) {
				if(ret[e.to] > ret[v] + e.len) {
					ret[e.to] = ret[v] + e.len;
					if(!chk[e.to]) {
						q.push(e.to);
						chk[e.to] = 1;
					}
				}
			}
		}
		while(!q.empty()) {
			int now = q.front();
			q.pop();
			for(auto &e : edges[now]) {
				if(!chk[e.to]) {
					chk[e.to] = 1;
					q.push(e.to);
				}
			}
		}
		for(int i = 0; i < ver; i++)
			if(chk[i]) ret[i] = -INF;

		return ret;
	}

	//
	//ver
	vector<int> topo_sort() {
		// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_A
		// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B
		assert(directed);
		vector<int> num_input(ver);
		// 
		for(int i = 0; i < ver; i++) {
			for(auto e : edges[i]) {
				num_input[e.to]++;
			}
		}
		// 0queue
		queue<int> que;
		for(int i = 0; i < ver; i++) {
			if(num_input[i] == 0) {
				que.push(i);
			}
		}
		vector<int> ans;
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

	//{{},}
	pair<pair<int, int>, T> DiameterOfTree(bool weigh = true) {
		// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_A
		vector<T> vec;
		vec = weigh ? dijkstra(0) : bfs(0);
		int v1 = -1;
		T dia = -1;
		for(int i = 0; i < ver; i++)
			if((dia < vec[i])) {
				dia = vec[i];
				v1 = i;
			}

		vec = weigh ? dijkstra(v1) : bfs(v1);
		dia = -1;
		int v2 = -1;
		for(int i = 0; i < ver; i++)
			if((dia < vec[i])) {
				v2 = i;
				dia = vec[i];
			}

		pair<pair<int, int>, T> ans = {{v1, v2}, dia};
		return ans;
	}

	//
	graph<T> RootToLeaf(int root) {	 // 0-indexed
		graph<T> ret(ver, 1, weight);
		vector<bool> chk(ver, 0);
		chk[root] = 1;
		function<void(int)> dfs = [&](int now) {
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
	graph<T> LeafToRoot(int root) {	 // 0-indexed
		graph<T> ret(ver, 1, weight);
		vector<bool> chk(ver, 0);
		chk[root] = 1;
		function<void(int)> dfs = [&](int now) {
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
	vector<int> par(int root) {	 // 0-indexed
		vector<int> ret(ver, -1);
		ret[root] = root;  // rootroot
		function<void(int)> dfs = [&](int now) {
			for(auto &e : edges[now]) {
				if(ret[e.to] != -1) continue;
				ret[e.to] = now;
				dfs(e.to);
			}
		};
		dfs(root);
		return ret;
	}
	vector<edge<T>> ParentAndDistance(int root) {  // 0-indexed
		vector<edge<T>> ret(ver);
		for(int i = 0; i < ver; i++) ret[i].to = -1;
		ret[root].to = root;  // rootroot
		ret[root].len = 0;	  // root0
		function<void(int)> dfs = [&](int now) {
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
	vector<vector<T>> GraphArray(void) {
		vector<vector<T>> ret(ver, vector<T>(ver, INF));
		for(int from = 0; from < ver; from++) {
			for(auto &e : edges[from]) {
				ret[from][e.to] = e.len;
			}
			ret[from][from] = 0;
		}
		return ret;
	}

	graph<T> Prim(int start = 0) {
		// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_A
		graph<T> ret(ver, 0, 1);
		priority_queue<edge<T>, vector<edge<T>>, greater<edge<T>>> p;
		for(auto &e : edges[start]) {
			p.push(e);
		}
		vector<bool> chk(ver, 0);
		chk[start] = 1;
		while(!p.empty()) {
			auto ed = p.top();
			p.pop();
			if(chk[ed.to]) continue;
			chk[ed.to] = 1;
			ret.update(ed.from, ed.to, ed.len);
			for(auto &e : edges[ed.to]) {
				p.push(e);
			}
		}
		return ret;
	}

	//
	vector<T> height(int start = 0) {
		// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_B
		vector<T> fir(ver, -1), sec(ver, -1);
		function<T(int, int)> dfs = [&](int now, int par) {
			T f = 0, s = 0;	 // startnow12
			for(auto &e : edges[now]) {
				if(e.to == par) continue;
				s = max(s, dfs(e.to, now) + e.len);
				if(f < s) swap(f, s);
			}
			sec[now] = s;
			return fir[now] = f;
		};
		dfs(start, -1);
		function<void(int, int, T, T, T)> sol = [&](int now, int par, T parf, T pars, T parlen) {
			if(fir[now] + parlen == parf) parf = pars;
			sec[now] = max(sec[now], parf + parlen);
			if(fir[now] < sec[now]) swap(fir[now], sec[now]);
			for(auto &e : edges[now]) {
				if(e.to == par) continue;
				sol(e.to, now, fir[now], sec[now], e.len);
			}
			return;
		};
		sol(start, -1, -1, -1, -1);
		return fir;
	}

	//DP
	//
	// std::function
	template <class U>
	vector<U> zenhoui(function<U(U, U)> f, function<U(U)> g, U unit, int root = 0) {
		auto tr = RootToLeaf(root);
		vector<vector<U>> v(ver);
		vector<U> ret(ver);	 //

		function<U(int)> dfs = [&](int now) {
			U res = unit;
			vector<U> vec;
			for(auto &e : tr.edges[now]) {
				U k = dfs(e.to);
				vec.push_back(k);
				res = f(res, k);
			}
			v[now] = vec;
			return g(res);
		};
		dfs(root);

		function<void(int, U)> dfs2 = [&](int now, U ans_par) {
			int sz = v[now].size();
			vector<U> mae(sz + 1), rev(sz + 1);
			mae[0] = rev[sz] = unit;
			for(int i = 0; i < sz; i++) mae[i + 1] = f(mae[i], v[now][i]);
			for(int i = sz - 1; i >= 0; i--) rev[i] = f(rev[i + 1], v[now][i]);
			for(int i = 0; i < sz; i++) {
				auto nxtans = f(ans_par, f(mae[i], rev[i + 1]));
				dfs2(tr.edges[now][i].to, g(nxtans));
			}
			ret[now] = f(ans_par, mae[sz]);
			return;
		};
		dfs2(root, unit);

		return ret;
	}

	// HL
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// cout << fixed << setprecision(15);
	long long t;
	cin >> t;
	vector<mint> ans(t);
	for(long long i = 0; i < t; i++) {
		mint res = 0;
		ll n;
		cin >> n;
		graph<> g(n);
		g.input(n - 1);
		ll m;
		cin >> m;
		vll pp = vin(m);
		sort(rall(pp));
		V<mint> p(n - 1, 1);
		if(m > n - 1) {
			rep(j, m - (n - 1) + 1) { p[0] *= pp[j]; }
			Rep(j, 1, n - 1) { p[n - 1 - j] = pp[m - j]; }
		} else {
			rep(j, m) { p[j] = pp[j]; }
		}
		//debug(p);

		// rep(i, m) { p[m-1-i] = pp[i]; }
		// if(m > n - 1) {
		// 	Rep(i, n - 1, m) { p[0] *= pp[i]; }
		// 	m = n - 1;
		// }

		// function<ll(ll, ll)> add = [](ll a, ll b) { return a + b; };
		// function<ll(ll)> up = [](ll a) { return a + 1; };
		// vll v = g.zenhoui(add, up, 0LL, 0);
		vll v(n);
		auto tr = g.RootToLeaf(0);

		function<ll(ll)> dfs = [&](ll now) {
			ll res = 0;
			foa(e, tr.edges[now]) { res += dfs(e.to); }
			return v[now] = res + 1;
		};
		dfs(0);
		// debug(v);

		rep(i, n) { v[i] = min(v[i], n - v[i]); }
		sort(rall(v));
		// debug(v);
		// debug(p);
		rep(j, n - 1) {
			mint ad = p[j] * v[j] * (n - v[j]);
			res += ad;
			// debug(ad);
		}

		ans[i] = res;
	}
	for(long long i = 0; i < t; i++) {
		cout << ans[i] << endl;
	}
}