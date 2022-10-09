#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

static int n, m, d;
static basic_string<int> e[100005];
static string s;

static const int SCC_MAXN = 5000005;
static int* low, *idx, *komp;
static int scc_t, kkk;
static int kompsz[SCC_MAXN];
static bool* instack;
static vector<int> sccstack;
static set<int> cities;

static int scc_z;

static void scc(int x) {
	instack[x] = true;
	sccstack.push_back(x);
	low[x] = idx[x] = scc_t++;
	for (int y : e[x/d]) {
		y = y*d+(x+1)%d;
		if (instack[y]) {
			low[x] = min(low[x], idx[y]);
		} else if (idx[y] == -1) {
			scc(y);
			low[x] = min(low[x], low[y]);
		}
	}
	if (low[x] == idx[x]) {
		cities.clear();
		while (1) {
			scc_z = sccstack.back();
			komp[scc_z] = kkk;
			if (s[scc_z] == '1')
				cities.insert(scc_z/d);
			sccstack.pop_back();
			instack[scc_z] = false;
			if (scc_z == x)
				break;
		}
		kompsz[kkk] = cities.size();
		kkk++;
	}
}

static vector<int> topo_e[SCC_MAXN];
static basic_string<int> topo_q;
static int topo_indeg[SCC_MAXN];
static int dp[SCC_MAXN];

static inline void topo_add_edge(int x, int y) {
	topo_e[x].push_back(y);
	topo_indeg[y]++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> d;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		e[u-1] += v-1;
	}
	for (int i=0; i<n; i++) {
		string ss;
		cin >> ss;
		s += ss;
	}

	low = new int[n*d];
	idx = new int[n*d];
	komp = new int[n*d];
	instack = new bool[n*d];
	sccstack.reserve(n*d);

	fill(low, low+n*d, 0);
	fill(idx, idx+n*d, -1);
	fill(instack, instack+n*d, false);

	scc(0);

	delete[] low;
	delete[] instack;

	for (int i=0; i<n*d; i++) {
		if (idx[i] == -1)
			continue;
		int x = i/d;
		int t = i%d;
		int t2 = t == d-1 ? 0 : t+1;
		for (int y : e[x]) {
			int j = y*d + t2;
			if (komp[i] != komp[j]) {
				topo_add_edge(komp[i], komp[j]);
			}
		}
	}

	int root_komp = komp[0];

	delete[] komp;
	delete[] idx;

	topo_q.reserve(n*d);
	for (int i=0; i<kkk; i++)
		if (topo_indeg[i] == 0)
			topo_q += i;
	size_t qs = 0;
	int sol = 0;
	memset(dp, 128, sizeof(dp));
	dp[root_komp] = 0;
	while (qs != topo_q.size()) {
		int i = topo_q[qs++];
		dp[i] += kompsz[i];
		sol = max(sol, dp[i]);
		for (int j : topo_e[i]) {
			dp[j] = max(dp[j], dp[i]);
			if (!--topo_indeg[j]) {
				topo_q += j;
			}
		}
	}
	cout << sol << '\n';
}