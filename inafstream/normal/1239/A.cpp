#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;

int n,m,f[100005],mod=1e9+7;

int main()
{
	cin>>n>>m;
	
	int i;
	f[0]=f[1]=1;
	for (i=2;i<=100000;i++)
	{
		f[i]=(f[i-1]+f[i-2])%mod;
	}
	
	cout<<(2ll*f[m]+2ll*(f[n]+mod-1ll))%mod<<endl;
	return 0;
}