#include<iostream>
using namespace std;
int main()
{
	long long n,k,p,o;
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		cin>>k>>p;
		cout<<(k-1)*9+p<<endl;;
	}
}