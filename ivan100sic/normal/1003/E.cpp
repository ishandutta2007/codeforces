#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, d, k, rem;
int cvor;

vector<pair<int, int>> sol;

void ae(int x, int y) {
	sol.push_back({x, y});
}

void dfs(int x, int dub, int sus) {
	if (!dub)
		return;
	if (!rem)
		return;
	for (int i=0; i<k-sus; i++) {
		if (!rem)
			break;
		int t = ++cvor;
		rem--;
		ae(x, t);
		dfs(t, dub-1, 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> d >> k;
	if (n == 1)
		return cout << "NO\n", 0;

	if (k == 1) {
		if (n == 2 && d == 1)
			cout << "YES\n1 2\n";
		else
			cout << "NO\n";
		return 0;
	}

	if (n <= d) {
		cout << "NO\n";
		return 0;
	}

	for (int i=1; i<=d; i++)
		ae(i, i+1);

	rem = n-d-1;
	cvor = d+1;

	for (int i=2; i<=d; i++)
		dfs(i, min(i-1, d+1-i), 2);

	if (!rem) {
		cout << "YES\n";
		for (auto p : sol)
			cout << p.first << ' ' << p.second << '\n';
	} else {
		cout << "NO\n";
	}
}