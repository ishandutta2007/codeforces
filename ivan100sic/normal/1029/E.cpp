#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, sol;
vector<int> e[200005];
int gore[200005], dole[200005], imam[200005];

void dfs(int x, int p, int dub) {
	ll dole0 = 0, dole1 = 123123123;
	imam[x] = 1;
	for (int y : e[x]) {
		if (y != p) {
			dfs(y, x, dub+1);
			gore[x] += min(dole[y], imam[y]);
			imam[x] += min({gore[y], dole[y], imam[y]});

			dole1 = min({dole1 + imam[y], dole1 + dole[y], dole0 + imam[y]});
			dole0 += dole[y];
		}
	}

	if (dole1 > 123123121)
		dole1 = 123123123;

	dole[x] = dole1;

	if (dub == 2)
		sol += min({gore[x], imam[x], dole[x]});
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int x, y;
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}

	dfs(1, 1, 0);

	cout << sol << '\n';
}