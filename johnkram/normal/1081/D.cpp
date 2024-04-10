#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
struct node
{
	int s,t,d;
	bool operator<(const node& y)const
	{
		return d<y.d;
	}
}e[MAXN];
int n,m,i,j,N,f[MAXN],s[MAXN];
int get(int x)
{
	if(f[x]==x)return x;
	return f[x]=get(f[x]);
}
int main()
{
	scanf("%d%d%d",&n,&m,&N);
	for(i=1;i<=N;i++)
	{
		scanf("%d",&j);
		s[j]=1;
	}
	for(i=1;i<=n;i++)f[i]=i;
	for(i=1;i<=m;i++)scanf("%d%d%d",&e[i].s,&e[i].t,&e[i].d);
	sort(e+1,e+m+1);
	for(i=1;i<=m;i++)if(get(e[i].s)!=get(e[i].t))
	{
		s[get(e[i].s)]+=s[get(e[i].t)];
		f[get(e[i].t)]=get(e[i].s);
		if(s[get(e[i].s)]==N)
		{
			while(N--)printf("%d ",e[i].d);
			break;
		}
	}
	return 0;
}