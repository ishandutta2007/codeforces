// Hydro submission #6263f367255d14008c26c143@1650717543720
#include<bits/stdc++.h>
using namespace std;
struct USE{
	int start;
	int end;
	int seconds;
}a[105];
int p1,p2,p3,t1,t2,n,ans=0;
int main()
{
	cin>>n>>p1>>p2>>p3>>t1>>t2;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].start>>a[i].end;
		a[i].seconds=a[i].end-a[i].start;
		ans+=a[i].seconds*p1;
	}
	for(int i=1;i<n;i++)
	{
		int t=a[i+1].start-a[i].end;
		if(t<=t1) ans+=p1*t;
		else if(t>t1 && t<=t2+t1) ans+=p1*t1+p2*(t-t1);
		else ans+=p1*t1+p2*t2+p3*(t-t1-t2);
	}
	cout<<ans;
	return 0;
}