#include <bits/stdc++.h>
using namespace std;

int k,cnt[4];
bool ok[1<<4];

bool dfs(int cur,int sum)
{
	if (cur==(1<<k))
	{
		if (sum==0)
			return false;
		for (int i=0;i<k;i++)
			if (cnt[i]*2>sum)
				return false;
		return true;
	}
	if (dfs(cur+1,sum))
		return true;
	if (ok[cur])
	{
		for (int i=0;i<k;i++)
			if (cur>>i&1)
				cnt[i]++;
		if (dfs(cur+1,sum+1))
			return true;
		for (int i=0;i<k;i++)
			if (cur>>i&1)
				cnt[i]--;
	}
	return false;
}

int main()
{
	int n;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++)
	{
		int x=0;
		for (int j=0;j<k;j++)
		{
			int s;
			scanf("%d",&s);
			x|=(s<<j);
		}
		ok[x]=true;
	}
	if (dfs(0,0))
		printf("YES");
	else
		printf("NO");
	return 0;
}