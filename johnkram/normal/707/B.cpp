#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<queue>
using namespace std;
#define MAXN 100005
#define ll long long
struct node
{
	ll x;
	int y;
	bool operator<(node b)const
	{
		return x>b.x;
	}
}a,t;
priority_queue<node> H;
int n,m,N,M,i,j,k,h[MAXN],ne[MAXN<<1],p[MAXN<<1],w[MAXN<<1];
ll d[MAXN],ans;
bool b[MAXN];
int main()
{
	scanf("%d%d%d",&n,&m,&N);
	while(m--)
	{
		scanf("%d%d%d",&i,&j,&k);
		p[++M]=j;
		ne[M]=h[i];
		w[M]=k;
		h[i]=M;
		p[++M]=i;
		ne[M]=h[j];
		w[M]=k;
		h[j]=M;
	}
	memset(d,127,sizeof(d));
	while(N--)
	{
		scanf("%d",&i);
		b[i]=1;
		d[i]=0;
		a.x=0;
		a.y=i;
		H.push(a);
	}
	while(!H.empty())
	{
		a=H.top();
		H.pop();
		if(a.x!=d[a.y])continue;
		for(i=h[a.y];i;i=ne[i])if(d[p[i]]>a.x+w[i])
		{
			t.x=d[p[i]]=a.x+w[i];
			t.y=p[i];
			H.push(t);
		}
	}
	ans=d[0];
	for(i=1;i<=n;i++)if(!b[i])ans=min(ans,d[i]);
	if(ans==d[0])ans=-1;
	cout<<ans<<endl;
	return 0;
}