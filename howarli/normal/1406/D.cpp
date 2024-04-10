#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define efo(i,q) for(int i=A[q];i;i=B[i][0])
using namespace std;
typedef long long LL;
const int N=100500,INF=1e9+7;
int read(int &n)
{
	bool q=0;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')ch=getchar(),q=1;
	for(;ch<='9'&&ch>='0';ch=getchar())n=(n<<1)+(n<<3)+ch-48;
	return q?n=-n:n;
}
int n,m;
LL ans;
LL a[N];
LL max(LL q,LL w){return q>w?q:w;}
int main()
{
	int q,w,e;

	read(n);
	ans=0;
	a[1]=read(q);
	fo(i,2,n)a[i]=read(q),ans+=max(0,a[i-1]-a[i]);
	ans+=a[n];
	fod(i,n,2)a[i]=a[i]-a[i-1];
	printf("%lld\n",ans/2+(ans>0?ans%2:0));
	read(m);
	fo(i,1,m)
	{
		read(q),read(w),read(e);
		if(q-1)ans-=max(0,-a[q]);
		a[q]+=e;
		if(q-1)ans+=max(0,-a[q]);

		if(w+1<=n)ans-=max(0,-a[w+1]);
		a[w+1]-=e;
		if(w+1<=n)ans+=max(0,-a[w+1]);
		
		if(w==n)ans+=e;
		
		printf("%lld\n",ans/2+(ans>0?ans%2:0));
	}
	return 0;
}