#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
using namespace std;
#define int long long
int arr[5010];
int nen1[5010];

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		int i;
		int ans = 0;
		for (i = 0; i < N; i++)
		{
			cin >> arr[i];
			nen1[i] = i;
		}
		nen1[N] = N;
		for (i = N - 1; i >= 0; i--)
		{
			if (arr[i] == 1)
				nen1[i] = nen1[i + 1];
		}
		
		while (nen1[0] != N)
		{
			
			ans++;
			int cur = 0;
			while (cur < N)
			{
				if (arr[cur] == 1)
					cur = nen1[cur];
				else
				{
					int ncur = cur + arr[cur];
					arr[cur]--;
					if (arr[cur] == 1)
					{
						nen1[cur] = nen1[cur + 1];
						int nnc = cur-1;
						while (nnc >= 0 && nen1[nnc] == cur)
						{
							nen1[nnc] = nen1[cur + 1];
							nnc--;
						}
					}
					cur = ncur;
				}
				

			}
			if (arr[nen1[0]] > N)
			{
				ans += arr[nen1[0]] - N;
				arr[nen1[0]] = N;
				if (arr[nen1[0]] == 1)
				{
					int cur = nen1[0];
					nen1[cur] = nen1[cur + 1];
					int nnc = cur - 1;
					while (nnc >= 0 && nen1[nnc] == cur)
					{
						nen1[nnc] = nen1[cur + 1];
						nnc--;
					}
				}
			}
		}
		cout << ans<<'\n';
	}
}