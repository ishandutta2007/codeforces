#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
vector<int> d[MAXN];
int n,m,i,j,k,a[MAXN],b[MAXN];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		a[i]=n-a[i];
		d[a[i]].push_back(i);
	}
	for(i=1;i<=n;i++)if(d[i].size()%i)
	{
		puts("Impossible");
		return 0;
	}
	else if(d[i].size())for(j=0;j<d[i].size();j+=i)for(m++,k=0;k<i;k++)b[d[i][j+k]]=m;
	puts("Possible");
	for(i=1;i<=n;i++)cout<<b[i]<<' ';
	return 0;
}