#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int n,m,q,i,j,a[4096],w[20],b[4096][105],d[4096];
char c[20];
int get()
{
	scanf("%s",c);
	reverse(c,c+n);
	int i,j;
	for(i=j=0;i<n;i++)j=j<<1|(c[i]^'0');
	return j;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(i=0;i<n;i++)scanf("%d",w+i);
	while(m--)a[get()]++;
	for(i=0;i<1<<n;i++)for(j=0;j<n;j++)if(!(i>>j&1))d[i]+=w[j];
	for(i=0;i<1<<n;i++)
	{
		for(j=0;j<1<<n;j++)if(d[i^j]<101)b[i][d[i^j]]+=a[j];
		for(j=1;j<101;j++)b[i][j]+=b[i][j-1];
	}
	while(q--)
	{
		i=get();
		scanf("%d",&j);
		printf("%d\n",b[i][j]);
	}
	return 0;
}