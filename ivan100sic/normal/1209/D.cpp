#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

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

	int n, k, s = 0;
	cin >> n >> k;
	iota(p+1, p+n+1, 1);
	for (int i=0; i<k; i++) {
		int u, v;
		cin >> u >> v;
		if (!spoji(u, v))
			s++;
	}
	cout << s << '\n';
}