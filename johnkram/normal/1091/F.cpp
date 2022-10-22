#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll a[MAXN],b[MAXN],s,ans,x,y,z;
char c[MAXN];
int n,i,j,w[MAXN];
multiset<ll> t;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%I64d",a+i);
	scanf("%s",c+1);
	w[0]=3;
	for(i=1,j=0;i<=n;i++)
	{
		if(c[i]=='G')w[i]=2;
		else if(c[i]=='W')w[i]=1;
		if(w[i]&&w[i]<w[j])j=i;
		if(w[i])s+=a[i];
		else if(s>=a[i])s-=a[i];
		else
		{
			a[j]+=a[i]-s;
			s=0;
		}
	}
	for(i=1;i<=n;i++)ans+=(2*w[i]+1)*a[i];
	for(i=1;i<=n;i++)a[i]<<=1;
	for(i=1,s=0;i<=n;i++)if(w[i])
	{
		if(x&&w[i]==2)
		{
			z=min(max(a[i]-s,0LL)>>1,x);
			s+=z<<1;
			x-=z;
		}
		z=min(a[i],s)+a[i]>>1;
		if(w[i]==1)x+=z;
		else y+=z;
		s=s-min(s,a[i]);
	}
	else if(s>=a[i])s-=a[i];
	else
	{
		z=min(a[i]-s>>1,x);
		x-=z;
		s+=z<<1;
		if(s>=a[i])
		{
			s-=a[i];
			continue;
		}
		z=a[i]-s>>1;
		y-=z;
		s+=z<<1;
		s-=a[i];
	}
	cout<<ans-x-2*y<<endl;
	return 0;
}