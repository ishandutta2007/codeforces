// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, c[3], m;
basic_string<int> e[5005];

struct descr {
	vector<int> u, v;
};

vector<descr> dataa;
descr curr;

int col[5005];

void no() {
	cout << "NO\n";
	exit(0);
}

void dfs(int x, int cr) {
	col[x] = cr;
	(cr == 1 ? curr.u : curr.v).push_back(x);

	for (int y : e[x]) {
		if (col[y] == 0) {
			dfs(y, 3-cr);
		} else if (col[y] == col[x]) {
			no();
		}
	}
}

//   first i, excl k
char dp[5005][5005];

int is2[5005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m;
	cin >> c[0] >> c[1] >> c[2];
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	for (int i=1; i<=n; i++) {
		if (col[i] == 0) {
			curr = {};
			dfs(i, 1);
			dataa.push_back(curr);
		}
	}

	int g = dataa.size();
	dp[0][0] = 1;
	for (int i=0; i<g; i++) {
		for (int j=0; j<=n; j++) {
			if (dp[i][j]) {
				dp[i+1][j + dataa[i].u.size()] = 1;
				dp[i+1][j + dataa[i].v.size()] = 2;
			}
		}
	}

	if (!dp[g][c[1]]) {
		no();
	}

	int j = c[1];

	for (int i=g; i>0; i--) {
		if (dp[i][j] == 1) {
			for (int x : dataa[i-1].u)
				is2[x] = 1;
			j -= dataa[i-1].u.size();
		} else {
			for (int x : dataa[i-1].v)
				is2[x] = 1;
			j -= dataa[i-1].v.size();
		}
	}

	cout << "YES\n";

	for (int i=1; i<=n; i++) {
		if (is2[i]) {
			cout << 2;
		} else if (c[0]) {
			cout << 1;
			c[0]--;
		} else {
			cout << 3;
		}
	}

	cout << '\n';


}