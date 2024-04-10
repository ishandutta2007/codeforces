#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans[100005];
int n,m,i;
void work(int x)
{
	ans[m++]=(ll)(2+n-x)*n/x/2;
}
int main()
{
	cin>>n;
	for(i=1;i*i<=n;i++)if(n%i==0)
	{
		work(i);
		if(i*i<n)work(n/i);
	}
	sort(ans,ans+m);
	for(i=0;i<m;i++)cout<<ans[i]<<' ';
	return 0;
}