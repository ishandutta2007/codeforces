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
double lst,up,now,P;
long long n,len,a,b,c,num;
int main()
{
	cin>>n>>P;
	up=n*(n-1)*(n-2);
	for (len=0;len<=n;len++)
	    {
	    	  now=0;
			lst=(len)*(n-len)*(n-len-1)/2*3;
			lst+=len*(len-1)*(len-2);
			lst+=len*(len-1)*(n-len)*3;
				if ((double)lst/(double)up>=P) break;
		}
	printf("%lld\n",len);
	return 0;
}