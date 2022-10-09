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
int a[100005], d[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	a[0] = -200000;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	d[0] = 0;
	for (int i=1; i<=n; i++) {
		d[i] = d[i-1] + 20;
		d[i] = min(d[i], d[lower_bound(a, a+n+1, a[i] - 89) - a - 1] + 50);
		d[i] = min(d[i], d[lower_bound(a, a+n+1, a[i] - 1439) - a - 1] + 120);

		cout << d[i] - d[i-1] << '\n';
	}
}