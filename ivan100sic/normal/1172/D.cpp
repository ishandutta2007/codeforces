#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int r[1005], c[1005];
vector<array<int, 4>> sol;

void solve(vector<int> r, vector<int> c, int n) {
	if (n == 1)
		return;

	vector<int> r2 = r, c2 = c;

	for (int i=1; i<n; i++) {
		if (r2[i] == n)
			swap(r2[i], r2[n]);
		if (c2[i] == n)
			swap(c2[i], c2[n]);
	}

	r2.pop_back();
	c2.pop_back();
	solve(r2, c2, n-1);

	if (r[n] != n || c[n] != n)
		sol.push_back({n, c[n], r[n], n});
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> r[i];
	for (int i=1; i<=n; i++)
		cin >> c[i];

	solve(vector<int>(r, r+n+1), vector<int>(c, c+n+1), n);

	cout << sol.size() << '\n';
	for (auto a : sol) {
		for (int x : a)
			cout << x << ' ';
		cout << '\n';
	}
}