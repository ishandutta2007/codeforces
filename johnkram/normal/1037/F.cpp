#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
#define ll long long
#define P 1000000007
int ans,n,m,X,Y,i,j,k,l,r,a[MAXN],pr[MAXN],ne[MAXN],s[MAXN],t;
struct node
{
	int l,r,s;
}x[10],y[10];
void work(node *x,int &n,int l,int r)
{
	n=0;
	int L=l/m,R=r/m;
	if(L==R)
	{
		x[n].l=l%m;
		x[n].r=r%m;
		x[n++].s=1;
	}
	else
	{
		x[n].l=l%m;
		x[n].r=m-1;
		x[n++].s=1;
		x[n].l=0;
		x[n].r=r%m;
		x[n++].s=1;
		if(R>L+1){
		x[n].l=0;
		x[n].r=m-1;
		x[n++].s=R-L-1;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	m--;
	for(i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		while(t&&a[s[t]]<a[i])t--;
		pr[i]=s[t];
		s[++t]=i;
	}
	for(s[t=0]=n+1,i=n;i;i--)
	{
		while(t&&a[s[t]]<=a[i])t--;
		ne[i]=s[t];
		s[++t]=i;
	}
	for(i=1;i<=n;i++)
	{
		work(x,X,pr[i]+1,i);
		work(y,Y,i,ne[i]-1);
		for(j=0;j<X;j++)for(k=0;k<Y;k++)
		{
			l=max(x[j].l,y[k].l);
			r=min(x[j].r,y[k].r);
			if(l<=r)ans=(ans+(ll)(r-l+1)*x[j].s*y[k].s%P*a[i])%P;
		}
		ans-=a[i];
		if(ans<0)ans+=P;
	}
	cout<<ans<<endl;
	return 0;
}