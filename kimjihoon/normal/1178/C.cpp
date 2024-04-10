#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int w, h; cin >> w >> h;
	int c = w + h;
	long long ans = 1;
	for (int i = 0; i < c; i++)
		ans = (ans * 2LL) % 998244353LL;
	cout << ans << '\n';
	return 0;
}