#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1005;
int n,m,v[MAXN],i,j,ans;
int main()
{
	//freopen("250_c.in","r",stdin);
	//freopen("250_c.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",v+i);
	while(m--)
	{
		scanf("%d%d",&i,&j);
		ans+=min(v[i],v[j]);
	}
	printf("%d",ans);
	return 0;
}