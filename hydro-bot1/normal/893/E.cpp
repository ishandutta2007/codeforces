// Hydro submission #62ef1e8374296d3511bba590@1659838083967
#include<bits/stdc++.h>
using namespace std;
long long f[1500001],inv[1500001];
const int MOD=1000000007;
long long quick_pow(int a,int b,int p=MOD)
{
    if(!b) return 1;
    long long s=quick_pow(a,b/2,p);
    s=s*s%p;
    if(b%2) s=s*a%p;
    return s;
}
int main()
{
	int t,x,y,z,s,as,i; 
	cin>>t;f[0]=1;
	for(i=1;i<=1500000;i++)
	f[i]=f[i-1]*i%MOD;
	inv[0]=inv[1]=1;
	for(i=2;i<=1500000;i++)
	inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
	for(i=1;i<=1500000;i++)
	inv[i]=inv[i]*inv[i-1]%MOD;
	while(t--)
	{
		cin>>x>>y;z=x;
		as=quick_pow(2,y-1);
		for(i=2;i<=sqrt(z);i++)
		if(z%i==0)
		{
			s=0;
			while(z%i==0)
			{
				z/=i;
				s++;
			}
			as=as*(f[s+y-1]*inv[s]%MOD*inv[y-1]%MOD)%MOD;
		}
		if(z!=1)
		as=1ll*as*y%MOD;
		printf("%d\n",as);
	}
	return 0;
}