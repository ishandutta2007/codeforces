#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	long n;
	long long k,a,b,m=0;
	cin>>n;
	cin>>k;
	cin>>a>>b;
	if(b>k)
		m=a-b+k;
	else
		m=a;
	for(long i=1;i<n;i++)
	{
		cin>>a>>b;
		if(b>k)
			if((a-b+k)>m)
				m=a-b+k;
		if(b<=k) 
			if(a>m)
				m=a;
	}
	cout<<m;
}