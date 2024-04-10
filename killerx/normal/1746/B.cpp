#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T --)
	{
		int n;
		cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; ++ i) cin >> a[i];
		vector <int> pref(n + 1), suff(n + 1);
		for (int i = 0; i < n; ++ i) pref[i + 1] = pref[i] + a[i];
		for (int i = n - 1; ~i; -- i) suff[i] = suff[i + 1] + a[i];
		int ans = n - 1;
		for (int i = 0; i <= n; ++ i) ans = min(ans, max(pref[i], n - i - suff[i]));
		cout << ans << endl;
	}
	return 0;
}