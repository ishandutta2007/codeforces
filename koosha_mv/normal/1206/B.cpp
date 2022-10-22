using namespace std;
#include<iostream>
int main()
{
	long long n,i;
	cin>>n;
	long long t=0,m=0,s=0;
	for(int j=0;j<n;j++)
	{
		cin>>i;
		if(i>=1)
			t+=i-1;
		if(i<=-1)
		{
			m++;
			t+=-1-i;
		}
		if(i==0)
		{
			s=1;
			t++;
		}
	}
	if(s>0)
		cout<<t;
	else
		if(m%2==0)
			cout<<t;
		else
			cout<<t+2;
	
}