#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int p[100005];

int e(int x) {
	if (x == p[x])
		return x;
	return p[x] = e(p[x]);
}

bool spoji(int x, int y) {
	x = e(x);
	y = e(y);
	if (x == y)
		return false;
	p[x] = y;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	iota(p, p+n+1, 0);
	int z = 0;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		if (!spoji(u, v))
			z = (2*z+1) % 1'000'000'009;
		cout << z << '\n';
	}
}