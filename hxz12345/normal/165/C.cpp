#include<bits/stdc++.h>
using namespace std;
long long pow(long long x,long long y,long long p)
{
	long long ans=1;
	for (;y;y>>=1,x=x*x % p)
		if (y&1) ans=ans*x % p;
	return ans;
}
long long gcd(long long x,long long y)
{
	if (y==0) return x;
	long long ans=gcd(y,x % y);return ans;
}
long long L,R,i,n,K,sum,l,r,mid,lft,ans,pre[1010100],a[1010100];
string s;
int main()
{
	ios::sync_with_stdio(0);cin.tie();cout.tie();
	cin>>K;
	cin>>s;n=s.size();
	for (i=1;i<=n;i++) a[i]=s[i-1]-'0',pre[i]=pre[i-1]+a[i];
	for (lft=1;lft<=n;lft++)
	      {
	      	l=lft;r=n;L=0;
	      	while (l<=r)
	      	     {
	      	     	mid=(l+r)/2;
	      	     	if (pre[mid]-pre[lft-1]>=K)
	      	     	     {
	      	     	     	L=mid;r=mid-1;
							}
					else l=mid+1;
				   }
			l=lft;r=n;R=0;
	      	while (l<=r)
	      	     {
	      	     	mid=(l+r)/2;
	      	     	if (pre[mid]-pre[lft-1]<=K)
	      	     	     {
	      	     	     	R=mid;l=mid+1;
							}
					else r=mid-1;
				   }
			if ((L!=0)&&(R!=0)) sum+=R-L+1;
		  }
	cout<<sum<<endl;
return 0;
}