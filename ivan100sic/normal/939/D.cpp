#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<char, char> p;

char e(char x) {
	if (x == p[x])
		return x;
	return p[x] = e(p[x]);
}

bool merge(char x, char y) {
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

	for (char x='a'; x<='z'; x++)
		p[x] = x;

	int n;
	string a, b;
	cin >> n >> a >> b;
	basic_string<pair<char, char>> sol;
	for (int i=0; i<n; i++) {
		if (merge(a[i], b[i])) {
			sol += {a[i], b[i]};
		}
	}
	cout << sol.size() << '\n';
	for (auto [x, y] : sol)
		cout << x << ' ' << y << '\n';
}