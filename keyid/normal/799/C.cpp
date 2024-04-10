#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005;

int C[MAXN],D[MAXN];

void add(int C[],int x,int d)
{
	for (;x<=100000;x+=x&-x)
		C[x]=max(C[x],d);
}

int query(int C[],int x)
{
	int ret=INT_MIN;
	for (;x;x-=x&-x)
		ret=max(ret,C[x]);
	return ret;
}

int main()
{
	int n,c,d;
	scanf("%d%d%d",&n,&c,&d);
	char typ[5];
	fill(C,C+MAXN,INT_MIN);
	fill(D,D+MAXN,INT_MIN);
	int ans=0;
	for (int i=0;i<n;i++)
	{
		int b,p,ret;
		scanf("%d%d%s",&b,&p,typ);
		if (typ[0]=='C')
		{
			if (p>c) continue;
			ret=max(query(C,c-p),query(D,d));
			add(C,p,b);
		}
		else
		{
			if (p>d) continue;
			ret=max(query(C,c),query(D,d-p));
			add(D,p,b);
		}
		ans=max(ans,ret+b);
	}
	printf("%d",ans);
	return 0;
}