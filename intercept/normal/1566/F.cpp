#include<bits/stdc++.h>
#define eb emplace_back
#define ll long long
using namespace std;
const int M=4e5+9;
int n,m;
struct P{
	ll l,r;
}p[M];
ll a[M];
ll dp[M],pre[M],suf[M];
bool cmp(P l,P r){
	return l.r==r.r?l.l>r.l:l.r<r.r;
}
void work(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	a[n+1]=2e9;
	for(int i=1;i<=m;++i){
		dp[i]=0;
		scanf("%lld%lld",&p[i].l,&p[i].r);
	}
	sort(p+1,p+m+1,cmp);
	int mm=m;
	ll ma=-2e9;m=0;
	for(int i=1;i<=mm;++i){
		int x=a[lower_bound(a+1,a+n+1,p[i].l)-a];
		if(p[i].l<=ma||(p[i].l<=x&&p[i].r>=x))continue;
		ma=max(ma,p[i].l);
		p[++m]=p[i];
	}
	for(int i=1;i<=n;++i)p[++m]=P{a[i],a[i]};
	sort(p+1,p+m+1,cmp);
	pre[0]=-p[1].r;
	suf[0]=-p[1].r*2;
	int kk=1;
	while(p[kk].r<a[1])pre[kk]=pre[0],suf[kk]=suf[0],kk++;
	for(int i=1,j=kk,la=0;i<=n;++i){
		for(;p[j].r<a[i+1]&&j<=m;++j){
			ll x=p[j].l-a[i];
			dp[j]=min(pre[la]+x+p[j].l,suf[la]+p[j].l+a[i]);
			pre[j]=dp[j]-p[j+1].r;
			suf[j]=dp[j]-p[j+1].r*2ll;
			pre[j]=min(pre[j],pre[j-1]);
			suf[j]=min(suf[j],suf[j-1]);
		}
		la=j-1;
	}
	printf("%lld\n",dp[m]);
}
int main(){
	int T;
	for(scanf("%d",&T);T;--T)work();
	return 0;
}