#include<bits/stdc++.h>
using namespace std;
int n,m,l,r,mid,p[100],i,j;
void ask(int x)
{
	cout<<x<<endl;
	fflush(stdout);
	cin>>j;
}
int main()
{
	cin>>m>>n;
	for(i=1;i<=n;i++)
	{
		ask(1);
		if(!j)exit(0);
		p[i]=j;
	}
	for(i=l=1,r=m;;i=i%n+1)
	{
		mid=l+r>>1;
		ask(mid);
		j*=p[i];
		if(!j)exit(0);
		if(~j)l=mid+1;
		else r=mid-1;
	}
	return 0;
}