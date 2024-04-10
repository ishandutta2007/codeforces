// ja sam! no worries

#include <bits/stdc++.h>
using namespace std;

int n, m;
bool p[10][10], q[10][10];
int cja[10];
int zu[10][10], zv[10][10];
set<int> u[10][10], v[10][10];

int dva(int a, int b, int c, int d) {
	if (a == b) return a;
	if (a == c) return a;
	if (a == d) return a;
	if (b == c) return b;
	if (b == d) return b;
	if (c == d) return c;
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		if (x > y) swap(x, y);
		p[x][y] = 1;
	}

	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		if (x > y) swap(x, y);
		q[x][y] = 1;
	}

	for (int i=1; i<=9; i++) {
		for (int j=1; j<=9; j++) {
			for (int k=1; k<=9; k++) {
				for (int l=1; l<=9; l++) {
					if (i == j || k == l)
						continue;

					int sp = 0;
					sp += i == k;
					sp += i == l;
					sp += j == k;
					sp += j == l;

					if (sp != 1)
						continue;

					int isti = dva(i, j, k, l);

					if (p[i][j] && q[k][l]) {
						cja[isti]++;
						u[i][j].insert(isti);
						v[k][l].insert(isti);
					}
				}
			}
		}
	}

	if (count(cja+1, cja+10, 0) == 8) {
		for (int i=1; i<=9; i++)
			if (cja[i])
				cout << i;
		return 0;
	}

	int bad = 0;
	for (int i=1; i<=9; i++) {
		for (int j=1; j<=9; j++) {
			bad += u[i][j].size() > 1;
			bad += v[i][j].size() > 1;
		}
	}

	if (bad)
		cout << "-1\n";
	else
		cout << "0\n";
}