#include<iostream>
using namespace std;
int abs(int n)
{
	if(n<0)
		return n*-1;
	return n;
}
int r(long long x,long long r)
{
	x=abs(x);
	long long y;
	y=x;
	for(int i=0;i<r;i++)
	{
		y=y/10;
	}
	return y%10;
}
int check(int x)
{
	for(int i=0;i<10;i++)
	{
		if((r(x,i))==8)
			return 1;
	}
	return 0;
}
int main(){
	long long f,t=1;
	cin>>f;
	f++;
	while(check(f)==0)
	{
		f++;
		t++;
	}
	cout<<t;
}