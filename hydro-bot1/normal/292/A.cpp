// Hydro submission #6253d09748f783013279274d@1649660055941
#include<bits/stdc++.h>
using namespace std;
int mx,x,s;
int main()
{
	int n,i,t,c;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>t>>c;x-=t-s;
		if(x<0) x=0;x+=c;
		mx=max(mx,x);s=t;
	}
	printf("%d %d\n",s+x,mx);
	return 0;
}