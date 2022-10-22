#include<iostream>
using namespace std;
string t( long long x)
{
	if(x==1)
		return "NO";
	return "YES";
	
}
int main()
{
	 long long l,x,y;
	cin>>l;
	for( long long i=0;i<l;i++)
	{
		cin>>x>>y;
		cout<<t(x-y)<<endl;
	}
}