#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n,ans=0;
	cin>>n;
	for(int i=2;i*i<=n;i++) if(n%i==0) ans+=2;
	if(sqrt(n)==floor(sqrt(n))) ans--;
	cout<<ans+1;
	return 0;
}