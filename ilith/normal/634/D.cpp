#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define FOR(i,a,b) for(rgi i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(rgi i=a,i##i=b;i>=i##i;--i)
using namespace std;
typedef long long ll;
const int N=800010;
int n,d,p,nw,nx[N],q[N],r;
ll ans;
struct node{int x,p;}a[N];
signed main(){
	scanf("%d%d%d",&d,&p,&n),nw=p;
	a[n+1].x=d;
	FOR(i,1,n)scanf("%d%d",&a[i].x,&a[i].p);
	++n,sort(a+1,a+n+1,[](node a,node y){return a.x<y.x;});
	FOR(i,1,n){
		while(r&&a[q[r]].p>=a[i].p)nx[q[r--]]=i;
		q[++r]=i;
	}
	FOR(i,1,n){
		nw-=a[i].x-a[i-1].x;
		if(nw<0)puts("-1"),exit(0);
		int d=a[nx[i]].x-a[i].x;
		if(nw<d){
			d=min(d,p);
			ans+=1ll*(d-nw)*a[i].p,nw=d;
		}
	}
	printf("%lld",ans);
	return 0;
}