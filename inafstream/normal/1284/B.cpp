#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;
 
long long ans;
int n,m,i,j;
int s[1000005],c[1000005];
 
int main()
{
	scanf("%d",&n);
	ans=1ll*n*n;
	rep(i,n)
	{
		int l,mi=1000001,mx=-1,f=0;
		scanf("%d",&l);
		rep(j,l)
		{
			int x;
			scanf("%d",&x);
			if (x>mi)
			{
				f=1;
			}
			mx=max(mx,x);mi=min(mi,x);
		}
		if (f==0){s[mi]++;c[mx]++;}
	}
	
	for (i=1000000;i>=0;i--)
	{
		if (i!=1000000) s[i]+=s[i+1];
		ans-=1ll*s[i]*c[i];
	}
	
	cout<<ans<<endl;
	return 0;
}