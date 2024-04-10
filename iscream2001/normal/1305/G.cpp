#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
const int N=2e5+10;
const double eps=1e-6;
const LL sed=1e9+7;
const LL P=998244353;
LL qpow(LL x,LL y){
	LL re=1;
	while(y){
		if(y&1) re=re*x%P;
		x=x*x%P;y>>=1;
	}
	return re;
}
int n,cnt;
int a[N];
int fa[N];

int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

struct Node{
	int val[2];
	int bel[2];
}F[(1<<18)+10],G[N];

void upd(Node &X,int v,int b){
	if(X.bel[0]==X.bel[1]||(b!=X.bel[0]&&v>X.val[1])){
		X.val[1]=v;
		X.bel[1]=b;
	}
	else {
		if(b==X.bel[0]&&v>X.val[0]){
			X.val[0]=v;
		}
		return;
	}
	if(X.val[0]<X.val[1]) {
		swap(X.val[0],X.val[1]);
		swap(X.bel[0],X.bel[1]);
	}
	return;
}

void SOSDP(){
	for(int i=0;i<(1<<18);++i) {
		F[i].val[0]=F[i].val[1]=F[i].bel[0]=F[i].bel[1]=0;
	}
	int u;
	for(int i=1;i<=n;++i){
		u=find(i);
		upd(F[a[i]],a[i],u);
	}
	for(int j=0;j<18;++j){
		for(int i=0;i<(1<<18);++i){
			if(i&(1<<j)) continue;
			upd(F[i^(1<<j)],F[i].val[0],F[i].bel[0]);
			upd(F[i^(1<<j)],F[i].val[1],F[i].bel[1]);
		}
	}
	return;
} 

void MAIN(){
	LL ans=0;
	scanf("%d",&n);
	a[0]=0;fa[0]=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		ans-=a[i];
		fa[i]=i;
	}
	cnt=n+1;
	int u,v,lim=(1<<18)-1;
	while(cnt>1){
		SOSDP();
		for(int i=0;i<=n;++i){
			G[i].val[0]=G[i].val[1]=G[i].bel[0]=G[i].bel[1]=0;
		}
		for(int i=0;i<=n;++i){
			u=find(i);
			upd(G[u],F[lim^a[i]].val[0]+a[i],F[lim^a[i]].bel[0]);
			upd(G[u],F[lim^a[i]].val[1]+a[i],F[lim^a[i]].bel[1]);
		}
		for(int i=0;i<=n;++i){
			u=find(i);
			if(u!=i) continue;
			if(find(G[u].bel[0])!=u){
				v=find(G[u].bel[0]);
				ans+=G[u].val[0];
				fa[max(u,v)]=min(u,v);
				--cnt;
			}
			else if(find(G[u].bel[1])!=u){
				v=find(G[u].bel[1]);
				ans+=G[u].val[1];
				fa[max(u,v)]=min(u,v);
				--cnt;
			}
		}
	}
	printf("%lld\n",ans);
	return;
}
int main(){
	int ttt=1;//scanf("%d",&ttt);
	while(ttt--){
		MAIN();
	}
    return 0;
}