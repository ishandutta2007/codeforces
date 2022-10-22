#include<iostream>
using namespace std;
int a[1000000]={0};
int main()
{
	int n,m=0,am;
	cin>>n;
	cout<<n<<" ";
	for(int i=2;i<=n;i++)
	{
		int t=0;
		while(n%i==0)
		{
			n=n/i;
			cout<<n<<" ";
		}
	}
}