#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=100005;

int MOD,a[MAXN],b[MAXN];
bool vis[MAXN*2];

int get_inv(int x)
{
	if (x==1)
		return 1;
	return (LL)(MOD-MOD/x)*get_inv(MOD%x)%MOD;
}

void work(int a[],int n,int &x,int &d)
{
	if (n==0)
	{
		x=0;
		d=1;
	}
	else if (n==1)
	{
		x=a[0];
		d=1;
	}
	else
	{
		sort(a,a+n);
		int df=(a[0]-a[1]+MOD)%MOD,cnt=0;
		for (int i=0;i<n;i++)
			if (binary_search(a,a+n,(a[i]+df)%MOD))
				cnt++;
		if (cnt>=n)
		{
			x=-1;
			return;
		}
		d=(LL)df*get_inv(n-cnt)%MOD;
		int mns=0,add=0,now=a[0];
		for (;;)
		{
			now=(now-d+MOD)%MOD;
			if (!binary_search(a,a+n,now))
				break;
			mns--;
		}
		now=a[0];
		for (;;)
		{
			now=(now+d)%MOD;
			if (!binary_search(a,a+n,now))
				break;
			add++;
		}
		if (add-mns+1==n)
			x=(a[0]+(LL)mns*d%MOD+MOD)%MOD;
		else
			x=-1;
	}
}

int main()
{
	int n;
	scanf("%d%d",&MOD,&n);
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int x,d;
	if (2*n-1<=MOD)
		work(a,n,x,d);
	else
	{
		for (int i=0;i<n;i++)
			vis[a[i]]=true;
		int cnt=0;
		for (int i=0;i<MOD;i++)
			if (!vis[i])
				b[cnt++]=i;
		work(b,cnt,x,d);
		if (x!=-1)
			x=(x-(LL)n*d%MOD+MOD)%MOD;
	}
	if (x!=-1)
		printf("%d %d",x,d);
	else
		printf("-1");
	return 0;
}