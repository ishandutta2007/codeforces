#include<bits/stdc++.h>
using namespace std;
int n,a[100005],ne[100005],p[100005];
 
int main()
{
	freopen("input.txt","r+",stdin);
	freopen("output.txt","w+",stdout);
	cin>>n;
	for(int i =1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
		if(a[i]>=0)
			ne[i]=ne[i-1]+1;
	else
		ne[i]=ne[i-1];
	for(int i=n;i>=1;i--)
		if(a[i]<=0)
			p[i]=p[i+1]+1;
	else
		p[i]=p[i+1];
	int ans=INT_MAX;
	for(int i=2;i<=n;i++)
		ans=min(ans,ne[i-1]+p[i]);
	cout<<ans<<endl;
 
	return 0;
}