#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
int N, M, T, a, b, c, d;
int arr[1001];
int dp[1001][1001][2];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		int i;
		int a=0, b = 0;
		for (i = 1; i <= N; i++)
		{
			cin >> arr[i];
			if (arr[i] % 2)
				a++;
			else
				b++;
		}
		if ((N == M && (a % 2) == 0) || a == 0||(M%2==0&&b==0))
			cout << "No" << '\n';
		else
			cout << "Yes" << '\n';
	}
}