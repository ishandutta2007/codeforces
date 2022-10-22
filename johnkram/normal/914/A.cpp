#include<bits/stdc++.h>
using namespace std;
int n,m,i,ans=-1000000000;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m);
		for(i=0;i<=1000;i++)if(i*i==m)break;
		if(i>1000)ans=max(ans,m);
	}
	cout<<ans<<endl;
	return 0;
}