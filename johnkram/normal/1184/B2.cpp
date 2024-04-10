#include<bits/stdc++.h>
using namespace std;
#define ll long long
int N,M,n,m,w1,w2,i,j,k,d[105][105],u[1005],v[1005],w[1005],x[1005],y[1005],h[1005],ne[1000005],p[1000005],L[1005];
bool b[1005];
bool work(int now)
{
	for(int i=h[now];i;i=ne[i])if(!b[p[i]])
	{
		b[p[i]]=1;
		if(!L[p[i]]||work(L[p[i]]))
		{
			L[p[i]]=now;
			return 1;
		}
	}
	return 0;
}
int main()
{
	scanf("%d%d",&N,&M);
	memset(d,63,sizeof(d));
	for(i=1;i<=N;i++)d[i][i]=0;
	while(M--)
	{
		scanf("%d%d",&i,&j);
		d[i][j]=d[j][i]=1;
	}
	for(k=1;k<=N;k++)for(i=1;i<=N;i++)for(j=1;j<=N;j++)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	scanf("%d%d%d%d",&n,&m,&w1,&w2);
	for(i=1;i<=n;i++)scanf("%d%d%d",u+i,v+i,w+i);
	for(i=1;i<=m;i++)scanf("%d%d",x+i,y+i);
	M=0;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)if(d[u[i]][x[j]]<=w[i]&&v[i]>=y[j])
	{
		p[++M]=j;
		ne[M]=h[i];
		h[i]=M;
	}
	for(i=1,j=0;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		j+=work(i);
	}
	cout<<min((ll)w1*j,(ll)w2*n)<<endl;
	return 0;
}