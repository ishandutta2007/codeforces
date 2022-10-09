#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<string, int> mp;
int n, k, m;
int p[100005], l[100005];

int e(int x) {
	if (x == p[x])
		return p[x];
	return p[x] = e(p[x]);
}

void merge(int x, int y) {
	x = e(x);
	y = e(y);
	if (x == y)
		return;
	p[x] = y;
	l[y] = min(l[y], l[x]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> m;
	for (int i=1; i<=n; i++) {
		string s;
		cin >> s;
		mp[s] = i;
	}
	for (int i=1; i<=n; i++) {
		cin >> l[i];
		p[i] = i;
	}
	for (int i=0; i<k; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		while (x--) {
			int z;
			cin >> z;
			merge(y, z);
		}
	}
	ll sol = 0;
	while (m--) {
		string s;
		cin >> s;
		sol += l[e(mp[s])];
	}
	cout << sol << '\n';
}