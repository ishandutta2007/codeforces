#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005], c[200005];

basic_string<tuple<int, int, int>> sol;

void uzmi(int i, int j) {
	if (a[i] > a[j])
		sol += {2, i, j};
	else
		sol += {1, i, j};
	a[i] = a[j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		c[a[i]]++;
	}

	int x = max_element(c, c+200005) - c;
	int y = find(a+1, a+n+1, x) - a;

	for (int i=y-1; i>=1; i--)
		if (a[i] != x)
			uzmi(i, i+1);

	for (int i=y+1; i<=n; i++)
		if (a[i] != x)
			uzmi(i, i-1);

	cout << sol.size() << '\n';
	for (auto [x, y, z] : sol)
		cout << x << ' ' << y << ' ' << z << '\n';

}