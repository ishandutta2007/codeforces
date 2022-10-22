#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,x,i,j,s,a[2][1024];
int main()
{
	scanf("%d%d%d",&n,&m,&x);
	while(n--)
	{
		scanf("%d",&i);
		a[0][i]++;
	}
	for(i=0;i<m;i++)for(fill(a[!(i&1)],a[!(i&1)]+1024,j=s=0);j<1024;s+=a[i&1][j++])
	{
		a[!(i&1)][j]+=a[i&1][j]+(s&1)>>1;
		a[!(i&1)][j^x]+=a[i&1][j]+(!(s&1))>>1;
	}
	for(i=0;i<1024;i++)if(a[m&1][i])break;
	for(j=1023;~j;j--)if(a[m&1][j])break;
	cout<<j<<' '<<i<<endl;
	return 0;
}