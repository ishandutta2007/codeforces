#include<bits/stdc++.h>
#define LL long long
#define ll long long
#define LD long double
using namespace std;
LL qpow(LL x,LL y,LL P=998244353){
	LL re;
	for(re=1;y;y>>=1){if(y&1) re=re*x%P;x=x*x%P;}
	return re;
}
const LL P=1e9+7;
const int N=2e5+10;
const int INF=1e9;

void init(){
}

int n,m,cnt;
int vis[N];
int fa[N],du[N];
int L[N],R[N];
int q[N];
vector< int > V[N];
void dfs(int x){
	L[x]=++cnt;
	q[cnt]=x;
	int y,z;
	for(int i=0;i<V[x].size();++i){
		y=V[x][i];
		if(y==fa[x]) continue;
		fa[y]=x;++du[x];
		dfs(y);
	}
	R[x]=cnt;
	return;
}


#define ls id<<1
#define rs id<<1|1

struct LazyTag{
	int x;
};

struct Segment{
	int l,r;
	//Val
	int mx,id;
	//LazyTag 
	int laz;
}d[N<<2];

bool Cut(int id){
	//
	return 0;
}

bool Check(int id){
	//
	return 1;
}

void PutTag(int id,LazyTag K){
	//
	d[id].laz+=K.x;
	d[id].mx+=K.x;
	return;
}

void pushup(int id){
	//
	d[id].mx=d[ls].mx;
	d[id].id=d[ls].id;
	if(d[rs].mx>d[id].mx){
		d[id].mx=d[rs].mx;
		d[id].id=d[rs].id;
	}
	return;
}

void pushdown(int id){
	//
	PutTag(ls,(LazyTag){d[id].laz});
	PutTag(rs,(LazyTag){d[id].laz});
	d[id].laz=0;
	return;
}

void build(int id,int l,int r){
	//
	d[id].l=l;d[id].r=r;
	
	if(l==r){
		//
		d[id].mx=0;
		d[id].id=l;
		d[id].laz=0;
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(id);
	return;
}

void Change(int id,int l,int r,int ql,int qr,LazyTag K){
	if(ql>r||qr<l||Cut(id)) return;
	if(ql<=l&&qr>=r&&Check(id)){
		PutTag(id,K);
		return;
	}
	int mid=(l+r)>>1;pushdown(id);
	Change(ls,l,mid,ql,qr,K);
	Change(rs,mid+1,r,ql,qr,K);
	pushup(id);
	return;
} 

void MAIN(){
	int u,v;
	LL ans,mm; 
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		V[u].push_back(v);
		V[v].push_back(u);
	}
	cnt=0;
	dfs(1);
	int num;
	num=0;
	for(int i=1;i<=n;++i){
		if(du[i]==0) ++num;
	}
	if(num<=m){
		mm=n>>1;
		if(m<=mm){
			ans=(LL)m*(LL)(n-m);
		}
		else if(num>=mm){
			ans=(LL)num*(LL)(n-num);
		}
		else{
			ans=(LL)mm*(LL)(n-mm);
		}
		printf("%lld\n",ans);
		return;
	}
	build(1,1,n);
	for(int i=1;i<=n;++i){
		Change(1,1,n,L[i],R[i],(LazyTag){1});
	}
	
	for(int ttt=1;ttt<=m;++ttt){
		u=q[d[1].id];
		while(u&&vis[u]==0){
			vis[u]=1;
			Change(1,1,n,L[u],R[u],(LazyTag){-1});
			u=fa[u];
		}
	}
	LL W=0,B=0,R=m;
	for(int i=1;i<=n;++i){
		if(vis[i]==0) B++;
	}
	W=n-B-R;
	R=-R;
	while(B>0){
		--B;
		if(R<=W) ++R;
		else ++W;
	} 
	R=-R;
	printf("%lld\n",R*W);
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