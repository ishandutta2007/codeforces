#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int z[5005][5005];
char a[5005][5005];
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i]+1;
	}

	for (int i=1; i<=5001; i++) {
		for (int j=1; j<=5001; j++) {
			if (a[i][j] == '1') {
				z[i][j] = 1;
			}
			z[i][j] += z[i-1][j] + z[i][j-1] - z[i-1][j-1];
		}
	}

	int sol = n*m;
	for (int k=2; k<=2500; k++) {
		int df = 0;
		for (int x=0; x<=2500; x+=k) {
			for (int y=0; y<=2500; y+=k) {
				int s = z[x+k][y+k] + z[x][y] - z[x+k][y] - z[x][y+k];
				df += min(s, k*k-s);
			}
		}
		sol = min(sol, df);
	}
	cout << sol;
}