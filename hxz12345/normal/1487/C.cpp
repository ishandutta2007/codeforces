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
long long T,n,lft,rit;
int main()
{
	T=read();
	for (;T;T--)
	   { 
	   n=read();
	   for (lft=1;lft<n;lft++)
	      { 
	      rit=lft+1;
	      if(!(n&1)&&(lft&1))
		      {
			  rit++;printf("0 ");
	        	}
	      for (;rit<=n;rit++)
	         if ((rit-lft)&1)
	            printf("1 ");
	          else printf("-1 ");
		  }
		  puts("");
	   }
	return 0;
}