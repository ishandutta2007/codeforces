#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[500005];
pair<int, int> g[500005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> k >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
	for (int i=1; i<n; i++)
		g[i-1] = {a[i] - a[i-1], i-1};
	sort(g, g+n-1);
	int m = min(n-1, 3*k);
	sort(g, g+m, [](auto p, auto q) {
		return p.second < q.second;
	});

	int last = -10;
	vector<int> ol0(k+1, 1e9);
	vector<int> ol1(k+1, 1e9);
	ol0[0] = 0;
	for (int j=0; j<m; j++) {
		auto [v, p] = g[j];
		vector<int> nu0(k+1, 1e9), nu1(k+1, 1e9);
		for (int i=0; i<k; i++) {
			nu1[i+1] = min(nu1[i+1], ol0[i] + v);
			if (p - last > 1)
				nu1[i+1] = min(nu1[i+1], ol1[i] + v);
		}
		for (int i=0; i<=k; i++)
			nu0[i] = min(ol0[i], ol1[i]);
		swap(ol0, nu0);
		swap(ol1, nu1);
		last = p;
	}
	cout << min(ol0[k], ol1[k]) << '\n';
}