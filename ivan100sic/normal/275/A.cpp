#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[3][3], b[3][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++) {
			int x;
			cin >> x;
			while (x--) {
				for (int dx=-1; dx<=1; dx++)
					for (int dy=-1; dy<=1; dy++) {
						if (abs(dx) + abs(dy) > 1)
							continue;
						int xx = i + dx;
						int yy = j + dy;
						if (xx < 0 || xx > 2)
							continue;
						if (yy < 0 || yy > 2)
							continue;

						b[xx][yy] ^= 1;
					}
			}
		}

	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++)
			cout << 1 - b[i][j];
		cout << '\n';
	}
}