#include <iostream>
#include <string>
#include <algorithm>
#define int long long
using namespace std;
int N;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> N >> T;
	if (T == 1)
	{
		int i;
		if (N == 1)
		{
			cout << 0;
			return 0;
		}
		for (i = 0; i < N; i++)
		{
			cout << i + 2 << '\n';
		}
	}
	else
	{
		int i, j;
		for (i = 0; i < N; i++)
		{
			int j;
			for (j = N; j < N + T; j++)
			{
				cout << (i + 1) * (j + 1) << ' ';
			}
			cout << '\n';
		}
	}
}