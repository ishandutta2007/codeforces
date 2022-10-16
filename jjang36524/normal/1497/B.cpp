#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <set>
using namespace std;
int don[101];
int cou[100100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N,M;
		cin >> N>>M;
		memset(cou, 0, sizeof(N) * M);
		int i;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			cou[a % M]++;
		}
		int ans = N;
		for (i = 0; i <= M/2; i++)
		{
			if (i == 0 || 2 * i == M)
			{
				ans -= max(cou[i] - 1,0);
			}
			else
			{
				ans -= max(min(cou[i] + cou[M - i] - 1, min(cou[i], cou[M - i]) * 2), 0);
			}
			
		}
		cout << ans << '\n';
	}
}