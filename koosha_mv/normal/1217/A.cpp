#include<iostream>
using namespace std;
int t(int x,int y,int z)
{
	int l,p;
	if(x>y)
	{
		l=x-(y+1);
		p=(z-l)/2;
		if(z-l<0)
			return z+1;
		return p+l+1;
	}
	if(z+x>y)
	{
		z-=(y-x)+1;
		x=y+1;
		return t(x,y,z);
	}
	return 0;
}
int main()
{
	int n;
	cin >>n;
	int t1,t2,t3;
	for(int i=0;i<n;i++)
	{
		cin>>t1>>t2>>t3;
		cout<<t(t1,t2,t3)<<endl;
	}	
}