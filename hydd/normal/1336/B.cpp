#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF=1ll<<62;
int T,r,g,b,R[110000],G[110000],B[110000];
ll ans;
ll sqr(int x){ return 1ll*x*x;}
int findpre(int n,int *a,int x){
	return lower_bound(a+1,a+n+1,x)-a-1;
}
int findsuf(int n,int *a,int x){
	return lower_bound(a+1,a+n+1,x)-a;
}
void solve(int n,int *a,int m,int *b,int k,int *c){
	int x,y;
	for (int i=1;i<=n;i++){
		x=findpre(m,b,a[i]);
		if (x>=1){
			y=findpre(k,c,(a[i]+b[x])/2);
			if (y>=1) ans=min(ans,sqr(a[i]-b[x])+sqr(b[x]-c[y])+sqr(c[y]-a[i]));
			y=findsuf(k,c,(a[i]+b[x])/2);
			if (y<=k) ans=min(ans,sqr(a[i]-b[x])+sqr(b[x]-c[y])+sqr(c[y]-a[i]));
		}
		x=findsuf(m,b,a[i]);
		if (x<=m){
			y=findpre(k,c,(a[i]+b[x])/2);
			if (y>=1) ans=min(ans,sqr(a[i]-b[x])+sqr(b[x]-c[y])+sqr(c[y]-a[i]));
			y=findsuf(k,c,(a[i]+b[x])/2);
			if (y<=k) ans=min(ans,sqr(a[i]-b[x])+sqr(b[x]-c[y])+sqr(c[y]-a[i]));
		}
	}
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d",&r,&g,&b); ans=INF;
		for (int i=1;i<=r;i++) scanf("%d",&R[i]);
		for (int i=1;i<=g;i++) scanf("%d",&G[i]);
		for (int i=1;i<=b;i++) scanf("%d",&B[i]);
		sort(R+1,R+r+1); sort(G+1,G+g+1); sort(B+1,B+b+1);
		solve(r,R,g,G,b,B); solve(r,R,b,B,g,G);
		solve(g,G,r,R,b,B); solve(g,G,b,B,r,R);
		solve(b,B,r,R,g,G); solve(b,B,g,G,r,R);
		printf("%lld\n",ans);
	}
	return 0;
}