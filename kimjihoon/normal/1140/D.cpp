#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int ans = 0;
	for (int i = 3; i <= n; i++) 
		ans += (i - 1) * i;
	cout << ans << '\n';
	return 0;
}