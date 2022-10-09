#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, d;
int c[30005];

namespace umap {
	unordered_map<int, int> dp[30005];

	int solve(int x, int l) {
		if (x > 30000) return 0;
		if (dp[x].count(l))
			return dp[x][l];

		int v = 0;
		if (l > 1)
			v = solve(x+l-1, l-1);
		v = max(v, solve(x+l, l));
		v = max(v, solve(x+l+1, l+1));
		return dp[x][l] = v + c[x];
	}
}

namespace arrays {
	int dp[30005][1005];

	int solve(int x, int l) {
		if (x > 30000) return 0;
		if (dp[x][l] != -1)
			return dp[x][l];

		int v = 0;
		if (l > 1)
			v = solve(x+l-1, l-1);
		v = max(v, solve(x+l, l));
		v = max(v, solve(x+l+1, l+1));
		return dp[x][l] = v + c[x];
	}
}	

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> d;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		c[x]++;
	}

	if (d <= 500) {
		memset(arrays::dp, 255, sizeof(arrays::dp));
		cout << arrays::solve(d, d) << '\n';
	} else {
		cout << umap::solve(d, d) << '\n';
	}
}