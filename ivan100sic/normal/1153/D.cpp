#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int p[300005], sz[300005], t[300005];
basic_string<int> e[300005];

int dfs(int x) {
	if (e[x].size() == 0)
		return 0;

	basic_string<int> a, b;
	for (int y : e[x]) {
		auto p = dfs(y);
		a += p;
		b += sz[y] - p;
	}

	if (t[x] == 1) {
		int me = *min_element(b.begin(), b.end());
		return sz[x] - me;
	} else {
		return accumulate(a.begin(), a.end(), 0);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> t[i];
	for (int i=2; i<=n; i++) {
		cin >> p[i];
		e[p[i]] += i;
	}

	for (int i=1; i<=n; i++)
		if (e[i].size() == 0)
			sz[i] = 1;
	for (int i=n; i>=2; i--)
		sz[p[i]] += sz[i];

	cout << dfs(1) + 1 << "\n";
}