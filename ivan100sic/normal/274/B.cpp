#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll a[100005], sol;
basic_string<int> e[100005];

ll pos[100005], neg[100005];

void dfs(int x, int p) {
	for (int y : e[x]) {
		if (y != p) {
			dfs(y, x);
			neg[x] = max(neg[x], neg[y]);
			pos[x] = max(pos[x], pos[y]);
		}
	}

	a[x] += pos[x] - neg[x];
	if (a[x] > 0)
		neg[x] += a[x];
	else
		pos[x] += -a[x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int x, y;
		cin >> x >> y;
		e[x] += y;
		e[y] += x;
	}
	for (int i=1; i<=n; i++)
		cin >> a[i];

	dfs(1, 1);

	cout << pos[1] + neg[1] << '\n';
}