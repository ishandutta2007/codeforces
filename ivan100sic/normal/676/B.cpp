#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

double cap[15][15];
int n;

void pour(int x, int y, double z) {
	if (x > n) return;
	double w = min(cap[x][y], z);
	cap[x][y] -= w;
	z -= w;
	pour(x+1, y, z/2);
	pour(x+1, y+1, z/2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> n >> t;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=i; j++)
			cap[i][j] = 1;
	while (t--) {
		pour(1, 1, 1);
	}
	int z = 0;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=i; j++)
			if (cap[i][j] < 1e-9)
				z++;
	cout << z << '\n';
}