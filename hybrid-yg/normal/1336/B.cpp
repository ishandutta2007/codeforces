#include<bits/stdc++.h>
using namespace std;
const int M=1000000007;
const int N=300005,E=524288;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
int n,i,na,nb,nc,t;
int a[N],b[N],c[N];
long long ans;
void cal()
{
	int i,j,k;
	j=1;
	k=1;
	for(i=1;i<=na;++i)
	{
		for(;j<=nb;++j)
			if(b[j]>=a[i])
				break;
		if(j>nb)
			return;
		for(;k<=nc;++k)
			if(c[k]>=b[j])
				break;
		if(k>nc)
			return;
		int x=lower_bound(b+1,b+1+nb,(a[i]+c[k])/2)-b;
		if(x<=nb&&x>=1)
			ans=min(ans,1ll*(b[x]-a[i])*(b[x]-a[i])+1ll*(b[x]-c[k])*(b[x]-c[k])+1ll*(a[i]-c[k])*(a[i]-c[k]));
		--x;
		if(x<=nb&&x>=1)
			ans=min(ans,1ll*(b[x]-a[i])*(b[x]-a[i])+1ll*(b[x]-c[k])*(b[x]-c[k])+1ll*(a[i]-c[k])*(a[i]-c[k]));
	}
}
void Uni(int *a,int &n)
{
	int m=0,i;
	for(i=1;i<=n;++i)
		if(a[i]!=a[m])
			a[++m]=a[i];
	n=m;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&na,&nb,&nc);
		for(i=1;i<=na;++i)
			scanf("%d",&a[i]);
		for(i=1;i<=nb;++i)
			scanf("%d",&b[i]);
		for(i=1;i<=nc;++i)
			scanf("%d",&c[i]);
		sort(a+1,a+1+na);
		sort(b+1,b+1+nb);
		sort(c+1,c+1+nc);
		Uni(a,na);
		Uni(b,nb);
		Uni(c,nc);
		ans=3000000000000000000ll;
		cal();//abc
		for(i=1;i<=max(na,nb);++i)
			swap(a[i],b[i]);
		swap(na,nb);
		cal();//bac
		for(i=1;i<=max(na,nb);++i)
			swap(a[i],b[i]);
		swap(na,nb);
		
		for(i=1;i<=max(na,nc);++i)
			swap(c[i],a[i]);
		swap(na,nc);
		cal();//cba
		for(i=1;i<=max(na,nc);++i)
			swap(c[i],a[i]);
		swap(na,nc);
		
		for(i=1;i<=max(nb,nc);++i)
			swap(c[i],b[i]);
		swap(nb,nc);
		cal();//acb
		for(i=1;i<=max(nb,nc);++i)
			swap(c[i],b[i]);
		swap(nb,nc);
		
		for(i=1;i<=max(na,nc);++i)
			swap(c[i],a[i]);
		swap(na,nc);
		for(i=1;i<=max(nb,na);++i)
			swap(b[i],a[i]);
		swap(na,nb);
		cal();//bca
		for(i=1;i<=max(nb,na);++i)
			swap(b[i],a[i]);
		swap(na,nb);
		for(i=1;i<=max(na,nc);++i)
			swap(c[i],a[i]);
		swap(na,nc);
		
		for(i=1;i<=max(nb,nc);++i)
			swap(c[i],b[i]);
		swap(nb,nc);
		for(i=1;i<=max(na,nb);++i)
			swap(a[i],b[i]);
		swap(na,nb);
		cal();//cab
		printf("%lld\n",ans);
	}
}