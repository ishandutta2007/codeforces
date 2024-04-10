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
//3 2 1 3 2 1 3 2 1
//1 3 2 1 3 2 1 3 2 
//1 3 2
//
//5 4 3 2 1 5 4 3 2 1 5 4 3 2 1
//1 2 4 5 2 3 5 1 3 4 1 2 4 5 

//7 6 5 4 3 2 1 7 6 5 4 3 2 1
//1 2 3 5 6 7 2 3 4 6 7 1 3 4 
long long n,m,T,now,lft,rit;
int main()
{
	for (T=read();T;T--)
	    { 
	      n=read();m=read();
	      if (n % 2==0) printf("%lld\n",(m-1) % n+1);
	      else 
	         { 
	           now=(m-1) % (n*(n-1))+1;
	           lft=(now-1)/(n-1)+1;rit=(now-1) % (n-1)+1;
	           if (rit<=n/2) printf("%lld\n",(lft+rit-1-1+n) % n+1);
	           else printf("%lld\n",(lft+rit-1+n) % n+1);
			 }
		 } 
	return 0;
}