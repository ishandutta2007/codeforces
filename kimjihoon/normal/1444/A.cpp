#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		long long p, q; cin >> p >> q;
		if (p % q != 0) {
			cout << p << '\n';
			continue;
		}
		v.clear();
		long long ans = 1;
		for (long long i = 2; i * i <= q; i++) {
			if (q % i == 0) {
				v.push_back(i);
				if (i * i != q) v.push_back(q / i);
			}
		}
		v.push_back(q);
		for (int i = 0; i < v.size(); i++) {
			long long c = 1, tq = q;
			while (tq % v[i] == 0) {
				c *= v[i];
				tq /= v[i];
			}
			long long tp = p;
			while (tp % v[i] == 0)
				tp /= v[i];
			c /= v[i];
			tp *= c;
			ans = max(ans, tp);
		}
		cout << ans << '\n';
	}
	return 0;
}