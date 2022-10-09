#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int e[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, a, b, c, t, sol=0;
	cin >> n >> a >> b >> c >> t;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		e[x]++;
	}

	for (int i=1; i<=t; i++) {

		int mx = 0;
		for (int r=i; r<=t; r++) {
			mx = max({mx, a-b*(r-i) + c*(r-i)});
		}

		sol += mx*e[i];
	}

	cout << sol << '\n';
}