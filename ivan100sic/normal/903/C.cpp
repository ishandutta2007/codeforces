#include <bits/stdc++.h>
using namespace std;

int n;
int a[5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;

	map<int, int> c;

	for (int i=1; i<=n; i++) {
		cin >> a[i];
		c[a[i]]++;
	}

	int sol = 0;

	for (auto p : c) {
		sol = max(sol, p.second);
	}

	cout << sol << '\n';

}