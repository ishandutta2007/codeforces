// Hydro submission #62e23e24a7298486b32fa6b7@1658994212855
#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
long long f[200001];
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
	int n,i;cin>>n;f[0]=1;
	for(i=1;i<=n*2;i++)
	f[i]=f[i-1]*i%MOD;
	printf("%lld\n",f[n*2]*quick_pow(f[n]*f[n]%MOD,MOD-2)%MOD-n);
	return 0;
}