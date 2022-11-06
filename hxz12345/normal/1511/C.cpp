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
//2 1 1 4 3 3 1->1 2 3 4 5 6 7
//50 
int now,n,Q,i,x,mov,a[1001010],G[1001010];
bool exist[1001010];
int main()
{
	n=read();Q=read();
	for (i=1;i<=n;i++) 
	    {
		a[i]=read();
		if (G[a[i]]==0) G[a[i]]=i;
	    }   
	for (;Q;Q--)
	    { 
	    x=read();
	    now=G[x];
	    printf("%d ",now);
	    for (i=1;i<=50;i++)
            if (i!=x)
 	        if (G[i]!=0) 
	          if (G[i]<now)
	              G[i]++;
	    G[x]=1;
		}
	return 0; 
}