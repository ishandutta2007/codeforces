#include <iostream>
#include <algorithm>
using namespace std;

long long qry(int l, int r)
{
	cout << "? " << l << " " << r << endl;
	long long t; cin >> t;
	return t;
}

long long ps(long long s, long long e, long long w)
{
	long long md = (s + e) / 2LL;
	while (s < e) {
		long long t = md * (md + 1LL) / 2LL;
		if (t == w) break;
		else if (t < w) s = md + 1LL;
		else e = md - 1LL;
		md = (s + e) / 2LL;
	}
	return md;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		long long mx = qry(1, n);
		int s = 1, e = n, md = (s + e) / 2;
		while (s < e) {
			long long t = qry(1, md);
			if (!t) s = md + 1;
			else if (t == mx) e = md - 1;
			else break;
			md = (s + e) / 2;
		}
		int tp = 1LL * md - (qry(1, md) - qry(1, md - 1)), l = 0, r = 0;
		if (qry(1, tp) == 0) {
			l = tp;
			s = md + 1;
			md = (s + e) / 2;
			while (s < e) {
				long long t = qry(1, md);
				if (1LL * (md - tp) * (md - tp + 1) / 2LL == t) s = md + 1;
				else if (t == mx) e = md - 1;
				else break;
				md = (s + e) / 2;
			}
			r = 1LL * md - (qry(1, md) - qry(1, md - 1));
		}
		else {
			r = tp;
			l = 1LL * (tp - 1) - (qry(1, tp - 1) - qry(1, tp - 2));
		}
		mx -= 1LL * (r - l - 1) * (r - l) / 2LL;
		long long df = ps(0LL, 1000000000LL, mx);
		cout << "! " << l << " " << r << " " << 1LL * r + df << endl;
	}
	return 0;
}