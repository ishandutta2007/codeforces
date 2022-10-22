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
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vb = vector<bool>;
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
#pragma region vector
//()
// vector 
vector<long long> vin(long long n) {  //n
	vector<long long> v(n);
	for(long long i = 0; i < n; i++) {
		cin >> v[i];
	}
	return v;
}
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
template <class T>
void add(vector<T> &v, T val) {	 //
	for(auto &a : v) a += val;
	return;
}
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
void err() { cout << -1 << endl; }

#pragma endregion
template <class T = long long>
struct edge {
	T len;
	int to;
};
template <class T = long long>
struct graph {	// 0-indexed
	vector<vector<edge<T>>> edges;
	bool directed, weight;
	int ver;

	// constructor
	graph(int vertex, bool direction = 0, bool weigh = 0) : edges(vertex) {
		ver = vertex;
		directed = direction;
		weight = weigh;
		edges.resize(vertex);
	}

	// (0-indexed)
	void update(int from, int to, T len = 1, bool direction = 1) {
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
	void input(int edge_num, int index = 1) {
		rep(i, edge_num) {
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

	//path<vll> O((ver)log(ver)+(edge))
	vector<T> dijkstra(int start) {
		vector<T> ret(ver, (T)dekai);
		pqup<pair<T, int>> p;  //{dist,place}
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
				if(chmin(ret[nextplace], dist + dis)) {
					p.push({ret[nextplace], nextplace});
				}
			}
		}
		return ret;
	}

	// O((ver)*(edge))
	// ret[i] = -dekai;
	vector<T> BellmanFord(int start) {
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
		queue<int> q;
		vector<bool> chk(ver, 0);
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
			int now = q.front();
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
	vector<int> topo_sort() {
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

	pair<pair<int, int>, T> DiameterOfTree() {	//{{},}
		int v1, v2;								// 0v1
		V<T> dis(ver, -1);
		dis[0] = 0;
		queue<int> q;
		q.push(0);
		while(!q.empty()) {
			int now = q.front();
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
			int now = q.front();
			q.pop();
			for(auto &e : edges[now]) {
				if(dis[e.to] != -1) continue;
				dis[e.to] = dis[now] + e.len;
				q.push(e.to);
			}
			if(q.empty()) v2 = now;
		}
		pair<pair<int, int>, T> ans = {{v1, v2}, dis[v2]};
		return ans;
	}

	//
	graph<T> RootToLeaf(int root) {	 // 0-indexed
		graph<T> ret(ver, 1, weight);
		vb chk(ver, 0);
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
		vb chk(ver, 0);
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
		V<edge<T>> ret(ver);
		rep(i, ver) ret[i].to = -1;
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
	VV<T> GraphArray(void) {
		VV<T> ret(ver, V<int>(ver, dekai));
		rep(from, ver) {
			for(auto &e : edges[from]) {
				ret[from][e.to] = e.len;
			}
			ret[from][from] = 0;
		}
		return ret;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// cout << fixed << setprecision(15);
	ll n, m, k;
	cin >> n >> m >> k;
	VV<pll> gra(n);
	rep(i, m) {
		ll f, t, w;
		cin >> f >> t >> w;
		f--;
		t--;
		gra[f].push_back({w, t});
	}
	rep(i, n) { sort(all(gra[i])); }

	std::random_device rnd;	 // 
	std::mt19937 mt(rnd());	 // 
	std::uniform_int_distribution<int> intRand(0, 9923499);	 // 

	vll res(n);
	rep(i, n) { res[i] = intRand(mt); }	 //
	rep(i, n) res[i] = (res[i] * res[i] + 42423) % mod;

	// add
	vll res2(n);
	rep(i, n) res2[i] = (res[i] * res[i] % mod + 24234) % mod;

	ll correct = 1;

	// add
	ll cor2 = 1;

	rep(i, n) {
		(correct *= res[i]) %= mod;
		// add
		cor2 *= res2[i] %= mod;
	}
	vvll hashes(k);
	rep(i, k) hashes[i].assign(i + 1, 1);

	// add
	auto hashes2 = hashes;

	rep(i, n) {
		ll sz = gra[i].size();
		rep(j, sz) {
			ll to = gra[i][j].second;
			(hashes[sz - 1][j] *= res[to]) %= mod;
			// add
			(hashes2[sz - 1][j] *= res2[to]) %= mod;
		}
	}

	vll cal(k, -dekai);
	// add
	vll cal2(k, -1);

	function<long long(long long)> dfs = [&](long long num) {
		if(num == k) {
			// debug(cal);
			ll res = 1;
			// add
			ll res2 = 1;
			rep(i, k) {
				(res *= cal[i]) %= mod;
				// add
				(res2 *= cal2[i]) %= mod;
			}
			if(res == correct /*&& res2 == cor2*/)
				return 1LL;
			else
				return 0LL;
		}
		ll ans = 0;
		rep(i, num + 1) {
			cal[num] = hashes[num][i];
			// add
			cal2[num] = hashes2[num][i];
			ans += dfs(num + 1);
		}
		return ans;
	};
	cout << dfs(0) << ednl;
	// debug(res[0] * res[1] * res[2] * res[3] % mod);
	// debug(hashes[0][0] * hashes[1][0] * hashes[2][2] % mod);
	// debug(correct);
	// debug(res);
	// debug(hashes);
}