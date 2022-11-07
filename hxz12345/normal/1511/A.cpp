#include <bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
long long Testing,n,sum,i,x;
int main()
{
	Testing=read();
	for (;Testing;Testing--)
	        {
	        	n=read();
	        	sum=0;
	        	for (i=1;i<=n;i++) x=read(),sum+=(x!=2);
	        	printf("%lld\n",sum);
			}
		return 0;
}