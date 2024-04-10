#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, k;
bool marked[305];
basic_string<int> fale, tu;

bool e[305][305];

void ae(int x, int y) {
	if (e[x][y])
		return;
	if (m == 0)
		return;

	// cerr << "dodao " << x << ' ' << y << '\n';
	e[x][y] = e[y][x] = 1;
	m--;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=0; i<k; i++) {
		int x;
		cin >> x;
		tu += x;
		marked[x] = 1;
	}
	for (int j=1; j<=n; j++)
		if (!marked[j])
			fale += j;

	int y = tu[0];
	int z = tu[1];

	for (int i=1; i<=n; i++) {
		if (i == y || i == z)
			continue;
		ae(i, y);
	}

	if (fale.size() == 0)
		return cout << "-1\n", 0;

	for (int x : fale)
		ae(x, z);

	for (int i=1; i<=n; i++) {
		if (i == z)
			continue;
		for (int j=1; j<=n; j++) {
			if (j == z)
				continue;
			if (i == j)
				continue;
			ae(i, j);
		}
	}

	if (m > 0)
		return cout << "-1\n", 0;
	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++)
			if (e[i][j])
				cout << i << ' ' << j << '\n';
}