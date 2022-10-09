#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, q;
int a[200005];
int f[200005];
map<int, int> e[200005];

ll o;
int z, y;

void ad(int s, int t, int u) {
	e[s][t] = u;
	f[u]++;
	z += f[u] > a[u];
	y++;
}

void rm(int s, int t) {
	int u = e[s][t];
	e[s].erase(t);
	f[u]--;
	z -= f[u] >= a[u];
	y--;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i], o += a[i];
	cin >> q;
	while (q--) {
		int s, t, u;
		cin >> s >> t >> u;
		if (e[s].count(t)) {
			rm(s, t);
		}
		if (u) {
			ad(s, t, u);
		}
		cout << o - y + z << '\n';
	}
}