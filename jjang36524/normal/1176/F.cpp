#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int count1[] = { 0,0,0,1,1,2,3 };
int count2[] = { 0,1,0,0,1,0,0 };
int count3[] = { 0,0,1,0,0,0,0 };
long long N;
vector<long long>sor1;
vector<long long>sor2;
vector<long long>sor3;
long long dp[10];
long long newdp[10];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int i;
	for (i = 1; i < 10; i++)
	{
		dp[i] = -(1LL<<60);
		newdp[i] = -(1LL << 60);
	}
	newdp[0] = -(1LL << 60);
	while (N--)
	{
		sor1.clear();
		sor2.clear();
		sor3.clear();
		int n;
		cin >> n;
		for (i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			if (a == 1)
				sor1.push_back(b);
			if (a == 2)
				sor2.push_back(b);
			if (a == 3)
				sor3.push_back(b);
		}
		sort(sor1.begin(), sor1.end());
		sort(sor2.begin(), sor2.end());
		sort(sor3.begin(), sor3.end());
		for (i = 0; i < 7; i++)
		{
			if (sor1.size() < count1[i] || sor2.size() < count2[i] || sor3.size() < count3[i])
				continue;
			int j;
			long long total = 0, ma = 0;
			for (j = 0; j < count1[i]; j++)
			{
				total += sor1[sor1.size() - 1 - j];
				ma = max(ma, sor1[sor1.size() - 1 - j]);
			}
			for (j = 0; j < count2[i]; j++)
			{
				total += sor2[sor2.size() - 1 - j];
				ma = max(ma, sor2[sor2.size() - 1 - j]);
			}
			for (j = 0; j < count3[i]; j++)
			{
				total += sor3[sor3.size() - 1 - j];
				ma = max(ma, sor3[sor3.size() - 1 - j]);
			}
			int totadd = count1[i] + count2[i] + count3[i];
			for (j = 0; j < 10; j++)
			{
				if (j + totadd > 9)
				{
					newdp[j + totadd - 10] = max(newdp[j + totadd - 10], dp[j] + total + ma);
				}
				else
				{
					newdp[j + totadd] = max(newdp[j + totadd], dp[j] + total);
				}
			}
		}
		for (i = 0; i < 10; i++)
		{
			dp[i] = newdp[i];
			newdp[i] = -(1LL << 60);
		}
	}
	long long ans = 0;
	for (i = 0; i < 10; i++)
	{
		ans = max(ans, dp[i]);
	}
	cout << ans;
}