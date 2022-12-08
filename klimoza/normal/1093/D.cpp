#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;


typedef long long ll;

const ll INF = 1e18;

ll mod = 998244353;

vector<char> used;
vector<vector<int>> edge;
vector<int> dep;
ll h1 = 0;
ll h2 = 0;
bool an = true;

void dfs(int v, int p) {
	used[v] = true;
	if(p != -1) dep[v] = dep[p] + 1;
	if (dep[v] % 2 == 1) {
		//cout << v << " das " << endl;
		h1++;
	}
	else {
		//cout << v << endl;
		h2++;
	}
	for (int u : edge[v]) {
		if (used[u]) {
			if ((dep[v] - dep[u]) % 2 == 0) {
				an = false;
				return;
			}
		}
		if (!used[u]) {
			dfs(u, v);
			if (!an) return;
		}
	}
	if (!an) return;
}


int main() {
	int t, n, m;
	cin >> t;
	vector<ll> pov(4 * 1e5);
	pov[0] = 1;
	for (int i = 1; i < pov.size(); i++) {
		pov[i] = pov[i - 1] * 2;
		pov[i] %= mod;
	}
	for (int j = 0; j < t; j++) {
		cin >> n >> m;
		used.clear();
		used.resize(n);
		edge.clear();
		edge.resize(n);
		dep.clear();
		dep.resize(n);
		int t1, t2;
		for (int i = 0; i < m; i++) {
			cin >> t1 >> t2;
			t1--;
			t2--;
			edge[t1].push_back(t2);
			edge[t2].push_back(t1);
		}
		ll ans = 0;
		bool r = false;
		for (int i = 0; i < n; i++) {
			if (!used[i]) {
				h1 = 0;
				h2 = 0;
				an = true;
				dfs(i, -1);
				if (!an) {
					ans = 0;
					break;
				}
				if (!r) ans = 1;
				ans = ((ans * pov[h1]) % mod + (ans * pov[h2]) % mod) % mod;
				//cout << pov[h1] << " " << pov[h2] << " " << h1 << " " << h2 <<  endl;
				r = true;
			}
		}
		cout << ans << endl;
	}
	//system("pause");
	return 0;
}