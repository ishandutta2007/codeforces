#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,l,r,i,j,x,ans=-1;
void work(ll x)
{
	if(x>n&&x<=2*n)ans=max(ans,x-n);
}
int main()
{
	cin>>n>>l>>r>>m;
	r=(r-l+1+n)%n;
	if(m<r)
	{
		puts("-1");
		return 0;
	}
	for(i=n;i<=m&&i<=2*n;i=j+1)
	{
		j=min(2*n,m/(m/i));
		x=min(2*n,min((m-r)/(m/i),(m+2*n-2*r+1)/(m/i+1)));
		if(x>=i&&m-m/i*x<=r+min(r,x-n))ans=x-n;
	}
	if(!r)for(i=1;i*i<=m+1;i++)if((m+1)%i==0)
	{
		work(i);
		work((m+1)/i);
	}
	if(m>=r&&m<=2*r)ans=max(ans,m+(m<2*r)+n-2*r);
	cout<<ans<<endl;
	return 0;
}