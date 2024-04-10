#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9 + 7;
const int MAX_N = 200100;

int dp[MAX_N][3];

int ord(char c)
{
	if(c == 'R')
		return 0;

	if(c == 'G')
		return 1;

	return 2;
}

int chr(int i)
{
	if(i == 0)
		return 'R';

	if(i == 1)
		return 'G';

	return 'B';
}

void solve()
{
	int n;
	string str;

	cin >> n >> str;

	dp[0][0] = dp[0][1] = dp[0][2] = 1;
	dp[0][ord(str[0])] = 0;

	for(int i = 1; i < n; ++i)
	{
		for(int c = 0; c < 3; ++c)
		{
			dp[i][c] = INT_INF;

			for(int c1 = 0; c1 < 3; ++c1)
			{
				if(c1 == c)
					continue;

				dp[i][c] = min(dp[i][c], dp[i - 1][c1]);
			}

			if(c != ord(str[i]))
				++dp[i][c];
		}
	}

	cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << endl;

	int last_char = 0, idx = n - 1;
	string ans;

	for(int c = 1; c < 3; ++c)
	{
		if(dp[n - 1][c] < dp[n - 1][last_char])
			last_char = c;
	}

	for(;;)
	{
		ans += chr(last_char);
		int old = last_char;
		last_char = (last_char + 1) % 3;

		--idx;

		if(idx < 0)
			break;

		for(int c = 0; c < 3; ++c)
		{
			if(c == old)
				continue;

			if(dp[idx][c] < dp[idx][last_char])
				last_char = c;
		}
	}

	reverse(ans.begin(), ans.end());

	cout << ans << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}