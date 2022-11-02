#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);	
	int n; cin >> n;
	if (n % 2) cout << 0 << '\n';
	else {
		int ans = 1;
		for (int i = 0; i < n / 2; i++)
			ans *= 2;
		cout << ans << '\n';
	}
	return 0;
}