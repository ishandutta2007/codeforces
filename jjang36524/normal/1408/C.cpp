#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
int arr[100005];
double ti[100005][2];
signed main()
{
	int N, M,T;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		int i;
		for (i = 0; i < N; i++)
		{
			cin >> arr[i + 1];
		}
		ti[0][0] = ti[N + 1][1] = 0;
		arr[N + 1] = M;
		for (i = 1; i <= N + 1; i++)
		{
			ti[i][0] = ti[i - 1][0] + (arr[i] - arr[i - 1]) / (double)(i);
		}
		for (i = N; i>=0; i--)
		{
			ti[i][1] = ti[i + 1][1] + (arr[i+1] - arr[i]) / (double)(N+1-i);
		}
		double ans = 0;
		for (i = 0; i <= N + 1; i++)
		{
			if (ti[i][0] > ti[i][1])
			{
				double mi = 0;
				if (ti[i - 1][0] > ti[i][1])
				{
					mi = (N + 2 - i) * (ti[i - 1][0] - ti[i][1]);
				}
				else
				{
					mi = (i) * (-ti[i - 1][0] + ti[i][1]);
				}
				ans = max(ti[i][1], ti[i - 1][0]) + (arr[i] - arr[i - 1]-mi) /(double)(N+2);
				break;
			}
		}
		cout.precision(15);
		cout << ans << '\n';
	}
}