#include<iostream>
using namespace std;
int main()
{
	int n,n1=0,k;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		n1=max(k,n1);
	}
	cout<<n1;
}