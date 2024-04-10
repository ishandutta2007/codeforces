#include<bits/stdc++.h>
using namespace std;
#define MAXN 400005
int n,m,N,M,i,j,h[MAXN],ne[MAXN],p[MAXN],d[MAXN],q[MAXN],he,ta;
bool b[MAXN];
void dfs(int x)
{
	for(int i=h[x];i;i=ne[i])if(!b[p[i]])
	{
		b[p[i]]=1;
		d[p[i]]=d[x];
		dfs(p[i]);
	}
}
int main()
{
	scanf("%d%d%d",&n,&M,&N);
	while(M--)
	{
		scanf("%d%d",&i,&j);
		p[++m]=j;
		ne[m]=h[i];
		h[i]=m;
		p[++m]=i;
		ne[m]=h[j];
		h[j]=m;
		d[i]++;
		d[j]++;
	}
	if(d[1]<N)
	{
		puts("NO");
		return 0;
	}
	memset(d,0,sizeof(d));
	b[1]=1;
	for(i=h[1],j=0;i;i=ne[i])if(!b[p[i]])
	{
		j++;
		d[p[i]]=p[i];
		dfs(p[i]);
	}
	if(j>N)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	memset(b,0,sizeof(b));
	b[1]=1;
	N-=j;
	for(i=h[1];i;i=ne[i])if(d[p[i]]==p[i])
	{
		printf("1 %d\n",p[i]);
		b[q[ta++]=p[i]]=1;
	}
	else if(N)
	{
		printf("1 %d\n",p[i]);
		b[q[ta++]=p[i]]=1;
		N--;
	}
	while(he!=ta)
	{
		i=q[he++];
		for(j=h[i];j;j=ne[j])if(!b[p[j]])
		{
			printf("%d %d\n",i,p[j]);
			b[q[ta++]=p[j]]=1;
		}
	}
	return 0;
}