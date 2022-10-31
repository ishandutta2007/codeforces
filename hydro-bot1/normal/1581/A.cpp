// Hydro submission #625793ec17cd4d0a41786f24@1649906669062
#include<bits/stdc++.h>
using namespace std;
long long f(int n)
{
	long long s=1,i;
	for(i=3;i<=2*n;i++)
	s=s*i%1000000007;
	return s;
}
int main()
{
    long long t,i;
    int n;cin>>t;
	for(i=1;i<=t;i++)
	{
	    cin>>n;
		printf("%lld\n",f(n));
	}
	return 0;
}