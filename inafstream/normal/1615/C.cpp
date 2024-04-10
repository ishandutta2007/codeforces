#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int n,m,a[100005],b[100005];


void solve()
{
	int n,i,ans=0x7fffffff;
	scanf("%d",&n);
	rep(i,n)
	{
		char c;while(!isdigit(c=getchar()));
		a[i]=(c&1);
	}
	rep(i,n)
	{
		char c;while(!isdigit(c=getchar()));
		b[i]=(c&1);
	}
	
	int c0=0,c1=0;
	rep(i,n)
	{
		if(a[i]==0&&b[i]==1) c0++;
		if(a[i]==1&&b[i]==0) c1++; 
	}
	
	if((c0+c1)%2==0&&c0==c1) ans=min(ans,c0+c1);
	
	c0=0,c1=0;
	rep(i,n)
	{
		if(a[i]==0&&b[i]==0) c0++;
		if(a[i]==1&&b[i]==1) c1++;
	}
	
	if((c0+c1)%2==1&&c0+1==c1) ans=min(ans,c0+c1);
	
	if(ans==0x7fffffff) puts("-1"); else printf("%d\n",ans); 
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}