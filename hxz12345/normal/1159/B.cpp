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
struct node{
int val,id;
} a[1010100];
int n,i,mn,mx,ans;

bool cmp(node a,node b){
	return a.val>b.val;
}
int main()
{
	n=read();
	for (i=1;i<=n;i++) a[i].val=read(),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	mn=1e9;ans=1e9;
	for (i=1;i<=n;i++)
	    {	    	
		if (a[i].id>mn)	ans=min(ans,a[i].val/(a[i].id-mn));
		if (a[i].id<mx)	ans=min(ans,a[i].val/(mx-a[i].id));
	    mn=min(mn,a[i].id);mx=max(mx,a[i].id);
	    }
	printf("%d\n",ans);
    return 0;
}