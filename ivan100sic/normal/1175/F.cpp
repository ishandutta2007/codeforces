#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
set<pair<int, int>> sol;
int a[300005];
basic_string<int> e[300005];
int cutoff[300005], seen[300005];
int mx[300005][19];

int sparse(int l, int r) {
	r++;
	int w2 = 31 - __builtin_clz(r-l);
	return max(mx[l][w2], mx[r-(1<<w2)][w2]);
}

bool is_perm(int l, int r) {
	if (l < 1 || r > n || l > r)
		return false;
	return sparse(l, r) == r-l+1 && cutoff[r] < l;
}

void solve(int l, int r, int x) {
	int z = 0;
	for (int i=x; i<=r; i++) {
		z = max(z, a[i]);
		if (is_perm(i-z+1, i))
			sol.insert({i-z+1, i});
	}
	z = 0;
	for (int i=x; i>=l; i--) {
		z = max(z, a[i]);
		if (is_perm(i, i+z-1))
			sol.insert({i, i+z-1});
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		e[a[i]] += i;
		mx[i][0] = a[i];
	}

	for (int i=1; i<=n; i++) {
		cutoff[i] = max(cutoff[i-1], seen[a[i]]);
		seen[a[i]] = i;
	}

	for (int i=1; i<19; i++) {
		for (int j=1, k=1+(1<<(i-1)); j<=n; j++, k++) {
			mx[j][i] = max(mx[j][i-1], k <= n ? mx[k][i-1] : 0);
		}
	}

	for (int i=0; i<(int)e[1].size(); i++) {
		int l = i == 0 ? 1 : e[1][i-1] + 1;
		int r = i == (int)e[1].size() - 1 ? n : e[1][i+1] - 1;
		int x = e[1][i];
		solve(l, r, x);
	}

	cout << sol.size() << '\n';
}