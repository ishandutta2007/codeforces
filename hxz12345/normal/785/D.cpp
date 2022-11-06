#include <bits/stdc++.h>
using namespace std;
string s;
long long x,fac[2001010],ifac[2001010],inv[2001010],f[2001010],suf[2001010],n,MOD,ans,i;
long long C(long long n,long long m)
{
	return fac[n]*ifac[n-m] % MOD*ifac[m] % MOD;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie();cout.tie();
	cin>>s;n=s.size();MOD=1e9+7;
	fac[0]=1;fac[1]=1;inv[1]=1;
	for (i=2;i<=1000000;i++) fac[i]=fac[i-1]*i % MOD,inv[i]=(MOD-MOD/i)*inv[MOD % i] % MOD;
    ifac[0]=1;
    for (i=1;i<=1000000;i++) ifac[i]=ifac[i-1]*inv[i] % MOD; 
	for (i=1;i<=n;i++)
	    if (s[i-1]==')') f[i]=1;
	else f[i]=2;
	for (i=n;i>=1;i--) suf[i]=suf[i+1]+(f[i]==1);
	for (i=1;i<=n;i++)
	    if (s[i-1]=='(')
	        {
	        	x++;
	        	//C(x-1+suf[i],
	        	//C(x-1,j)*C(suf[i],j+1)
	        	//(1+x-1)^x-1=
	        	/*for (j=0;j<=x-1;j++)
	        	    ans=ans+C(x-1,j)*C(suf[i],suf[i]-j-1);*/
	        	ans=(ans+C(x-1+suf[i],suf[i]-1)) % MOD;
			}
	printf("%lld\n",ans);
	return 0;
}