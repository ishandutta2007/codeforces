#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	vector<int> d(n+1);
	for (int i=0; i<n-1; i++) {
		int u, v;
		cin >> u >> v;
		d[u]++;
		d[v]++;
	}
	ll z = 0;
	for (int i=1; i<=n; i++)
		z += d[i]*(d[i]-1) / 2;
	cout << z << '\n';
}