#include<iostream>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	long long b,tb,k,tk,a;
	for(long long i=0;i<n;i++)
	{
		cin>>a;
		if(i==0)
		{
			b=a;
			tb=1;
			k=a;
			tk=1;
		}
		else
		{
			if(a==b)
			{
				tb++;
			}
			if(a>b)
			{
				b=a;
				tb=1;
			}
			if(a==k)
				tk++;
			if(a<k)
			{
				k=a;
				tk=1;
			}
		}
	}
	if(k==b)
		cout<<"0"<<" "<<(tk*(tb-1))/2;
	else
	cout<< b-k<<" "<<tk*tb;
}