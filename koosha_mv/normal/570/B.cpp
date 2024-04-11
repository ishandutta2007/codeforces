#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	if(m==1 && n==1)
	{
		cout<<1;
		return 0;
	}
	if(n-m>m-1)
	{
		cout<<m+1;
	}
	else
		cout<<m-1;
}