#include <iostream>
using namespace std;
int nowdptable[209];
int dppreparedvalue[209];
int N;
#include <vector>
#include <algorithm>
#include <string.h>
vector<pair<int, int>>things;
int sum;
int main()
{
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		things.push_back({ a,b });
		sum += b;
	}
	memset(dppreparedvalue, -10, sizeof(dppreparedvalue));
	memset(nowdptable, -10, sizeof(nowdptable));
	dppreparedvalue[0] = 0;
	for (i = 0; i < N; i++)
	{
		int j;
		for (j = 0; j < things[i].first; j++)
		{
			nowdptable[j] = dppreparedvalue[j];
		}
		for (j = 0; j <= 2 * N; j++)
		{
			nowdptable[j + things[i].first] = max(dppreparedvalue[j + things[i].first], dppreparedvalue[j] + things[i].second);
		}
		for (j = 0; j <= 2 * N; j++)
		{
			dppreparedvalue[j] = nowdptable[j];
			nowdptable[j] = 0xF6F6F6F6;
		}
	}
	for (i = 1; i <= 2 * N; i++)
	{
		if (i>=(sum-dppreparedvalue[i]))
		{
			cout << i;
			return 0;
		}
	}
}