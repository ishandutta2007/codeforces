#include<iostream>
using namespace std;
int t(int x)
{
	if(x<0)
		return 0;
	return x;
}
int main()
{
	int a1,a2,k1,k2,n,tt=0;
	cin>>a1>>a2>>k1>>k2>>n;
	cout<<t(n-((a1*k1+a2*k2)-(a1+a2)))<<" ";
	if(k1<k2)
	{
		tt+=int(n/(k1));
		if(tt>a1)
		{
			tt=a1;
			n-=a1*k1;
			tt+=int(n/(k2));
		}
		else
		{
			n=n%k1;
		}
		
	}
	else
	{
		int t2;
		t2=k1;
		k1=k2;
		k2=t2;
		t2=a1;
		a1=a2;
		a2=t2;
		tt+=int(n/(k1));
		if(tt>a1)
		{
			tt=a1;
			n-=a1*k1;
			tt+=int(n/(k2));
		}
		else
		{
			n=n%k1;
		}
	}
	cout<<tt;
}