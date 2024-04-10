#include <iostream>
#include <string>
#define int long long
using namespace std;
int N;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int a;
		cin >> a;
		if (a > 10 && ((a - 1) % 14) < 6)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}