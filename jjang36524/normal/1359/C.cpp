#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define int long long
int N, M, T;
double a, b, c, d;
int dp[200510];
int arr[200510];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	while (N--)
	{
		cin >> a >> b >> c;
		if (c <= (a + b) / 2)
			cout << 2 << '\n';
		else if (c >= a)
			cout << 1 << '\n';
		else
		{
			int x = ((a - b) / 2 / (c - (a + b) / 2)-1)/2;
			if (abs(c-((a + b) / 2) - ((a - b) / 2 / (2 * x + 1))) <= abs(c-((a + b) / 2) - ((a - b) / 2 / (2 * x + 3))))
			{
				cout << 2 * x + 1 << '\n';
			}
			else
				cout << 2 * x + 3 << '\n';
		}
	}
}