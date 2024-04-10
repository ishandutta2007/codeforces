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
int n,i,ans,x;
string s;
int main()
{
	cin>>n;
	cin>>s;
	x=0;ans=0;
	for (i=1;i<=n;i++)
	     {
	     	if (s[i-1]=='+') x++;
	     	else x--;
	     	ans=max(ans,-x);
		 }
		
	for (i=1;i<=n;i++)
	     {
	     	if (s[i-1]=='+') ans++;else ans--;
		 }
	printf("%d\n",ans);
    return 0;
}