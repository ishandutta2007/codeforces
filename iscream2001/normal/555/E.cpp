#include<bits/stdc++.h>
#define LD long double
#define LL long long
using namespace std;
const LL INF=1e18;
const int inf=1e9;
//const LD PI=acos(-1.0);
//const LL M=998244353;
const LL M=1e9+7;
const int N=3e5+10;
const LD eps=1e-11;
const LD eps2=1e-10;
//
LL qpow(LL x,LL y,LL mod=M){
	x%=mod;
	LL re=1;
	while(y){
		if(y&1) re=re*x%mod;
		y>>=1;x=x*x%mod;
	}
	return re;
}

//struct jz{
//	LL x[12][12];
//};
//jz operator * (jz A,jz B){
//	jz C;
//	for(int i=1;i<=9;++i){
//		for(int j=1;j<=9;++j){
//			C.x[i][j]=0;
//		}
//	}
//	for(int i=1;i<=9;++i){
//		for(int k=1;k<=9;++k){
//			if(A.x[i][k]!=0){
//				for(int j=1;j<=9;++j){
//					(C.x[i][j]+=A.x[i][k]*B.x[k][j]%M)%=M;
//				}
//			}
//		}
//	}
//	return C;
//}
////inline char gc(){return getchar();}
//bool is_pri[N+10];
//LL pri[6000000];
////int mu[N+10];
//int cntp=0;
//
//void init_pri(){
////	mu[1]=1;
//    for(int i=2;i<=N;++i){
//        if(!is_pri[i]) {
//            pri[++cntp]=i;
//  //          mu[i]=-1;
//        }
//        for(int j=1;j<=cntp&&pri[j]*i<=N;++j){
//            is_pri[pri[j]*i]=1;
//            if(i%pri[j]==0) {
//    //        	mu[pri[j]*i]=0;
//                break;
//            }
//            else{
//      //      	mu[pri[j]*i]=-mu[i];
//			}
//        }
//    }
//}
//
//struct P{
//	LD x,y;
//	P(LD _x=0,LD _y=0){x=_x;y=_y;}
//}used,a[550],b[550];
//
//LD dis(P x){return x.x*x.x+x.y*x.y;}
//P operator + (P x,P y){return P(x.x+y.x,x.y+y.y);}
//P operator - (P x,P y){return P(x.x-y.x,x.y-y.y);}
//LD operator * (P x,P y){return x.x*y.x+x.y*y.y;}
//P operator * (P x,LD y){return P(x.x*y,x.y*y);}
//LD operator / (P x,P y){return x.x*y.y-x.y*y.x;}
//P operator / (P x,LD y){return P(x.x/y,x.y/y);}
//P dwh(P x){LD w=sqrt(dis(x));return x/w;}
//
//LL fac[1000005],finv[1000005];
//LL C(LL x,LL y,LL mod=M){
//	if(x<y) return 0;
//	if(x<=1000000) return fac[x]*finv[y]%mod*finv[x-y]%mod;
//	LL re=1;
//	y=min(y,x-y);
//	for(LL i=x-y+1;i<=x;++i){
//		re=re*i%M;
//	}
//	re=re*finv[y]%M;
//	return re;
//}
//void init(){
//	fac[0]=fac[1]=finv[0]=finv[1]=1;
//	for(LL i=2;i<=1000000;++i) fac[i]=fac[i-1]*i%M;
//	finv[1000000]=qpow(fac[1000000],M-2,M);
//	for(LL i=1000000;i>1;--i) finv[i-1]=finv[i]*i%M;
//	return;
//}

int n,m,Q,cnt,num,dfn_co; 

int hed[N],fa[N],cut[N<<1],dfn[N],low[N];
struct edge{
	int r,nxt,val;
}e[N<<1];
void insert(int u,int v,int w){
	e[++cnt].r=v;e[cnt].nxt=hed[u];hed[u]=cnt;e[cnt].val=w;
}

void Tarjan(int x,int rt){
	dfn[x]=low[x]=++num;
	for(int i=hed[x];i;i=e[i].nxt){
		if(i==(fa[x]^1)) continue;
		if(!dfn[e[i].r]){
			fa[e[i].r]=i;
			Tarjan(e[i].r,rt);
			low[x]=min(low[x],low[e[i].r]);
			if(low[e[i].r]>dfn[x]){
				cut[i]=cut[i^1]=1;
			}
		}
		else{
			low[x]=min(low[x],dfn[e[i].r]);
		}
	}
}

int co[N];
void col(int x){
	co[x]=num;
	for(int i=hed[x];i;i=e[i].nxt){
		if(cut[i]) continue;
		if(co[e[i].r]) continue;
		col(e[i].r);
	}
}

vector<int> V[N];
int siz[N],son[N],top[N],dL[N],dR[N],dep[N];
void dfs1(int x){
	siz[x]=1;son[x]=0;
	for(auto y:V[x]){
		if(fa[x]==y){
			continue;
		}
		fa[y]=x;
		dep[y]=dep[x]+1;
		dfs1(y);
		siz[x]+=siz[y];
		if(siz[y]>siz[son[x]]) son[x]=y;
	}
	return;
}
void dfs2(int x,int TP){
	top[x]=TP;
	dL[x]=++dfn_co;
	dfn[dL[x]]=x;
	if(son[x]){
		dfs2(son[x],TP);
	}
	for(auto y:V[x]){
		if(y==son[x]||y==fa[x]) continue;
		dfs2(y,y);
	}
	dR[x]=dfn_co;
	return;
}

bool flag;
int A[N],B[N];
void dfs3(int x){
	for(auto y:V[x]){
		if(y==fa[x]) continue;
		dfs3(y);
		A[x]+=A[y];
		B[x]+=B[y];
	}
	if(A[x]!=0&&B[x]!=0){
		flag=1;
	}
	return;
}

int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
} 



void MAIN(){
	int u,v,x;
	cin>>n>>m>>Q;cnt=1;
	memset(hed,0,sizeof(hed));
	for(int i=1;i<=m;++i){
		cin>>u>>v;
		insert(u,v,1);
		insert(v,u,1);
	}
	num=0;
	for(int i=1;i<=n;++i){
		if(dfn[i]==0)
			Tarjan(i,i);
	}
	num=0;
	for(int i=1;i<=n;++i){
		if(co[i]==0){
			++num;
			col(i);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=hed[i];j;j=e[j].nxt){
			if(cut[j]==0) continue;
			V[co[i]].push_back(co[e[j].r]);
		}
	}
	dfn_co=0;
	for(int i=1;i<=n;++i){
		if(dep[i]==0){
			dep[i]=1;fa[i]=0;
			dfs1(i);
			dfs2(i,i);
		}
	}
	flag=0;
	while(Q--){
		cin>>u>>v;
		u=co[u];
		v=co[v];
		if(u==v) continue;
		x=lca(u,v);
		if(x==0) flag=1;
		A[u]++;A[x]--;
		B[v]++;B[x]--;
	}
	for(int i=1;i<=n;++i){
		if(dep[i]==1){
			dfs3(i);
		}
	}
	if(flag) cout<<"No\n";
	else cout<<"Yes\n";
	return;
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
//	init();
//	init_pri();
	int ttt=1;//cin>>ttt; 
	while(ttt--) {
		MAIN();
	}
	return 0;
} 
/*
6
10 8 75 6 7 35
*/