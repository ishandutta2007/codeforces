#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string a, b;
int z[200005];
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> a >> b;
	n = a.size();
	m = b.size();

	for (int i=0; i<m; i++) {
		z[i+1] = z[i] + (b[i] - '0');
	}

	ll sol = 0;

	for (int i=0; i<n; i++) {
		int l = i;
		int r = i + m + 1 - n;
		int x = z[r] - z[l];
		if (a[i] == '1')
			x = m - n + 1 - x;
		sol += x;
	}
	cout << sol << '\n';
}