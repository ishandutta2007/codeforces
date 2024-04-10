#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
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
string s;
long long f[1010][1010],T,n,A,B,ans,l,i;
int main()
{
	ios::sync_with_stdio(0);cin.tie();cout.tie();
	cin>>T;
	for (;T;T--)
	    {
	    	cin>>n>>A>>B;
	    	cin>>s;ans=1;
	    		memset(f,0x7F,sizeof(f));	
	for(int i=1;i<=n;++i)
		f[i][i]=1;
	for(int l=1;l<n;++l) 
		for(int i=1,j=1+l;j<=n;++i,++j) {
			if(s[i-1]==s[j-1])
				f[i][j]=min(f[i+1][j],f[i][j-1]);
			else
				for(int k=i;k<j;++k)
					f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
		}
	         if (B>0) ans=A*n+B*n;
	         else ans=A*n+B*f[1][n];
	         printf("%lld\n",ans);
		}
 return 0;
}