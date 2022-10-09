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

int n;
long long a[4][100005];

long long d[4][100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=3; i++) {
		for (int j=1; j<=n; j++) {
			cin >> a[i][j];
		}
	}

	d[1][1] = a[1][1];
	d[2][1] = a[1][1] + a[2][1];
	d[3][1] = d[2][1] + a[3][1];

	d[1][0] = 0;
	d[2][0] = -1e18;
	d[3][0] = -1e18;

	for (int i=2; i<=n; i++) {
		vector<long long> v = {
			d[2][i-1] + a[2][i],
			d[1][i-1] + a[2][i] + a[1][i],
			d[3][i-1] + a[2][i] + a[3][i]
		};

		d[2][i] = *max_element(v.begin(), v.end());

		// 1

		v = {
			d[1][i-1] + a[1][i],
			d[2][i-1] + a[1][i] + a[2][i],
			d[3][i-1] + a[1][i] + a[2][i] + a[3][i],

			d[3][i-2] + a[1][i] + a[2][i] + a[3][i] + a[1][i-1] + a[2][i-1] + a[3][i-1]
		};

		d[1][i] = *max_element(v.begin(), v.end());

		// 3

		v = {
			d[3][i-1] + a[3][i],
			d[2][i-1] + a[3][i] + a[2][i],
			d[1][i-1] + a[3][i] + a[2][i] + a[1][i],

			d[1][i-2] + a[1][i] + a[2][i] + a[3][i] + a[1][i-1] + a[2][i-1] + a[3][i-1]
		};

		d[3][i] = *max_element(v.begin(), v.end());
	}

	cout << d[3][n];
}