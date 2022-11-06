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
long long gcd(long long x,long long y)
{
	if (y==0) return x;
	long long ans=gcd(y,x % y);return ans;
}
struct node{
	long long tim,val;
} a[1001010];
long long P,x,y,ans,m,f[101000],pre[1001010],g[101000],n,i,q[1001000],l,r,j;
double slope(int x,int y)
{
	double a1=x,b1=g[x]+pre[x];
	double a2=y,b2=g[y]+pre[y];
	if (a2-a1==0) return ((b2-b1)*1000000);
	return ((b2-b1)/(a2-a1));
}
bool cmp(node a,node b){return a.tim<b.tim;}
int main()
{
	n=read();m=read();P=read();
	for (i=2;i<=n;i++) x=read(),pre[i]=pre[i-1]+x;
	for (i=1;i<=m;i++)
	    {
	    	x=read();y=read();a[i].tim=y-pre[x];
			a[i].val=y-pre[x];
		 } 
	sort(a+1,a+m+1,cmp);
	pre[0]=0;
	for (i=1;i<=m;i++) pre[i]=pre[i-1]+a[i].val;
	//cout<<a[1].tim<<" "<<a[1].val<<endl;
	for (i=1;i<=m;i++) g[i]=a[i].tim*i-pre[i];ans=g[m];
	for (j=2;j<=P;j++)
	     {
	     	//cout<<"Part j: ";
	     	l=1;r=0;q[1]=0;
	     	 for (i=1;i<=m;i++)
	     	     {
	     	     	while ((l<r)&&(slope(q[l],q[l+1])<a[i].tim)) l++;
	     	     	if (l<=r) f[i]=g[q[l]]+a[i].tim*(i-q[l])-(pre[i]-pre[q[l]]);
                    else f[i]=a[i].tim*i-pre[i];
	     	     //	cout<<f[i]<<"----"<<pre[i]-pre[q[l]]<<"-----"<<q[l]<<"-----"<<pre[i]-pre[q[l]]<<" ";
				  	while ((l<r)&&(slope(q[r-1],q[r])>slope(q[r],i))) r--;
	     	     	r++;q[r]=i;
				  }
		//	cout<<endl;
		ans=min(ans,f[m]);
			for (i=1;i<=m;i++) g[i]=f[i];
		 }
	printf("%lld\n",ans);
return 0;
}