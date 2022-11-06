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
long long dif,A,B,Testing,lft,rit,w1,w2,w3,a[10][10010],i,j,n;
bool exist[100101];
bool flag;
int main()
{
	for (Testing=read();Testing;Testing--)
	   { 
	   n=read();
	   for (i=1;i<=n;i++)
	      for(j=1;j<=5;j++)
	         a[j][i]=read();flag=false;
	for (lft=1;lft<=5;lft++)
	   for (rit=lft+1;rit<=5;rit++)
	          { 
	          if (flag) break;
	          w1=0;w2=0;w3=0;
	          for (i=1;i<=n;i++) exist[i]=false;
	              for (i=1;i<=n;i++)
	                 if (a[lft][i]==1) exist[i]=true,w1++;
	            for (i=1;i<=n;i++)
	              if (a[rit][i]==1)
	                  {
	                  	   if (exist[i]) w3++;w2++;
					  }
				A=w1-w3;B=w2-w3;
				dif=0;
				if (A<n/2) dif+=n/2-A;
				if (B<n/2) dif+=n/2-B;
				if (dif<=w3) flag=true;
	            
			  }
		if (flag) puts("YES");else puts("NO");
	   }
	return 0;
}