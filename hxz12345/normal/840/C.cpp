#include <bits/stdc++.h>
using namespace std;
long long len,MOD,lsh[1001010],fac[1001010],sum,dif,lst1,x,c[1010][1010],up,fre[100101],f[1010][1010],a[100100],n,i,j,now,ans;
int main() {
    ios::sync_with_stdio(0);cin.tie();cout.tie();
    cin>>n;MOD=1e9+7;
    for (i=1;i<=n;i++) 
         {
         	cin>>a[i];
         	for (j=2,up=sqrt(a[i]);j<=up;j++)
         	     while (a[i] % (j*j)==0) 
         	          a[i]/=(j*j);
         	lsh[i]=a[i];
		 }
	c[0][0]=1;fac[0]=1;
	for (i=1;i<=500;i++)
	    {
	    	c[i][0]=1;c[i][i]=1;
	    	for (j=1;j<i;j++)
	    	   c[i][j]=(c[i-1][j-1]+c[i-1][j]) % MOD;
	    	fac[i]=fac[i-1]*i % MOD;
		}
	sort(lsh+1,lsh+n+1);len=unique(lsh+1,lsh+n+1)-lsh-1;
	for (i=1;i<=n;i++) a[i]=lower_bound(lsh+1,lsh+len+1,a[i])-lsh,fre[a[i]]++;
	f[1][fre[1]-1]=1;sum=fre[1];
	for (i=1,dif=1;i<=len;i++) dif=dif*fac[fre[i]] % MOD;
	for (i=2;i<=len;sum+=fre[i],i++)
	   for (lst1=0;lst1<=sum+1;lst1++)
	        if (f[i-1][lst1]!=0)
	            for (x=1;x<=fre[i];x++)
	                for (now=0;now<=min(lst1,x);now++)
	                    { 
	                    f[i][lst1-now+fre[i]-x]+=f[i-1][lst1]*c[fre[i]-1][fre[i]-x] % MOD*c[lst1][now] % MOD*c[sum+1-lst1][x-now] % MOD;
	                    f[i][lst1-now+fre[i]-x]%=MOD;
						}
    cout<<f[len][0]*dif % MOD<<endl;
	return 0;
}