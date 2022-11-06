#include<bits/stdc++.h>
using namespace std;
long long T,n,m;
long long pow(long long x,long long y,long long p)
{
    long long ans=1;
	for (;y;y>>=1,x=x*x % p)
	     if (y & 1) ans=ans*x % p;
	return ans;
}
int main()
{
	for (cin>>T;T;T--)
	     {
	     	cin>>n>>m;
	     	cout<<pow(n,m,1000000007)<<endl;
		 }
	return 0;
}