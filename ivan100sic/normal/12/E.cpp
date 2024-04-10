#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[1005][1005];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;

	for (int j=1; j<n; j++) {
		int x=j-1, y=x;
		a[n-1][x] = a[x][n-1] = j;
		for (int z=0; z<n/2-1; z++) {
			x = (x+n-2) % (n-1);
			y = (y+1) % (n-1);
			a[x][y] = a[y][x] = j;
		}
	}

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cout << a[i][j] << " \n"[j == n-1];
}