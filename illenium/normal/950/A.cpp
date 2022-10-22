#include<iostream>
#include<cstdio>
using namespace std;

int tmp;

int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int ans,t;
	t=min(a,b);
	a-=t; b-=t;
	ans=t*2;
	if(a==0)
	{
		if(c<=b) tmp=c*2;
		else
		{
			tmp=b*2;
			int p=(c-b)/2;
			tmp+=p*2;
		}
	}
	else
	{
		if(c<=a) tmp=c*2;
		else
		{
			tmp=a*2;
			int p=(c-a)/2;
			tmp+=p*2;
		}
	}
	cout<<ans+tmp;
	return 0;
}