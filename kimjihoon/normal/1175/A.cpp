#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);	
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		long long n, k; cin >> n >> k;
		long long ans = 0;
		while (n) {
			ans += n % k; 
			if (n >= k) ans++;
			n /= k;
		}
		cout << ans << '\n';
	}
	return 0;
}