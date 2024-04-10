#include <iostream>
using namespace std;
#define ll long long

ll d[2009][2009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, k; cin >> n >> m >> k; k++;
	d[1][1] = m;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= k; j++)
			d[i][j] = (d[i - 1][j] + d[i - 1][j - 1] * 1LL * (m - 1)) % 998244353;
	cout << d[n][k] << '\n';
	return 0;
}