#include <iostream>
#include <algorithm>
#include <math.h>
#define int long long
using namespace std;
int T, N, M;
int arr[200100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		int i;
		for (i = 0; i < N; i++)
		{
			arr[i + 1] = 0;
		}
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			if (a == i + 1)
			{
				
				arr[a] = 1;
			}
		}
		int ans = 0;
		for (i = 1; i <= N; i++)
		{
			if (i != 1 && arr[i] != arr[i - 1])
				ans++;
		}
		ans += arr[N] == 0;
		ans+=arr[1] == 0;
		cout << min((ans+1)/2,2LL)<< '\n';
	}
}