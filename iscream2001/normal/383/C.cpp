#include<bits/stdc++.h>
#define LL long long
#define ll long long
#define LD long double
using namespace std;
LL qpow(LL x,LL y,LL P=998244353){
	LL re;x%=P;
	for(re=1;y;y>>=1){if(y&1) re=re*x%P;x=x*x%P;}
	return re;
}
const LL P=1e9+7;
const int N=2e5+10;
const LL INF=2e18;
void init(){
}

int n,m,cnt;
vector<int> V[N];
int L[N],R[N],fa[N];
LL a[N];
LL dep[N];
void dfs(int x){
	L[x]=++cnt;
	int y;
	for(int i=0;i<V[x].size();++i){
		y=V[x][i];
		if(y==fa[x]) continue;
		fa[y]=x;
		dep[y]=-dep[x];
		dfs(y);
	}
	R[x]=cnt;
	return;
}
LL t[N];
void add(int x,LL w){
	while(x<=n){
		t[x]+=w;
		x+=x&-x;
	}
	return;
}
LL ask(int x){
	LL re=0;
	while(x>0){
		re+=t[x];
		x-=x&-x;
	}
	return re;
}
void MAIN(){
	int u,v,op;
	LL x;
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		V[v].push_back(u);
		V[u].push_back(v);
	}
	cnt=0;dep[1]=1;
	dfs(1);
	while(m--){
		scanf("%d%d",&op,&u);
		if(op==1){
			scanf("%lld",&x);
			x*=dep[u];
			add(L[u],x);
			add(R[u]+1,-x);
		}
		else{
			x=ask(L[u])*dep[u];
			printf("%lld\n",x+a[u]);
		}
	}
	return;
}
/*
*/
int main(){
    init();
    int ttt=1;//scanf("%d",&ttt);
    while(ttt--) MAIN();
    return 0;    
}