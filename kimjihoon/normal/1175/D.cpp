#include <iostream>
#include <algorithm>
using namespace std;

long long s[300009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);	
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		long long a; cin >> a;
		s[i] = s[i - 1] + a;
	}
	long long ans = 1LL * k * s[n];
	sort(s + 1, s + n);
	for (int i = 1; i < k; i++)
		ans -= s[i];
	cout << ans << '\n';
	return 0;
}