#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int w[444][444][2][2];
int x, y, n, d;
int dx[20], dy[20];

bool dlk(int x, int y) {
	x -= 222, y -= 222;
	return x*x+y*y > d*d;
}

int resi(int x, int y, int u, int v) {
	if (dlk(x, y))
		return 1;

	int& ans = w[x][y][u][v];
	if (ans)
		return ans;

	if (u == 0) {
		int w = resi(y, x, v, 1);
		if (w == 2) {
			return ans = 1;
		}
	}

	for (int i=0; i<n; i++) {
		int w = resi(x+dx[i], y+dy[i], v, u);
		if (w == 2)
			return ans = 1;
	}

	return ans = 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> x >> y >> n >> d;
	for (int i=0; i<n; i++)
		cin >> dx[i] >> dy[i];

	cout << (resi(x+222, y+222, 0, 0) == 1 ? "Anton\n" : "Dasha\n");
}