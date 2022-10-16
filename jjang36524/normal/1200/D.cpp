#include <iostream>
using namespace std;
int N, K;
#include <algorithm>
#include <vector>
#include <string.h>
pair<int, int>xlim[2005];
pair<int, int>ylim[2005];
char arr[2005][2005];
int codeforcesgod[2005];
int touristgod[2005];
long long rans;
long long ansplus;
int visited[2005][2];
int main()
{
	scanf("%d%d", &N, &K);
	int i, j;
	for (i = 0; i < N; i++)
	{
		xlim[i] = { 0,2000 };
		ylim[i] = { 0,2000 };
	}
	ansplus = 2 * N;
	for (i = 0; i < N; i++)
	{
		scanf("%s", arr[i]);
		
		for (j = 0; j < N; j++)
		{
			if (arr[i][j] == 'B')
			{
				ylim[i].first = max(ylim[i].first, j - K + 1);
				xlim[j].first = max(xlim[j].first, i - K + 1);
				ylim[i].second = min(ylim[i].second, j);
				xlim[j].second = min(xlim[j].second, i);
				visited[i][0] = 1;
				visited[j][1] = 1;
			}
		}
	}
	for (i = 0; i < N; i++)
	{
		ansplus -= visited[i][0] + visited[i][1];
	}
	for (i = 0; i < N-K+1; i++)
	{
		memset(codeforcesgod, 0, sizeof(codeforcesgod));
		memset(touristgod, 0, sizeof(touristgod));
		for (j = 0; j < N; j++)
		{
			if (i >= xlim[j].first&&i <= xlim[j].second&&visited[j][1])
			{
				codeforcesgod[max(j-K+1,0)]++;
				codeforcesgod[j + 1]--;
			}
		}
		for (j = i; j < min(i+K,N); j++)
		{
			if (ylim[j].first <= ylim[j].second&&visited[j][0])
			{
				touristgod[ylim[j].first]++;
				touristgod[ylim[j].second+1]--;
			}
		}
		long long ans = 0;
		for (j = 0; j < N; j++)
		{
			ans += touristgod[j] + codeforcesgod[j] ;
			rans = max(rans, ans);
		}
	}
	cout << rans+ansplus;
}