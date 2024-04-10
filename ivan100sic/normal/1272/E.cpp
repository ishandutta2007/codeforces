#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005];
int d[2][200005];
basic_string<int> e[200005];

void bfs(int par) {
	memset(d[par], 255, sizeof(d[0]));
	basic_string<int> q;
	for (int i=0; i<n; i++)
		if (a[i] % 2 == par)
			q += i, d[par][i] = 0;
	size_t qs = 0;
	while (q.size() != qs) {
		int x = q[qs++];
		for (int y : e[x]) {
			if (y >= 0 && y < n && d[par][y] == -1)
				d[par][y] = d[par][x] + 1, q += y;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		for (int y : {i - a[i], i + a[i]}) {
			if (y >= 0 && y < n)
				e[y] += i;
		}
	}

	bfs(0);
	bfs(1);

	for (int i=0; i<n; i++)
		cout << d[1 - a[i] % 2][i] << " \n"[i == n-1];
}