#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string a[105];
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i];

	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++) {
			int z = a[i][j];
			if (z == '*')
				continue;
			if (z == '.')
				z = 0;
			else
				z -= 48;
			for (int x=-1; x<=1; x++)
				for (int y=-1; y<=1; y++) {

					int xx = x + i;
					int yy = y + j;

					if (xx < 0 || xx >= n || yy < 0 || yy >= m)
						continue;

					if (a[xx][yy] == '*')
						z--;
				} 
			if (z) {
				cerr << i << ' ' << j << '\n';
				return cout << "NO\n", 0;
			}
		}

	cout << "YES\n";
}