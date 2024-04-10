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
bool vis[1001010];
bitset<20001010> siz;
long long n,m,tag[1001010],ans,i,sum,j;
int main()
{
	n=read();m=read();
	for (i=1;i<=20;i++){tag[i]=tag[i-1];
		for (j=1;j<=m;j++) 
		    tag[i]+=1-siz[i*j],siz[i*j]=1;
	}
	ans=1;
	for (i=2;i<=n;i++)
	    if (vis[i]==false)
	       {sum=0;
	       	for (j=i;j<=n;j=j*i){sum++;
	       		  vis[j]=true;
			   }
			ans=ans+tag[sum];
	    }
	printf("%lld\n",ans);
    return 0;
}