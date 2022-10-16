#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define int long long
using namespace std;
int cou[200000];
int diff[200000];
int arr[1000100];
int dif[1000100];
int rcou[200100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int ans = 0;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (i = 0; i < N - 1; i++)
		dif[i] = arr[i] < arr[i + 1];
	int st = 0;
	int cla = dif[0];
	for (i = 1; i < N - 1; i++)
	{
		if (cla != dif[i])
		{
			int ne = i - st + 1;
			rcou[ne]++;
			if (cou[ne])
			{
				if (cou[ne] != max(arr[st], arr[i]))
				{
					diff[ne] = 1;
				}
			}
			else
			{
				cou[ne] = max(arr[st], arr[i]);
			}
			ans = max(ans, ne);
			st = i;
			cla = dif[i];
		}
	}
	i = N - 1;
	int ne = i - st + 1;
	rcou[ne]++;
	if (cou[ne])
	{
		if (cou[ne] != max(arr[st], arr[i]))
		{
			diff[ne] = 1;
		}
	}
	ans = max(ans, ne);
	if (diff[ans])
		cout << 0;
	else
	{
		cout << ((ans % 2)&&(rcou[ans]>1));
	}
}