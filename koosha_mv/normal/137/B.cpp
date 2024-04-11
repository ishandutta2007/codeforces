#include<iostream>
using namespace std;
bool a[5002];
int main()
{
	int n,k;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		a[k]=true;
	}
	int p=0;
	for(int i=1;i<n+1;i++)
	{
		if(a[i]==false)
			p++;
	}
	cout<<p;
}