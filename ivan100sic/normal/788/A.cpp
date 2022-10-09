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
long long a[100005];
long long b[100005];
long long c[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for (int i=1; i<n; i++) {
		b[i] = abs(a[i] - a[i+1]);
		//cerr << b[i] << '\n';
	}
	long long lo = b[n-1];
	long long hi = b[n-1];
	long long sol = lo;

	for (int i=n-2; i>=1; i--) {
		long long lon = min(-hi+b[i], b[i]);
		long long hin = max(-lo+b[i], b[i]);

		lo = lon;
		hi = hin;

		//cerr << lo << ' ' << hi << '\n';

		sol = max(sol, hi);
	}

	cout << sol;
}