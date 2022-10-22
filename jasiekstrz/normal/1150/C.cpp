#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,a,x,i;
	cin>>n;
	x=0;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		x+=(a==2);
	}
	if(x==0)
	{
		for(i=1;i<=n;i++)
			cout<<"1 ";
		return 0;
	}
	if(x==n)
	{
		for(i=1;i<=n;i++)
			cout<<"2 ";
		return 0;
	}
	cout<<"2 1 ";
	n-=2;
	x--;
	for(i=1;i<=n;i++)
	{
		if(i<=x)
			cout<<"2 ";
		else
			cout<<"1 ";
	}
	return 0;
}