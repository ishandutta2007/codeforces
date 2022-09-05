#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
typedef long double ld;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=3e5+5;
int n,x1,x2,c[N],q[N];
s64 a[N],w[N],mx[N];
int nq[N],head,tail;
bool c_xiao(int x,int y)
{
	return c[x]<c[y];
}

int len;
s64 f(int i)
{
	return w[i]-a[i]*len;
}
bool need_pop(int x,int y,int z)
{
	return (ld)(a[x]-a[z])*(w[y]-w[z])-(ld)(a[y]-a[z])*(w[x]-w[z])>0;
}

int main()
{

	cin>>n>>x1>>x2;
	rep(i,1,n)scanf("%d",c+i);
	rep(i,1,n)q[i]=i;
	sort(q+1,q+n+1,c_xiao);
	for(int i=n;i;--i)
	{
		a[i]=c[q[i]];
		w[i]=a[i]*(n-i+1);
		mx[i]=max(mx[i+1],w[i]);
	}
	head=1;tail=0;
	rep(i,1,n)
	{
		len=(x1+a[i]-1)/a[i];
		int j=i+len-1;
		if(j>n)continue;
		if(mx[j+1]>=x2)
		{
			while(++j,w[j]!=mx[j]);
			puts("Yes");
			printf("%d %d\n",len,n-j+1);
			rep(k,i,i+len-1)printf("%d ",q[k]);puts("");
			rep(k,j,n)printf("%d ",q[k]);puts("");
			exit(0);
		}
		while(head<tail&&f(nq[head])<f(nq[head+1]))++head;
		if(head<=tail&&f(nq[head])>=x2)
		{
			puts("Yes");
			j=nq[head];
			printf("%d %d\n",len,n-j+1-len);
			rep(k,i,i+len-1)printf("%d ",q[k]);puts("");
			rep(k,j,i-1)printf("%d ",q[k]);
			rep(k,i+len,n)printf("%d ",q[k]);
			puts("");
			exit(0);
		}
		while(head<tail&&need_pop(nq[tail-1],nq[tail],i))--tail;
		nq[++tail]=i;
	}
	puts("No");
}