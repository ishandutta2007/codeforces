#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int c[200005];
basic_string<int> e[200005];

void dfs(int x) {
	for (int y : e[x])
		if (!c[y])
			c[y] = 3-c[x], dfs(y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	vector<pair<int, int>> v;
	for (int i=0; i<n; i++) {
		int l, r;
		cin >> l >> r;
		l = 2*l;
		r = 2*r+1;
		v.emplace_back(l, i);
		v.emplace_back(r, i+n);
	}
	sort(v.begin(), v.end());
	for (int i=0; i<2*n; i+=2) {
		int x = v[i].second;
		int y = v[i+1].second;
		e[x] += y;
		e[y] += x;
	}
	for (int i=0; i<n; i++)
		e[i] += i+n, e[i+n] += i;
	for (int i=0; i<n; i++) {
		if (!c[i])
			c[i] = 1, dfs(i);
		cout << c[i]-1 << " \n"[i == n-1];
	}
}