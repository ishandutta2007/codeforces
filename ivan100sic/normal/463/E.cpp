#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int f[2000005];

basic_string<int> faktori(int x) {
	basic_string<int> w;
	while (x > 1) {
		int p = f[x];
		w += p;
		while (x % p == 0)
			x /= p;
	}
	return w;
}

int n, q;
basic_string<int> a[100005], e[100005];

basic_string<int> jobs[100005];
int T, ans[100005];

int naj[2000005];
int stek[100005];

void dfs(int x, int p, int dub) {
	stek[dub] = x;
	int odg = -1;
	for (int q : a[x])
		if (naj[q] != 0)
			odg = max(odg, naj[q]);
	if (odg != -1)
		odg = stek[odg];

	for (int y : jobs[x])
		ans[y] = odg;

	basic_string<pair<int, int>> staro;
	for (int q : a[x]) {
		staro += {q, naj[q]};
		naj[q] = dub;
	}

	for (int y : e[x])
		if (y != p)
			dfs(y, x, dub+1);

	while (staro.size()) {
		auto [q, nq] = staro.back();
		staro.pop_back();
		naj[q] = nq;
	}
}

void operi() {
	dfs(1, 1, 1);
	for (int i=0; i<T; i++)
		cout << ans[i] << '\n';
	T = 0;
	for (int i=1; i<=n; i++)
		jobs[i] = {};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	iota(f, f+2000005, 0);
	for (int i=2; i<2000005; i++)
		for (int j=2*i; j<2000005; j+=i)
			f[j] = min(f[j], i);

	cin >> n >> q;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		a[i] = faktori(x);
	}

	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	while (q--) {
		int t, v, w;
		cin >> t >> v;
		if (t == 2) {
			// operi sve
			operi();
			cin >> w;
			a[v] = faktori(w);
		} else {
			jobs[v] += T++;
		}
	}
	operi();
}