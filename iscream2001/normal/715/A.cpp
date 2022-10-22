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
//
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


int n,m,cnt,dfn_co;
int hed[N],fa[N],siz[N],son[N],top[N],dL[N],dR[N],dep[N],dfn[N];
struct edge{
	int r,nxt,val;
}e[N<<1];
void insert(int u,int v,int w){
	e[++cnt].r=v;e[cnt].nxt=hed[u];hed[u]=cnt;e[cnt].val=w;
}
void dfs1(int x){
	siz[x]=1;son[x]=0;
	for(int i=hed[x];i;i=e[i].nxt){
		if(fa[x]==e[i].r){
			continue;
		}
		fa[e[i].r]=x;
		dep[e[i].r]=dep[x]+1;
		dfs1(e[i].r);
		siz[x]+=siz[e[i].r];
		if(siz[e[i].r]>siz[son[x]]) son[x]=e[i].r;
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
	for(int i=hed[x];i;i=e[i].nxt){
		if(e[i].r==son[x]||e[i].r==fa[x]) continue;
		dfs2(e[i].r,e[i].r);
	}
	dR[x]=dfn_co;
	return;
}

int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
} 
int a[N];
bool vis[N];
int dp[N];
int tp;
int st[N];
vector<int> V[N]; 
void ins(int x){
	if(tp==0){
		st[tp=1]=x;
		return;
	}
	int ance=lca(st[tp],x);
	while(tp>1&&dep[ance]<dep[st[tp-1]]){
		V[st[tp-1]].push_back(st[tp]);
        --tp;
	}
	if(dep[ance]<dep[st[tp]]) {
		V[ance].push_back(st[tp]);
		tp--;
	}
    if((!tp)||(st[tp]!=ance)) st[++tp]=ance;
    st[++tp]=x;
}
int ans;
void dfs3(int x){
	dp[x]=0;
	for(int i=0;i<V[x].size();++i){
		dfs3(V[x][i]);
		if(dp[V[x][i]]) ++dp[x];
	}
	V[x].clear();
	if(vis[x]==0){
		if(dp[x]<=1) return;
		ans++;
		dp[x]=0;
		return;
	}
	if(dp[x]==0){
		dp[x]=1;
		return;
	}
	ans+=dp[x];
	dp[x]=1;
	return;
}
void MAIN(){
	LL n;
	cin>>n;
	LL x=2,y=1,z,K;
	while(n--){
		z=y*(y+1)*(y+1);K=1;
		while(z*K*K<x){
			++K;
		}
		cout<<(z*K*K-x)<<"\n";
		x=K*y;y++;
	} 
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

4
9 19 6 5
20 15 16 19

*/