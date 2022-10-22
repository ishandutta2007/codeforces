#include<iostream>
using namespace std;
int cr(float k)
{
	int t=1;
	while(k/10.0>=1)
	{
		k=k/10.0;
		t++;
	}
	return t;
}
int r(long long x,long long r)
{
	long long y;
	y=x;
	for(int i=0;i<r;i++)
	{
		y=y/10;
	}
	return y%10;
}
int segment(int x)
{
	if(x==1)
		return 2;
	if(x==8)
		return 7;
	if(x==9 || x==6 || x==0)
		return 6;
	if(x==4)
		return 4;
	if(x==7)
	{
		return 3;
	}	
	return 5;
}
int main()
{
	int n1,n2,k=0,l=0;
	cin>>n1>>n2;
	for(int i=n1;i<=n2;i++)
	{
		l=0;
		for(int j=0;j<cr(i);j++)
		{
			//cout<<segment(r(i,j))<<endl;
			k+=segment(r(i,j));
			l+=segment(r(i,j));
		}
		//cout<<i<<"  "<<l<<endl;
	}
	//cout<<cr(11)<<endl;
	cout<<k;
}