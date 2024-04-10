#include <iostream>
#include <vector>
#define int long long
using namespace std;
int N;
int arr[100100][3];
vector<int>links[200100];
int treenum[200100];
int ch[100100];
int mi, fx, fy;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 1; j <= N; j++)
		{
			cin >> arr[j][i];
		}
	}
	for (i = 1; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		links[a].push_back(b);
		links[b].push_back(a);
	}
	int startnode;
	for (i = 1; i <= N; i++)
	{
		if (links[i].size() == 1)
			startnode = i;
		if (links[i].size() >= 3)
		{
			cout << -1;
			return 0;
		}
	}
	int bef = 0;
	int now = startnode;
	treenum[0] = now;
	for (i = 1; i < N; i++)
	{
		if (links[now][0] == bef)
		{
			bef = now;
			now = links[now][1];
		}
		else
		{
			bef = now;
			now = links[now][0];
		}
		treenum[i] = now;
	}
	int k;
	mi = 1LL << 50;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (i == j)
				continue;
			int nowans =arr[treenum[0]][i]+arr[treenum[1]][j];
			int b1c=i, b2c=j;
			for (k = 2; k < N; k++)
			{
				if (b1c + b2c == 1)
					nowans += arr[treenum[k]][2];
				else if(b1c+b2c==2)
					nowans += arr[treenum[k]][1];
				else
					nowans += arr[treenum[k]][0];
				int ne = 3 - b1c - b2c;
				b1c = b2c;
				b2c = ne;
			}
			if (mi > nowans)
			{
				mi = nowans;
				fx = i;
				fy = j;
			}
		}
	}
	cout << mi << '\n';
	int b1c = fx, b2c = fy;
	ch[treenum[0]] = fx;
	ch[treenum[1]] = fy;
	for (k = 2; k < N; k++)
	{
		ch[treenum[k]] = 3 - b1c - b2c;
		int ne = 3 - b1c - b2c;
		b1c = b2c;
		b2c = ne;
	}
	for (i = 1; i <= N; i++)
	{
		cout << ch[i]+1 << ' ';
	}
}