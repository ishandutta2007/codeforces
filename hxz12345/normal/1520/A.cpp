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
int a[100100],T,n,i;
bool flag,f[10000];
string s;
int main()
{
	T=read();
	for (;T;T--)
	    {
	    	n=read();
	    	cin>>s;n=s.size();
	    	for (i=1;i<=26;i++) f[i]=false;flag=true;
	    	for (i=1;i<=n;i++) a[i]=s[i-1]-'A'+1;
	    	for (i=1;i<=n;i++)
	    	   if (a[i]!=a[i-1])
	    	       {
	    	       	if (f[a[i]]) 
	    	       	  {
	    	       	  	flag=false;break;
						 }
	    	       	f[a[i]]=true;
				   }
	    	if (flag) puts("YES");
	    	else puts("NO");
		}
   return 0;
}