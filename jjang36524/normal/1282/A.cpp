#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
int N;
int dp[200100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	while (N--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a > b)
			swap(a, b);
		int cov = min(c + d, b) - max(c - d, a);
		if (cov < 0)
			cov = 0;
		cout << b - a - cov<<'\n';
	}
}