#include<iostream>
using namespace std;
int main()
{
	int n,k;
	cin>>n;
	k=int(n/2)+1;
	cout<<k<<endl;
	int i=1,j=1;
	for(int i=1;i<=k;i++)
	{
		cout<<i<<" "<<j<<endl;
	}
	if(n%2==0)
	{
		for(int j=2;j<=k-1;j++)
			cout<<k<<" "<<j<<endl;
	}
	else
	{
		for(int j=2;j<=k;j++)
			cout<<k<<" "<<j<<endl;
	}
}