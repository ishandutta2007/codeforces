#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<pair<int, int>, int> p;
map<int, int> px, py;

template<class T>
ll cnt(map<T, int> mp) {
	ll z = 0;
	for (auto p : mp)
		z += p.second * (p.second - 1ll);
	return z / 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	while (n--) {
		int x, y;
		cin >> x >> y;
		p[{x, y}]++;
		px[x]++;
		py[y]++;
	}

	cout << cnt(px) + cnt(py) - cnt(p) << '\n';
}