



#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

//#define FAST_ALLOCATOR_MEMORY 1e8
#undef LOCAL
//#include "optimization.h"

vector< vector<pair<long long, long long> > > g;
vector<long long> ans;
vector<long long> c;
vector<bool> used;
vector<long long> dp;
vector<long long> col;
vector<long long> p;

long long val = 0;
long long pos = 0;
long long pos2 = 0;

void doit(long long v) {
	used[v] = 1;
	for (auto i : g[v]) {
		if (!used[i.first]) {
			p[i.first] = v;
			doit(i.first);
			ans[i.second] = c[i.first] - dp[i.first];
			dp[i.first] += ans[i.second];
			dp[v] += ans[i.second];
		}
	}
	
}

bool dfs(long long v) {
	used[v] = 1;
	
	for (auto i : g[v]) {
		if (!used[i.first]) {
			col[i.first] = col[v] ^ 1;
			if (dfs(i.first))
				return 1;
		}
		else {
			if (col[i.first] != col[v] ^ 1) {
				val = i.second;
				pos = i.first;
				pos2 = v;
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	long long n, m;
	cin >> n >> m;
	ans.resize(m);
	g.resize(n);
	c.resize(n);
	dp.resize(n);
	p.resize(n);
	for (long long i = 0; i < n; i++)
		cin >> c[i];
	for (long long i = 0; i < m; i++) {
		long long a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back({ b, i });
		g[b].push_back({ a, i });
	}

	used.assign(n, 0);
	doit(0);
	if (dp[0] == c[0]) {
		cout << "YES\n";
		for (long long i : ans)
			cout << i << '\n';
		return 0;
	}

	used.assign(n, 0);
	col.resize(n);
	col[0] = 0;
	if (!dfs(0)) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	vector<long long> to;
	long long now = pos;
	while (now != 0) {
		to.push_back(now);
		now = p[now];
	}
	reverse(to.begin(), to.end());
	now = 0;
	for (long long i = 0; i < to.size(); i++) {
		for (auto j : g[now]) {
			if (j.first == to[i]) {
				long long up = c[now] - dp[now];
				ans[j.second] += up;
				dp[now] += up;
				dp[j.first] += up;
			}
		}
		now = to[i];
	}
	
	if ((c[pos] - dp[pos]) % 2 != 0) {
		return -1;
	}

	long long up = (c[pos] - dp[pos]) / 2;
	ans[val] += up;
	dp[pos] += up;
	dp[pos2] += up;

	to.clear();
	now = pos2;
	while (now != pos) {
		to.push_back(now);
		now = p[now];
	}

	reverse(to.begin(), to.end());
	now = pos;
	for (long long i = 0; i < to.size(); i++) {
		for (auto j : g[now]) {
			if (j.first == to[i]) {
				long long up = c[now] - dp[now];
				ans[j.second] += up;
				dp[now] += up;
				dp[j.first] += up;
			}
		}
		now = to[i];
	}
	for (long long i : ans)
		cout << i << '\n';
	return 0;
}