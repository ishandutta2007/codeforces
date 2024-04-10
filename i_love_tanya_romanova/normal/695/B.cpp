//#pragma comment(linker, "/STACK:16777216")

#include <fstream>
#include <iostream>
#include <bitset>
#include <cstring>
#include <string>
#include <complex>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <ctime>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

using ll = long long;
using pii = pair<int, int>;
template<class T1, class T2, class T3> struct triple {
	T1 x; T2 y; T3 z;
};
using tri = triple<int, int, int>;
using trll = triple<ll, ll, ll>;
template<class T1, class T2, class T3>
bool operator<(const triple<T1, T2, T3>& t1, const triple<T1, T2, T3>& t2) {
	return t1.x < t2.x || (t1.x == t2.x && (t1.y < t2.y || t1.y == t2.y && t1.z < t2.z));
}

#define eps 1e-9
#define bs 1000000007
const int mod = 1000000007;
const int INF = 1000111000;
const ll LLINF = 1000111000111000111LL;
const double PI = acos(-1.0);
#define bsize 256

#define all(v) (v).begin(), (v).end()
#define FI(n) for (int i = 0; i < n; ++i)
#define FJ(n) for (int j = 0; j < n; ++j)
#define FK(n) for (int k = 0; k < n; ++k)
#define FREIN(file) freopen(file, "rt", stdin)
#define FREOUT(file) freopen(file, "wt", stdout)
#define sqr(x) ((x)*(x))

#define DB(n) cerr<<#n<<" = "<<(n)<<" "
#define DBN(n) cerr<<#n<<" = "<<(n)<<"\n"

int gcd(int x, int y) { while (y) { x %= y, swap(x, y); } return x; }
ll gcd(ll x, ll y) { while (y) { x %= y, swap(x, y); } return x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
ll powmod(ll x, ll n, const int mod) {
	ll res = 1; while (n)
	{
		if (n & 1) res = res * x % mod; n /= 2; x = x * x % mod;
	} return res;
}
#define checkbit(mask, bit) ((mask>>bit)&1)

const int N = 50000;

int n, m, s, t;
int a[N];
int b[N];
vector<int> g[N];
int used[N];
int ans;
vector<int> ans_vec;
int par[N];

int get_other(int v, int id)
{
	if (a[id] == v)
		return b[id];
	return a[id];
}

void dfs_trace(int v)
{
	for (int i = 0; i < g[v].size(); i++)
	{
		int id = g[v][i];
		int other = get_other(v, id);
		if (used[other])
			continue;
		used[other] = 1;
		par[other] = id;
		dfs_trace(other);
	}
}

void trace(int v)
{
	for (int i = 1; i <= n; i++)
		used[v] = 0;
	used[v] = 1;
	dfs_trace(v);
}

vector<int> get_route(int v)
{
	vector<int> route;
	while (v != s)
	{
		route.push_back(par[v]);
		v = get_other(v, par[v]);
	}
	return route;
}

int BANNED;
int is_bridge[N];
int timer;
int c[N];

int tin[N], fup[N];

void BRIDGE(int id)
{
	is_bridge[id] = 1;
}

int reach[N];

void dfs(int v,int edge_id)
{
	++timer;
	if (v == t)
		reach[v] = 1;
	tin[v] = timer;
	fup[v] = timer;
	used[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
	{
		int id = g[v][i];
		if (BANNED==id)
			continue;
		if (id == edge_id)
			continue;
		int to = get_other(v, id);
		if (used[to])
		{
			fup[v] = min(fup[v], fup[to]);
		}
		else
		{
			dfs(to,id);
			reach[v] |= reach[to];
			if (fup[to] > tin[v]&&reach[to]==1)
			{
				BRIDGE(id);
			}
			fup[v] = min(fup[v], fup[to]);
		}
	}
}

pair<int, int> try_solve(int edge_id)
{
	BANNED = edge_id;
	for (int i = 1; i <= n; i++)
	{
		used[i] = 0;
		reach[i] = 0;
	}

	for (int i = 1; i <= m; i++)
		is_bridge[i] = 0;
	timer = 0;
	dfs(s,-1);
	int ret = ans + 1;
	int ret_id = -1;
	if (used[t] == 0)
	{
		return make_pair(c[edge_id], -1);
	}
	for (int i = 1; i <= m; i++)
	{
		if (is_bridge[i])
		{
			int cost = c[i] + c[edge_id];
			if (cost < ret)
			{
				ret = cost;
				ret_id = i;
			}
		}
	}
	return make_pair(ret, ret_id);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	cin >> s >> t;

	for (int i = 1; i <= m; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
		g[a[i]].push_back(i);
		g[b[i]].push_back(i);
	}


	trace(s);
	if (used[t] == 0)
	{
		cout << 0 << endl;
		cout << 0 << endl;
		return 0;
	}

	vector<int> path = get_route(t);

	ans = 2e9 + 1e7;
	for (int i = 0; i < path.size(); i++)
	{
		pair<int,int> here=try_solve(path[i]);
		if (here.first < ans)
		{
			ans = here.first;
			ans_vec.clear();
			ans_vec.push_back(path[i]);
			ans_vec.push_back(here.second);
		}
	}

	while (ans_vec.size() > 1 && ans_vec.back() == -1)
		ans_vec.pop_back();

	if (ans > 2e9 + 1e6)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << ans << endl;
		cout << ans_vec.size() << endl;
		for (int i = 0; i < ans_vec.size(); i++)
		{
			if (i)
				cout << " ";
			cout << ans_vec[i];
		}
		cout << endl;
	}

	return 0;
}
/**/