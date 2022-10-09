#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
using namespace std;

int a[105][105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;

	cin >> n;

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (i == 1 || j == 1) {
				a[i][j] = 1;
			} else {
				a[i][j] = a[i-1][j] + a[i][j-1];
			}
		}
	}

	cout << a[n][n];
}