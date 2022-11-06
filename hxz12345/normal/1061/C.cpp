#include<bits/stdc++.h>
using namespace std;
long long w,ans,a[100020],b[2000000],f[2000000],MOD,sum,n,i,j;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++) cin>>a[i];
	f[0]=1;MOD=1000000007;
    for (i=1;i<=n;i++)
          {
          	  w=0;
          	  for (j=1;j<=sqrt(a[i]);j++)
          	     if (j<=i)
          	      if (a[i] % j==0)
          	          {
          	          	w++;b[w]=j;
						}
			  for (j=1;j<=w;j++)
			     if (a[i]/b[j]<=i)
			      if (b[j]*b[j]!=a[i])
			          f[a[i]/b[j]]=(f[a[i]/b[j]]+f[(a[i]/b[j])-1]) % MOD;
			  for (j=w;j>=1;j--)
			       if (b[j]<=i)
			          f[b[j]]=(f[b[j]]+f[b[j]-1]) % MOD;
		  }
	for (i=1;i<=n;i++) ans=(ans+f[i]) % MOD;
	cout<<ans<<endl;
	return 0;
}