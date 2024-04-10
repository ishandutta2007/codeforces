#include <bits/stdc++.h>
using namespace std;

int n,d,e,ans,i,j;

int main()
{
	scanf("%d%d%d",&n,&d,&e);
	e*=5;
	
	ans=n;
	for(i=0;i*e<=n;i++){
		ans=min(ans,n-i*e-((n-i*e)/d*d));
	}
	
	cout<<ans<<endl;
	
	return 0;
}