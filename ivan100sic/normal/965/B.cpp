#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string a[100];
int b[100][100];
int n, k;

void okh(int x, int y) {
	bool ok = true;
	for (int i=0; i<k; i++) {
		if (x+i >= n)
			return;
		if (a[x+i][y] == '#')
			ok = false;
	}

	if (!ok)
		return;

	for (int i=0; i<k; i++)
		b[x+i][y]++;
}

void okv(int x, int y) {
	bool ok = true;
	for (int i=0; i<k; i++) {
		if (y+i >= n)
			return;
		if (a[x][y+i] == '#')
			ok = false;
	}

	if (!ok)
		return;

	for (int i=0; i<k; i++)
		b[x][y+i]++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++) {
			okh(i, j);
			okv(i, j);
		}

	int bx=0, by=0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			// cerr << b[i][j] << ' ';
			if (b[i][j] > b[bx][by]) {
				bx = i;
				by = j;
			}
		}
		// cerr << '\n';
	}
	cout << bx+1 << ' ' << by+1 << '\n';
}