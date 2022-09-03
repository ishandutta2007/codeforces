#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 2e5 + 239;
const int BIG = 1e9 + 239;

int n, a[M];

int main()
{
	cin.sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < (2 * n); i++)
		cin >> a[i];
	sort(a, a + (2 * n));
	if (n == 1)
	{
		cout << "0";
		return 0;
	}
	int now = BIG;
	for (int i = 1; i < n; i++) now = min(now, a[i + n - 1] - a[i]); 
	cout << min((ll)(a[2 * n - 1] - a[0]) * (ll)now, (ll)(a[n - 1] - a[0]) * (ll)(a[2 * n - 1] - a[n]));
	return 0;
}