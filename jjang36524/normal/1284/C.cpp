#include <iostream>
using namespace std;
#define int long long
int N, M, T;
int fact[251000];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N>>M;
	int i;
	fact[0] = 1;
	for (i = 1; i <= N;i++)
	{
		fact[i] = (fact[i - 1] * i) % M;
	}
	int ans = 0;
	for (i = 1; i <= N;i++)
	{
		ans += ((N - i + 1) * fact[i] %M* fact[N - i + 1])%M;
	}
	cout << ans % M;
}