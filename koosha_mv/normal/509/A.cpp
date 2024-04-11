using namespace std;
#include<iostream>
long long e(long long n1,long long n2)
{
	long long t=1,t1=1,t2=1;
	for(long long i=1;i<=n2;i++)
	{
		t=t*i;
	}
	for(long long i=1;i<=n2-n1;i++)
	{
		t1=t1*i;
	}
	for(long long i=1;i<=n1;i++)
	{
		t2=t2*i;
	}
	return t/(t1*t2);
	
}
int main()
{
	long long n;
	cin>>n;
	//cout<<e(2,4);
	cout<<e(n-1,2*(n-1));
}