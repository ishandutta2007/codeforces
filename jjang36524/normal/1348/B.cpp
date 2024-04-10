#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define int long long
using namespace std;
int T, N;
int arr[101];
vector<int>p;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		p.clear();
		int K;
		memset(arr, 0, sizeof(arr));
		cin >> N>>K;
		int i;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			if (!arr[a])
			{
				arr[a] = 1;
				p.push_back(a);
			}
		}
		if (p.size() > K)
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << N* K<<'\n';
			for (i = 0; i < N; i++)
			{
				int j;
				for (j = 0; j <K; j++)
				{
					cout << p[min((long long)p.size()-1,j)] << ' ';
				}
			}
			cout << '\n';
		}
	}
}