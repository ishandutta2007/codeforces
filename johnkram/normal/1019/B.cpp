#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a[100005],l,r,m,x,y;
void ask(int i)
{
	cout<<"? "<<i<<endl;
	fflush(stdout);
	cin>>a[i];
}
int main()
{
	cin>>n;
	if(n&3)
	{
		cout<<"! -1"<<endl;
		fflush(stdout);
		return 0;
	}
	ask(1);
	ask(1+(n>>1));
	if(a[1]==a[1+(n>>1)])
	{
		cout<<"! 1"<<endl;
		fflush(stdout);
		return 0;
	}
	l=1;
	r=1+(n>>1);
	x=a[1]-a[1+(n>>1)];
	y=-x;
	for(;;)
	{
		m=l+r>>1;
		ask(m);
		ask(m+(n>>1));
		if(a[m]==a[m+(n>>1)])
		{
			cout<<"! "<<m<<endl;
			fflush(stdout);
			return 0;
		}
		else if((ll)(a[m]-a[m+(n>>1)])*x<0)
		{
			r=m;
			y=a[m]-a[m+(n>>1)];
		}
		else
		{
			l=m;
			x=a[m]-a[m+(n>>1)];
		}
	}
	return 0;
}