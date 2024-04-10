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
long long l,r,mid,b[1001010],i,n,tot,a[1001010],pre[1001010],j,sum;
void Main(){
	n=read();tot=0;
	for (i=1;i<=n;i++) a[i]=read(),tot+=a[i];
	tot/=n;
	pre[n]=n-tot;
	if (a[n]==n) b[n]=1;else b[n]=0;
	for (i=n-1;i>=1;i--)
	     {
	     	sum=i;
	     	l=i+1;r=n;
	     	while (l<=r){
	     		mid=(l+r)/2;
	     		if (pre[mid]<i) sum=mid,l=mid+1;else r=mid-1;
			 }
			sum-=i;
	     	pre[i]=pre[i+1]-(1-b[i+1]);
	     	if (a[i]-sum==i) b[i]=1;else b[i]=0;
		 }
		//pre[i]
	for (i=1;i<=n;i++) printf("%lld ",b[i]);
    puts("");
	//i~n  pre[i]<i,pre[i]i0 
}
int main()
{
	int Testing=read();
	for (;Testing;Testing--) Main();
return 0;
}