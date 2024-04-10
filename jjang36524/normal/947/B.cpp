#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
int N;
long long temp[100100];
long long tpsum[100100];
long long vol[100100];
vector<pair<int, int>>notfulltime;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	signed i;
	for (i = 0; i < N; i++)
	{
		cin >> vol[i];
	}
	for (i = 0; i < N; i++)
	{
		cin >> temp[i];
	}
	tpsum[0] = temp[0];
	for (i = 1; i < N; i++)
	{
		tpsum[i] += tpsum[i - 1] + temp[i];
	}
	tpsum[N] = tpsum[N - 1];
	for (i = 0; i < N; i++)
	{
		int nt = max(i,lower_bound(tpsum, tpsum + N, vol[i]+(i?tpsum[i-1]:0)) - tpsum);
		notfulltime.push_back({ nt,i });
	}
	sort(notfulltime.begin(), notfulltime.end());
	int whatleft = 0;
	int count = 0;
	for (i = 0; i < N; i++)
	{
		long long nowans = 0;
		count++;
		while (whatleft<N&&notfulltime[whatleft].first == i)
		{
			count--;
			if (i == 0)
			{
				nowans += vol[0];
			}
			else
			{
				nowans += vol[notfulltime[whatleft].second] - tpsum[i - 1] + (i ? tpsum[notfulltime[whatleft].second - 1] : 0);
			}
			whatleft++;
		}
		nowans += temp[i] * count;
		cout << nowans << ' ';
	}
}