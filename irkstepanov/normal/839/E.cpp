#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

bool bit(int mask, int pos) {
	return (mask >> pos) & 1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");
	//freopen("input.txt", "r", stdin);
	//ofstream cout("output.txt");

	int n;
	cin >> n;

	ld k;
	cin >> k;

	vector<vector<int> > m(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> m[i][j];
		}
	}

	int a = n / 2;
	vector<int> adj(a, 0);
	for (int i = 0; i < a; ++i) {
		for (int j = a; j < n; ++j) {
			if (m[i][j]) {
				adj[i] += (1 << (j - a));
			}
		}
	}
	vector<char> clique(1 << a);
	clique[0] = true;
	vector<int> to(1 << a);
	int b = n - a;
	to[0] = (1 << b) - 1;
	
	int oldest = -1;

	for (int mask = 1; mask < (1 << a); ++mask) {
		if (!(mask & (mask - 1))) {
			++oldest;
		}
		if (mask == (1 << oldest)) {
			clique[mask] = true;
			to[mask] = adj[oldest];
			continue;
		}
		clique[mask] = true;
		for (int i = 0; i < oldest; ++i) {
			if (bit(mask, i) && !m[oldest][i]) {
				clique[mask] = false;
				break;
			}
		}
		if (!clique[mask ^ (1 << oldest)]) {
			clique[mask] = false;
		}
		if (!clique[mask]) {
			continue;
		}
		to[mask] = (to[mask ^ (1 << oldest)] & adj[oldest]);
	}

	vector<char> cliqueRg(1 << b);
	oldest = -1;
	for (int mask = 1; mask < (1 << b); ++mask) {
		if (!(mask & (mask - 1))) {
			++oldest;
		}
		if (mask == (1 << oldest)) {
			cliqueRg[mask] = true;
			continue;
		}
		cliqueRg[mask] = true;
		for (int i = 0; i < oldest; ++i) {
			if (bit(mask, i) && !m[oldest + a][i + a]) {
				cliqueRg[mask] = false;
				break;
			}
		}
		if (!cliqueRg[mask ^ (1 << oldest)]) {
			cliqueRg[mask] = false;
		}
	}

	vector<int> best(1 << b);
	best[0] = 0;
	for (int mask = 1; mask < (1 << b); ++mask) {
		if (cliqueRg[mask]) {
			best[mask] = __builtin_popcount(mask);
		}
		for (int i = 0; i < b; ++i) {
			if (bit(mask, i)) {
				best[mask] = max(best[mask], best[mask ^ (1 << i)]);
			}
		}
	}


	int ans = 0;
	for (int mask = 0; mask < (1 << a); ++mask) {
		if (!clique[mask]) {
			continue;
		}
		ans = max(ans, __builtin_popcount(mask) + best[to[mask]]);
	}

	if (ans == 0) {
		cout << "0\n";
		return 0;
	}

	ld res = k * k;
	res *= (ans - 1);
	res /= (2 * ans);

	cout << fixed;
	cout.precision(12);
	cout << res << "\n";

}