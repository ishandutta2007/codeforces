#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
int n,m,i,j,K,N,M,X,h[MAXN],ne[MAXN<<1],p[MAXN<<1],a[MAXN<<1],e[MAXN];
bool b[MAXN];
void dfs(int x)
{
	b[a[++N]=x]=1;
	for(int i=h[x];i;i=ne[i])if(!b[p[i]])
	{
		dfs(p[i]);
		a[++N]=x;
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&K);
	while(m--)
	{
		scanf("%d%d",&i,&j);
		p[++M]=j;
		ne[M]=h[i];
		h[i]=M;
		p[++M]=i;
		ne[M]=h[j];
		h[j]=M;
	}
	dfs(1);
	X=(2*n-1)/K;
	for(i=1;i<=K;i++)e[i]=X;
	N-=X*K;
	for(i=1;i<=N;i++)e[i]++;
	for(i=1;i<=K;i++)e[i]+=e[i-1];
	for(i=1;i<=K;i++,putchar('\n'))for(printf("%d",e[i]-e[i-1]),j=e[i-1]+1;j<=e[i];j++)printf(" %d",a[j]);
	return 0;
}