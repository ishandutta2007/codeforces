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

int a[100005];
int l, r, ls, rs, n, lc, rc;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	if (n == 1) {
		cout << "1 0";
		return 0;
	}

	l = 1;
	lc = 0;
	rc = 0;
	r = n;
	ls = a[1];
	rs = a[n];
	while (l <= r) {
		if (ls <= rs) {
			ls += a[++l];
			lc++;
		} else {
			rs += a[--r];
			rc++;
		}
	}
	cout << lc << ' ' << rc;
}