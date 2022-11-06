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
int x,y,T,n,sum1,sum2,i;
string s1,s2;
int main()
{
	T=read();
	for (;T;T--)
	    {
	    	n=read();
	    	cin>>s1;cin>>s2;
	    	sum1=0;sum2=0;
	    	for (i=1;i<=n;i++)
	    	    {
	    	    	x=s1[i-1]-'0';y=s2[i-1]-'0';
	    	    	if (x>y) sum1++;
	    	    	if (x<y) sum2++;
				}
			if (sum1==sum2) puts("EQUAL");
			else if (sum1>sum2) puts("RED");
			else puts("BLUE");
		}
   return 0;
}