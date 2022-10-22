#include<bits/stdc++.h>
using namespace std;
#define MAXN 400005
int n,m,M,i,j,h[MAXN],ne[MAXN],p[MAXN],d[MAXN],q[MAXN],he,ta;
bool b[MAXN];
int main()
{
	scanf("%d%d",&n,&M);
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
	for(i=j=1;i<=n;i++)if(d[i]>d[j])j=i;
	b[q[ta++]=j]=1;
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