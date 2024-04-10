#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,i,j,as;
long long a[N],b[N],ans,ta[N],tb[N];
string h;
bool GCD(long long a,long long b,long long x,long long y)
{
	if(b==0)
		return false;
	if(a<b)
		swap(a,b);
	if(x<y)
		swap(x,y);
	if(a==x&&b==y)
		return true;
	if(a<=x&&b<=y)
		return false;
	if(b==y&&(a-x)%b==0)
	{
		ans+=(a-x)/b;
		return true;
	}
	ans+=a/b;
	return GCD(b,a%b,x,y);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
		ta[i]=a[i];
	}
	for(i=1;i<=n;++i)
	{
		scanf("%lld",&b[i]);
		tb[i]=b[i];
	}
	if(n==1)
	{
		if(a[1]!=b[1])
			puts("IMPOSSIBLE");
		else
			puts("SMALL\n0");
		return 0;
	}
	while(1)
	{
		for(i=1;i<=n;++i)
			if(b[i]<=0)
			{
				puts("IMPOSSIBLE");
				return 0;
			}
		for(i=1;i<=n;++i)
			if(b[i]!=a[i])
				break;
		if(i>n)
			break;
		for(i=1;i<=n;++i)
			if(b[i]!=a[n-i+1])
				break;
		if(i>n)
		{
			h+='R';
			break;
		}
		if(b[1]>b[2])
		{
			reverse(b+1,b+1+n);
			h+='R';
		}
		for(i=n;i>=2;--i)
			b[i]-=b[i-1];
		h+='P';
		++as;
		if(as>200000)
			if(n==2)
				break;
	}
	if(as>200000)
	{
		if(n!=2)
		{
			puts("BIG");
			printf("%d",as);
		}
		else
		{
			ans=0;
			if(GCD(tb[1],tb[2],ta[1],ta[2]))
			{
				puts("BIG");
				cout<<ans;
			}
			else
				puts("IMPOSSIBLE");
		}
	}
	else
	{
		puts("SMALL");
		printf("%d\n",h.size());
		for(i=h.size()-1;i>=0;--i)
			printf("%c",h[i]);
	}
}