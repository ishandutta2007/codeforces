#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		long long hc, dc, hm, dm, k, w, a; cin >> hc >> dc >> hm >> dm >> k >> w >> a;
		bool f = false;
		for (long long i = 0; i <= k; i++) {
			long long h = hc + i * a, d = dc + (k - i) * w;
			long long rc = (h + dm - 1LL) / dm, rd = (hm + d - 1LL) / d;
			if (rc >= rd) {
				f = true;
				break;
			}
		}
		if (f) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}