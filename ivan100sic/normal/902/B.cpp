#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int b[10005];
basic_string<int> e[10005];
int n, sol;

void dfs(int x, int c) {
	if (c != b[x]) {
		c = b[x];
		sol++;
	}
	for (int y : e[x])
		dfs(y, c);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=2; i<=n; i++) {
		int x;
		cin >> x;
		e[x] += i;
	}

	for (int i=1; i<=n; i++)
		cin >> b[i];

	dfs(1, -1);
	cout << sol << '\n';
}