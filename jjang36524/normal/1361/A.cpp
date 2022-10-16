#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
int N, M, T;
vector<pair<int,int>>t;
vector<int>arr[1000100];
int v[1001000];
int r[1000100];
int a[1000100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N>>M;
	int i;
	for (i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for (i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		t.push_back({ a,i+1 });
		r[i+1] = a;
	}
	sort(t.begin(), t.end());
	for (i = 0; i < N; i++)
	{
		int j;
		for (j = 0; j < arr[t[i].second].size(); j++)
		{
			if(a[arr[t[i].second][j]])
				v[r[arr[t[i].second][j]]-1]++;
		}
		for (j = 0; j < arr[t[i].second].size(); j++)
		{
			if (!v[j])
				break;
		}
		if (j+1 != r[t[i].second])
		{
			cout << -1;
			return 0;
		}
		for (j = 0; j < arr[t[i].second].size(); j++)
		{
			if (a[arr[t[i].second][j]])
				v[r[arr[t[i].second][j]]-1]--;
		}
		a[t[i].second] = 1;
	}
	for (i = 0; i < N; i++)
	{
		cout << t[i].second << ' ';
	}
}