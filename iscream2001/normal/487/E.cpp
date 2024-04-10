#include<bits/stdc++.h>
#define LD long double
#define LL long long
#define pb push_back
#define pii pair<int,int>
using namespace std;
const LL INF=1e18;
const int inf=1e9+9;
const LD PI=acos(-1.0);
//const LL M=998244353;
LL M=1e9+7;
//const LL P=998244353;
const int N=1e5+10;
const LD eps=1e-8;
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

int B_S(int *a,int l,int r,int x){
	int mid;
	while(l<=r){
		mid=(l+r)/2;
		if(a[mid]==x) return mid;
		a[mid]>x?r=mid-1:l=mid+1;
	}
	return -1;
}
LL B_S2(LL *a,int l,int r,LL x){
	int mid;
	if(a[r]<x) return -1;
	while(l!=r){
		mid=(l+r)/2;
		if(a[mid]<x) l=mid+1;
		else r=mid;
	}
	return l;
}

int lowbit(int x){
	return (x&-x);
}
int popcount(int x){
	return x==0?0:1+popcount(x-lowbit(x));
}

LL getphi(LL x){
	LL re=1;
	for(LL i=2;i*i<=x;++i){
		if(x%i==0){
			x/=i;re*=(i-1);
			while(x%i==0){
				x/=i;
				re*=i;
			}
		}
	}
	if(x>1){
		re=re*(x-1);
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
//P rotate(P x,LD th){return P(x.x*cos(th)-x.y*sin(th),x.x*sin(th)+x.y*cos(th));}
//
//P waixin(LD x1,LD y1,LD x2,LD y2,LD x3,LD y3){
//double a,b,c,p;
//double  aa,bb,zz,aa1,bb1,zz1;
//	a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//    b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
//    c=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
//    aa=2*(x1-x2);
//    bb=2*(y1-y2);
//    zz=x1*x1-x2*x2+y1*y1-y2*y2;
//    aa1=2*(x3-x2);
//    bb1=2*(y3-y2);
//    zz1=x3*x3-x2*x2+y3*y3-y2*y2;
//    printf("%.2lf %.2lf\n",((zz*bb1)-(zz1*bb))/((aa*bb1)-(aa1*bb)),
//           ((aa*zz1)-(aa1*zz))/((aa*bb1)-(aa1*bb)));
//    return P(((zz*bb1)-(zz1*bb))/((aa*bb1)-(aa1*bb)),
//           ((aa*zz1)-(aa1*zz))/((aa*bb1)-(aa1*bb)));
//}

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

int n,m,num,tp,cnt,Q;
bool Flag;// 
int Sum;
struct edge{int r;};
vector<edge> a[N],b[N+N];
int dfn[N<<1],low[N],q[N],cf[N];

multiset<int> S[N+N];

void sadd(int x,int id){S[id].insert(x);}
void sdel(int x,int id){
	auto it=S[id].lower_bound(x);
	S[id].erase(it);
}
int smin(int id){
	auto it=S[id].begin();
	return (*it);
}


void Tarjan(int x,int fa){
	int y;
	dfn[x]=low[x]=++num;cf[x]=0;
	q[++tp]=x;
	for(int i=0;i<a[x].size();++i){
		y=a[x][i].r;
		if(!dfn[y]){
			Tarjan(y,x);
			cf[x]+=cf[y];
			low[x]=min(low[x],low[y]);
			if(low[y]==dfn[x]){
				++cnt;
				for(int j=0;j!=y;){
					b[cnt].push_back((edge){q[tp]});
					b[q[tp]].push_back((edge){cnt});
					j=q[tp];--tp;
				}
				b[cnt].push_back((edge){x});
				b[x].push_back((edge){cnt});
			//	cout<<cnt<<endl;
			//	for(int j=0;j<b[cnt].size();++j) cout<<b[cnt][j].r<<" ";
			//	cout<<endl;
			}
		}
		else if(dfn[y]<dfn[fa]){
			low[x]=min(low[x],dfn[y]);
			cf[x]++;
			cf[y]--;
		}
		else{
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(cf[x]>1) Flag=1;
	return;
}

int siz[N<<1],son[N<<1],fa[N<<1],dep[N<<1];
void dfs1(int x){
	siz[x]=1;son[x]=0;
	for(int i=0;i<b[x].size();++i){
		int y=b[x][i].r;
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
int dfn_co;
int top[N<<1],dL[N<<1],dR[N<<1];
void dfs2(int x,int TP){
	top[x]=TP;
	dL[x]=++dfn_co;
	dfn[dL[x]]=x;
	if(son[x]){
		dfs2(son[x],TP);
	}
	for(int i=0;i<b[x].size();++i){
		int y=b[x][i].r;
		if(y==son[x]||y==fa[x]) continue;
		dfs2(y,y);
	}
	dR[x]=dfn_co;
	return;
}

int W[N];




#define ls id<<1
#define rs id<<1|1
struct Segment{
	int l,r;
	int mn;
}d[N<<3];

void pushup(int id){
	d[id].mn=min(d[ls].mn,d[rs].mn);
	return;
}

void build(int id,int l,int r){
	d[id].l=l;d[id].r=r;
	if(l==r){
		d[id].mn=0;
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(id);
	return;
}

void Change(int id,int l,int r,int ql,int qr,int K){
	if(ql>r||qr<l) return;
	if(ql<=l&&qr>=r){
		d[id].mn=K;
		return;
	}
	int mid=(l+r)>>1;
	Change(ls,l,mid,ql,qr,K);
	Change(rs,mid+1,r,ql,qr,K);
	pushup(id);
	return;
} 
int Ask(int id,int l,int r,int ql,int qr){
	if(ql>r||qr<l) return inf;
	if(ql<=l&&qr>=r){
		return d[id].mn;
	}
	int mid=(l+r)>>1;
	int re=inf;
	re=min(re,Ask(ls,l,mid,ql,qr));
	re=min(re,Ask(rs,mid+1,r,ql,qr));
	return re;
} 

void MAIN(){
	Flag=0;Sum=0;
	int u,v;
	LL w;
	cin>>n>>m>>Q;cnt=n;
	for(int i=1;i<=n;++i){
		cin>>W[i];
	}
	for(int i=1;i<=m;++i){
		cin>>u>>v;
		a[u].pb((edge){v});
		a[v].pb((edge){u});
	}
	for(int i=1;i<=n;++i){
		if(!dfn[i]){
			Tarjan(i,0);
//			if(Flag){
//				puts("-1");
//				return;
//			}
//			DP(i,0);
		}
	}
	dfs1(1);
//	for(int i=1;i<=cnt;++i) cout<<fa[i]<<endl;
	dfn_co=0;
	dfs2(1,1);
//	for(int i=1;i<=cnt;++i) cout<<top[i]<<endl;
	build(1,1,cnt);
	for(int i=1;i<=n;++i){
		Change(1,1,cnt,dL[i],dL[i],W[i]);
		if(fa[i]>n){// 
			sadd(W[i],fa[i]);
		}
	}
	for(int i=n+1;i<=cnt;++i){
		Change(1,1,cnt,dL[i],dL[i],smin(i));
	}
	char op;
	int ans;
	while(Q--){
		cin>>op>>u>>v;
		if(op=='A'){
			ans=inf;
			while(top[u]!=top[v]){
				if(dep[top[u]]<dep[top[v]]){
					swap(u,v);
				}
				ans=min(ans,Ask(1,1,cnt,dL[top[u]],dL[u]));
				u=fa[top[u]];
			}
			if(dep[u]>dep[v]){
				swap(u,v);
			}
			ans=min(ans,Ask(1,1,cnt,dL[u],dL[v]));
			if(u>n){// 
				ans=min(ans,Ask(1,1,cnt,dL[fa[u]],dL[fa[u]]));
			}
			cout<<ans<<"\n";
		}
		else if(op=='C'){
			if(fa[u]>n){// 
				sdel(W[u],fa[u]);
				sadd(v,fa[u]);
				Change(1,1,cnt,dL[fa[u]],dL[fa[u]],smin(fa[u]));
			}
			W[u]=v;
			Change(1,1,cnt,dL[u],dL[u],W[u]);
		}
	}
	return;
}
/*
*/
int main(){
	srand(time(0));
	std::ios::sync_with_stdio(false);
	cin.tie(0);
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
//	init();
//	init_pri();
	int ttt=1;//cin>>ttt; 
	for(int i=1;i<=ttt;++i){
		//printf("Case #%d: ",i);
		MAIN();
	}
	return 0;
} 
/*
4 2
1 2 3
3 4 5
*/