#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int p[200005], q[200005], r[200005], z[200005], v[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++)
		cin >> p[i];
	for (int i=1; i<=n; i++)
		cin >> q[i];
	for (int i=1; i<=n; i++)
		r[p[i]] = i;
	for (int i=1; i<n; i++) {
		int u = r[q[i]];
		int v = r[q[i+1]];
		if (u > v) {
			z[v]++;
			z[u]--;
		}
	}
	v[1] = 1;
	for (int i=1, w=0; i<n; i++) {
		w += z[i];
		if (w > 0) {
			v[i+1] = v[i];
		} else {
			v[i+1] = v[i] + 1;
		}
	}
	if (v[n] < k) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		string s(n, 0);
		for (int i=1; i<=n; i++)
			s[p[i]-1] = 'a' + min(v[i], k) - 1;
		cout << s << '\n';
	}
}