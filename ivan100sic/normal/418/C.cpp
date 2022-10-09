#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<ll> solve1d(int n) {
	if (n == 1)
		return {1};
	else if (n == 2)
		return {3, 4};
	vector<ll> a(n, 1);
	a[n-2] = 1 + n%2;
	a[n-1] = (a[n-2]*a[n-2] + (n-2) - 1) / 2;
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> n >> m;
	auto a = solve1d(n), b = solve1d(m);
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cout << a[i]*b[j] << " \n"[j == m-1];
}