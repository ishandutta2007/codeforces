#include<iostream>
using namespace std;
int main()
{
	long long n,m,k=0;
	cin>>n>>m;
	if(m<=(n+1)/2)
	{
		cout<<m*2-1;
	}
	else
	{
		if(n%2==0)
			cout<<(m-(n/2))*2;
		else
			cout<<(m-(n+1)/2)*2;
	}
	
}