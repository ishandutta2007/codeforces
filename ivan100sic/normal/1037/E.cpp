#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k, m;
int u[200005], v[200005];
set<int> e[200005];
int deg[200005];
bool alive[200005];
int alc;
queue<int> delet;

void del(int x) {

	// cerr << "removing " << x << '\n';

	alive[x] = false;
	alc--;
	for (int y : e[x]) {
		if (alive[y]) {
			deg[y]--;
			if (deg[y] == k-1) {
				delet.push(y);
			}
		}
	}
}

void peck(int x) {
	deg[x]--;
	if (deg[x] == k-1) {
		delet.push(x);
	}
}

void clearq() {
	while (delet.size()) {
		int x = delet.front(); delet.pop();
		del(x);
	}
}

int ans[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=0; i<m; i++) {
		cin >> u[i] >> v[i];
		u[i]--;
		v[i]--;
		deg[u[i]]++;
		deg[v[i]]++;
		e[u[i]].insert(v[i]);
		e[v[i]].insert(u[i]);
	}

	fill(alive, alive+n, true);
	alc = n;

	for (int i=0; i<n; i++)
		if (deg[i] < k)
			delet.push(i);

	for (int i=m-1; i>=0; i--) {
		// cerr << i << '\n';
		clearq();
		ans[i] = alc;
		e[u[i]].erase(v[i]);
		e[v[i]].erase(u[i]);

		if (alive[u[i]] && alive[v[i]]) {
			peck(u[i]);
			peck(v[i]);
		}
	}

	for (int i=0; i<m; i++)
		cout << ans[i] << '\n';
}