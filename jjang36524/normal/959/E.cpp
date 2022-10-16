#include <iostream>
using namespace std;
#define int long long
signed main()
{
	int N;
	cin >> N;
	int ans = 0;
	int t = 1;
	while (N > 1)
	{
		ans += (N/2) * t;
		N = (N + 1) / 2;
		
		t *= 2;
	}
	cout << ans;
}