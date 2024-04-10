#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long a, b, c; cin >> a >> b >> c;
	long long ans = 2 * (min(a, b) + c);
	if (a != b) ans++;
	cout << ans << '\n';
	return 0;
}