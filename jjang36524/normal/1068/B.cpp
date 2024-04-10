#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int N;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int i;
	int ans = 1;
	for (i = 2; i <= 100000; i++)
	{
		int t = 1;
		while (N % i == 0)
		{
			t++;
			N /= i;
		}
		ans *= t;
	}
	if (N > 1)
		ans *= 2;
	cout << ans;
}