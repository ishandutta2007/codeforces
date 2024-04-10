#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, a, b;
int d[200005];

void dijk() {
	set<pair<int, int>> pq;
	d[0] = 0;
	for (int i=1; i<200005; i++) {
		d[i] = 1123123123;
	}
	pq.insert({0, 0});
	while (pq.size()) {
		int x = pq.begin()->second;
		pq.erase(pq.begin());

		if (x+a < 200005 && max(d[x], x+a) < d[x+a]) {
			pq.erase({d[x+a], x+a});
			d[x+a] = max(d[x], x+a);
			pq.insert({d[x+a], x+a});
		}

		if (x-b >= 0 && max(d[x], x-b) < d[x-b]) {
			pq.erase({d[x-b], x-b});
			d[x-b] = max(d[x], x-b);
			pq.insert({d[x-b], x-b});
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> a >> b;
	ll z = 0;

	dijk();

	for (int i=0; i<200005; i++) {
		z += max(0, n-d[i]+1);
	}

	int g = __gcd(a, b);
	int g0 = (200005 + g)/g*g;
	if (g0 - g >= 200005)
		g0 -= g;
	int g1 = n/g*g;
	if (g0 <= g1) {
		z -= (1+(g1-g0)/g) * (-2+2ll*g0-2ll*n+(g1-g0)) / 2;
	}
	cout << z << '\n';
}