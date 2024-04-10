#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool b[1000005];
int n=1000000,m,i,j,ans,p[1000005],a[1000005];
int main()
{
	for(i=2;i<=n;i++)
	{
		if(!b[i])a[p[m++]=i]=i;
		for(j=0;j<m&&i*p[j]<=n;j++)
		{
			b[i*p[j]]=1;
			a[i*p[j]]=a[i];
			if(i%p[j]==0)break;
		}
	}
	cin>>n;
	for(i=m-1;~i;i--)if(n%p[i]==0)break;
	ans=n;
	for(i=n-p[i]+1;i<=n;i++)if(b[i])ans=min(ans,i-a[i]+1);
	else ans=min(ans,i);
	cout<<ans<<endl;
	return 0;
}