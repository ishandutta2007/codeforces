#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> e[100005];
int z[100005];

void dfs(int x) {
	if (e[x].size() == 0) {
		z[x] = 1;
		return;
	}
	for (int y : e[x]) {
		dfs(y);
		z[x] += z[y];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=2; i<=n; i++) {
		int p;
		cin >> p;
		e[p] += i;
	}

	dfs(1);

	sort(z+1, z+n+1);
	for (int i=1; i<=n; i++)
		cout << z[i] << ' ';
	cout << '\n';
}