#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, t, c;
int z[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> t >> c;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		z[i] = z[i-1] + (x > t);
	}
	int u = 0;
	for (int i=c; i<=n; i++) {
		if (z[i] - z[i-c] == 0)
			u++;
	}
	cout << u << '\n';
}