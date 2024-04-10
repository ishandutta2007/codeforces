#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
vector<int> f[1000005];
int kp[1000005];

vector<int> stek;

void dfs(int x) {
	stek.push_back(x);

	if ((int)stek.size() >= k+1) {
		kp[x] = stek[(int)stek.size() - k - 1];
	} else {
		kp[x] = 1;
	}

	for (int y : f[x]) {
		dfs(y);
	}
	stek.pop_back();
}


const int SCC_MAXN = 1000005;
int low[SCC_MAXN], idx[SCC_MAXN], scc_t;
bool instack[SCC_MAXN];
vector<int> sccstack;
vector<int> e[SCC_MAXN];

int komponenta[1000005];
int listova[1000005];
int dp[1000005];
int kkk;

void scc(int x) {
	instack[x] = true;
	sccstack.push_back(x);
	low[x] = idx[x] = scc_t++;
	for (int y : e[x]) {
		if (instack[y]) {
			low[x] = min(low[x], idx[y]);
		} else if (idx[y] == -1) {
			scc(y);
			low[x] = min(low[x], low[y]);
		}
	}
	if (low[x] == idx[x]) {
		vector<int> komp;
		while (1) {
			int z = sccstack.back();
			komp.push_back(z);
			sccstack.pop_back();
			instack[z] = false;
			if (z == x)
				break;
		}

		kkk++;
		for (int i : komp) {
			komponenta[i] = kkk;
			if (f[i].size() == 0)
				listova[kkk]++;
		}
	}
}

struct topo_sort {

	vector<vector<int>> e;
	vector<int> outdeg;
	int n;

	topo_sort(int n) : e(n), outdeg(n, 0), n(n) {}

	void add_edge(int x, int y) {
		e[x].push_back(y);
		outdeg[y]++;
	}

	vector<pair<int, int>> sort() {
		queue<int> q;
		vector<int> red;

		for (int i=0; i<n; i++)
			if (outdeg[i] == 0)
				q.push(i);

		while (q.size()) {
			int x = q.front(); q.pop();
			red.push_back(x);
			for (int y : e[x]) {
				outdeg[y]--;
				if (outdeg[y] == 0)
					q.push(y);
			}
		}

		reverse(red.begin(), red.end());

		vector<pair<int, int>> rez;
		for (int x : red) {
			for (int y : e[x]) {
				rez.push_back({x, y});
			}
		}

		return rez;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=2; i<=n; i++) {
		int y;
		cin >> y;
		f[y].push_back(i);
		e[y].push_back(i);
	}

	dfs(1);
	for (int i=1; i<=n; i++) {
		if (f[i].size() == 0) {
			e[i].push_back(kp[i]);
		}
	}

	fill(idx, idx+n+1, -1);

	for (int i=1; i<=n; i++) {
		if (idx[i] == -1) {
			scc(i);
		}
	}

	topo_sort ts(kkk+1);

	for (int i=1; i<=n; i++)
		for (int j : e[i])
			if (komponenta[i] != komponenta[j]) {
				ts.add_edge(komponenta[i], komponenta[j]);
			}

	auto v = ts.sort();

	reverse(v.begin(), v.end());

	int sol = 0;

	for (int i=1; i<=kkk; i++)
		dp[i] = listova[i];

	for (auto e : v)
		dp[e.second] = max(dp[e.second], listova[e.second] + dp[e.first]);
	
	for (int i=1; i<=kkk; i++)
		sol = max(sol, dp[i]);

	cout << sol << '\n';

}