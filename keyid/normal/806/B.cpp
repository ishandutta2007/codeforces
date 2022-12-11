#include <bits/stdc++.h>
using namespace std;

const int MAXN=125,sco[6]={500,1000,1500,2000,2500,3000};

int n,a[MAXN][5],cnt[5],state[5],ans=1000000000;

int cal(int a[5])
{
	int ret=0;
	for (int i=0;i<5;i++)
		if (a[i]!=-1)
			ret+=sco[state[i]]-sco[state[i]]/250*a[i];
	return ret;
}

void check(int x)
{
	if (cal(a[0])<=cal(a[1]))
		return;
	int l[5],r[5],t=n+x;
	for (int i=0;i<5;i++)
	{
		if (state[i]<5) l[i]=t/(1<<(state[i]+1))+1;
		else l[i]=0;
		r[i]=t/(1<<state[i]);
		if (l[i]>r[i]) return;
	}
	for (int i=0;i<5;i++)
		if (cnt[i]>r[i])
			return;
	for (int i=0;i<5;i++)
	{
		l[i]=max(0,l[i]-cnt[i]);
		r[i]=r[i]-cnt[i];
		r[i]=min(x,r[i]);
		if (a[0][i]==-1) r[i]=0;
		if (l[i]>r[i]) return;
	}
	ans=min(ans,x);
}

void dfs(int cur)
{
	if (cur==5)
	{
		for (int i=0;i<=4000&&i<ans;i++)
			check(i);
		return;
	}
	for (int i=0;i<6;i++)
	{
		state[cur]=i;
		dfs(cur+1);
	}
}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		for (int j=0;j<5;j++)
			scanf("%d",&a[i][j]);
	for (int i=0;i<n;i++)
		for (int j=0;j<5;j++)
			if (a[i][j]!=-1)
				cnt[j]++;
	dfs(0);
	printf("%d",ans<1000000000?ans:-1);
	return 0;
}