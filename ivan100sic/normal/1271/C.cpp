#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, sx, sy;
int x[200005], y[200005];

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> sx >> sy;
	for (int i=0; i<n; i++)
		cin >> x[i] >> y[i];

	int xx=0, yy=0, zz=-1;

	for (int d=0; d<4; d++) {
		int a = sx + dx[d];
		int b = sy + dy[d];

		int z = 0;
		for (int i=0; i<n; i++)
			if (abs(x[i] - a) + abs(y[i] - b) + 1 ==
				abs(x[i] - sx) + abs(y[i] - sy))
			{
				z++;
			}
		if (z > zz)
			xx = a, yy = b, zz = z;
	}

	cout << zz << '\n' << xx << ' ' << yy << '\n';
}