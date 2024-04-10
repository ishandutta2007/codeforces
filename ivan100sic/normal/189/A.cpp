#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
using namespace std;

int n, a[3], p[4005], d[4005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> a[0] >> a[1] >> a[2];

	p[0] = 1;
	d[0] = 0;

	for (int i=1; i<=n; i++) {
		for (int j=0; j<3; j++) {
			if (i - a[j] >= 0 && p[i - a[j]]) {
				p[i] = 1;
				d[i] = max(d[i], d[i - a[j]] + 1);
			}
		}
	}

	cout << d[n];

}