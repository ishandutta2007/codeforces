#include <iostream>
#include <string>
using namespace std;
string s;
int dp[100100];
int main()
{
	cin >> s;
	int i;
	long long ans = 1;
	int l = s.length();
	dp[0] = 1;
	dp[1] = 1;
	for (i = 2; i <= l; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
	}
	int times = 0;
	for (i = 0; i < l; i++)
	{
		if (s[i] == 'w' || s[i] == 'm')
		{
			cout << 0;
			return 0;
		}
		if ((i && s[i] == s[i - 1]) && (s[i] == 'n' || s[i] == 'u'))
			times++;
		else if ((s[i] == 'u' || s[i] == 'n'))
		{
			ans *= dp[times];
			ans %= 1000000007;
			times = 1;
		}
		else
		{
			ans *= dp[times];
			ans %= 1000000007;
			times = 0;
		}
	}
	cout << (ans * dp[times])%1000000007;
}