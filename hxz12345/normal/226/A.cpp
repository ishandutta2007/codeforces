#include<bits/stdc++.h>
using namespace std;
long long n,MOD;
long long pow(long long x,long long y,long long p)
{
	long long ans=1;
	for (;y;y>>=1,x=x*x % MOD)
	   if (y&1) ans=ans*x % MOD;
	return ans;
}
int main()
{
	cin>>n>>MOD;
	n=pow(3,n,MOD);
	if (n==0) n=MOD-1;
	else n=n-1;
	cout<<n<<endl;
	return 0;
}