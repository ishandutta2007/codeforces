#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n, p;
	cin >> n >> p;
	vector<long double> a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	long long sum = 0, res = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i]; res += b[i];
	}
	if (sum <= p) {
		cout << -1;
		return 0;
	}
	long double l = 0, r = 1e11;
	long double nul = 0;
	for (int j = 0; j < 200; j++) {
		long double m = (l + r) / 2;
		long double get = 0;
		for (int i = 0; i < n; i++) {
			get += max(nul, ((m / p) * a[i] - b[i] / p));
		}
		if (get > m)
			r = m;
		else
			l = m;
	}
	cout << fixed << setprecision(15) << l;
	return 0;
}