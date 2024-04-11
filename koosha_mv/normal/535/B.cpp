#include<iostream>
using namespace std;
long long r2=0;
long long tavan(long long x,long long y)
{
	long long o=1;
	for(long long i=0;i<y;i++)
		o*=x;
	return o;
}
long long r(long long x,long long r)
{
	long long y;
	y=x;
	for(long long i=0;i<r;i++)
	{
		y=y/10;
	}
	return y%10;
}
long long h(int n)
{
	return tavan(2,n)+h(n-1);
}
long long t(long long n)
{
	if(n<10)
		return 1;
	return t(n/10)+1;
}
long long checkk(long long x)
{
	for(long long i=0;i<t(x);i++)
	{
		if(r(x,i)!=7 && r(x,i)!=4)
		{
			return 0;
		}
	}
	return 1;
}
long long gg(long long n,long long n1)
{
	if(t(n1)==t(n))
	{
		if(n1<=n)
		{
			//cout<<n1<<endl;
			r2++;
		}
	}
	else
	{
		gg(n,n1+(4*(tavan(10,(t(n1))))));
		gg(n,n1+(7*(tavan(10,t(n1)))));
	}
}
int main()
{
	long long n,k=0,l;
	cin>>n;
	for(int i=1;i<t(n);i++)
		k+=tavan(2,i);
	gg(n,4);
	gg(n,7);
	cout<<r2+k;
}