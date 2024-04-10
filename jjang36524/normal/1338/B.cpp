#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string.h>
#define int long long
using namespace std;
int N,M,T;
vector<int>t[100100];
int x[100100];
int firstans, secondans;
void df(int n,int p)
{
	int i;
	int rc = 0;
	for (i = 0; i < t[n].size(); i++)
	{
		int ne = t[n][i];
		if (ne == p)
			continue;
		x[ne] = x[n] + 1;
		df(ne, n);
		
	}
	return;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	secondans = N;
	int i;
	for (i = 1; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		t[a].push_back(b);
		t[b].push_back(a);
	}
	
	df(1, 0);
	int havetobe = -1;
	for (i = 1; i <= N; i++)
	{
		int j;
		int rc = 0;
		for (j = 0; j < t[i].size(); j++)
		{
			rc += t[t[i][j]].size() == 1;
		}
		if (rc > 1)
			secondans -= rc - 1;
		if (t[i].size() == 1 )
		{
			if (havetobe == -1)
				havetobe = x[i] % 2;
			else
			{
				if (x[i] % 2 != havetobe)
					firstans = 2;
			}
		}
	}
	cout << firstans + 1 << ' ' << secondans-1;
}