#include <iostream>
#include <algorithm>
using namespace std;

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		long long p; cin >> p;
		long long ans = -1;
		for (int i = 0; i < 3; i++) {
			long long a; cin >> a;
			if (p % a == 0) ans = 0;
			else {
				long long t = (a - (p % a));
				if (ans == -1) ans = t;
				else ans = min(ans, t);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}