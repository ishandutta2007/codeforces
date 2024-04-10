#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int ans = 2000000000;
	for (int i = 1; i * i <= n; i++)
		ans = min(ans, i + (n + i - 1) / i);
	cout << ans << '\n';
	return 0;
}