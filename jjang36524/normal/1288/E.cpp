#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
#define MOD 1000000007
int N, M, T;
vector<int>talks;
vector<int>gt[300100];
int ami[300100],ama[300100];
vector<pair<pair<int, int>, pair<int, int>>>mosready;
int coun[1010010];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	int i;
	int sq = sqrt(N);
	for (i = 0; i < N; i++)
	{
		talks.push_back(N - i);
		gt[N - i].push_back(i);
	}
	for (i = 0; i < M; i++)
	{
		int a;
		cin >> a;
		talks.push_back(a);
		gt[a].push_back(i + N);
	}
	for (i = 1; i <= N; i++)
	{
		gt[i].push_back(N + M);
		if (gt[i].size() > 2)
		{
			ami[i] = 1;
		}
		else
		{
			ami[i] = i;
		}
		int k;
		for (k = 1; k < gt[i].size(); k++)
		{
			mosready.push_back({ {(gt[i][k-1]+1) / sq,gt[i][k] -1},{i,gt[i][k-1]+1} });
		}
	}
	sort(mosready.begin(), mosready.end());
	int nows = 0;
	int nowe = -1;
	int a = 0;
	for (i = 0; i < mosready.size(); i++)
	{
		int news = mosready[i].second.second;
		int newe = mosready[i].first.second;
		register int j;
		if (nowe > newe)
		{
			for (j = newe + 1; j <= nowe; j++)
			{
				coun[talks[j]]--;
				if (coun[talks[j]] == 0)
					a--;
			}
		}
		if (nowe < newe)
		{
			for (j = nowe + 1; j <= newe; j++)
			{
				coun[talks[j]]++;
				if (coun[talks[j]] == 1)
					a++;
			}
		}
		if (nows > news)
		{
			for (j = news; j < nows; j++)
			{
				coun[talks[j]]++;
				if (coun[talks[j]] == 1)
					a++;
			}
		}
		if (nows < news)
		{
			for (j = nows; j < news; j++)
			{
				coun[talks[j]]--;
				if (coun[talks[j]] == 0)
					a--;
			}
		}
		ama[mosready[i].second.first] = max(ama[mosready[i].second.first],a+1);
		nows = news;
		nowe = newe;
	}
	for (i = 1; i <= N; i++)
	{
		cout << ami[i] << ' ' << ama[i]<<'\n';
	}
}