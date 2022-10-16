#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int isp(int n)
{
	int i;
	for (i = 2; i < n; i++)
	{
		if (n % i == 0)
			return 1;
	}
	return 0;
}
int vis[100100];
int main()
{
	int T;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		int i;
		for (i = 0; i < M; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			vis[b] = 1;
		}
		for (i = 1; i <= N; i++)
		{
			if (!vis[i])
			{
				int j;
				for (j = 1; j <= N; j++)
				{
					if(i!=j)
						cout << i << ' ' << j << '\n';
				}
				break;
			}
		}
		memset(vis, 0, sizeof(T) * (N + 5));
	}
}