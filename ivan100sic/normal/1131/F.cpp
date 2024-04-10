#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int p[200005];
list<int> a[200005];

int ep(int x) {
	if (x == p[x])
		return x;
	return p[x] = ep(p[x]);
}

void spoji(int x, int y) {
	x = ep(x);
	y = ep(y);
	p[x] = y;
	a[y].splice(a[y].end(), a[x]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		p[i] = i;
		a[i] = {i};
	}

	for (int i=1; i<n; i++) {
		int x, y;
		cin >> x >> y;
		spoji(x, y);
	}

	for (int x : a[ep(1)])
		cout << x << ' ';
	cout << '\n';
}