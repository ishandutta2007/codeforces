#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
#define MOD 1000000007
int N, M, T;
int st[300100];
int cc[256];
vector<pair<int, pair<int, int>>>all;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			int a;
			cin >> a;
			all.push_back({ -a,{i,j} });
		}
	}
	cc[0] = N;
	sort(all.begin(), all.end());
	int ans = 0;
	for (i = 0; i < N * M; i++)
	{
		auto n = all[i];
		int bef = st[n.second.first];
		cc[bef + (1 << n.second.second)]++;
		st[n.second.first] += (1 << n.second.second);
		for (j = 0; j < (1 << M); j++)
		{
			if (cc[j] && cc[(1 << M) - 1 - j])
			{
				int f=0, s=0;
				int k;
				for (k = 0; k < N; k++)
				{
					if ((st[k] & j)==j)
						f = k;
				}
				for (k = 0; k < N; k++)
				{
					if ((st[k] & ((1 << M) - 1 - j))== ((1 << M) - 1 - j))
						s = k;
				}
				cout << f + 1 << ' ' << s + 1;
				return 0;
			}
		}
	}
}