#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long poww(long long p,long long q)
{
	if (q==0) return 1;
	long long w=poww(p,q/2);
	if (q%2) return ((w*w)%1000000007*p)%1000000007;
	return (w*w)%1000000007;
}
int main()
{
	scanf("%lld %lld",&n,&m);
	ans=poww(poww(2,m)-1,n); 
	cout<<ans<<endl;
	return 0;
}