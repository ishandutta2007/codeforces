#include<bits/stdc++.h>
#define LD long double
#define LL long long
#define pb push_back
#define pii pair<int,int>
using namespace std;
const LL INF=1e18;
const int inf=1e9+9;
//const LD PI=acos(-1.0);
//const LL M=998244353;
LL M=1e9+7;
//const LL P=998244353;
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



int n,m,Q,cnt;

int a[N<<1];

struct edge{
	int l,r,t;
}e[N];
struct query{
	int op,x;
}q[N<<1];
vector<int> V[N<<1];
int fa[N<<1];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int tot;
int dfn[N<<1],L[N<<1],R[N<<1];
int F[N<<1][20];
void dfs(int x){
//	cout<<x<<endl;
	for(int i=1;i<=19;++i){
		F[x][i]=F[F[x][i-1]][i-1];
	}
	if(x<=n) {
		dfn[++tot]=x;
		L[x]=tot;
	}
	else{
		L[x]=tot+1;
	}
	for(auto y:V[x]){
		F[y][0]=x;
		dfs(y);
	}
	R[x]=tot;
}
int gettp(int x,int t){
	for(int i=19;i>=0;--i){
		if(a[F[x][i]]>=t){
			x=F[x][i];
		}
	}
	return x;
}

#define ls id<<1
#define rs id<<1|1

struct Segment{
	int l,r;
	int mn;
}d[N<<2];

bool Cut(int id){
	//
	return 0;
}

bool Check(int id){
	//
	return 1;
}

void pushup(int id){
	//
	d[id].mn=d[ls].mn;
	if(a[d[rs].mn]>a[d[id].mn]){
		d[id].mn=d[rs].mn;
	}
	return;
}

void build(int id,int l,int r){
	//
	d[id].l=l;d[id].r=r;
	
	if(l==r){
		//
		d[id].mn=dfn[l];
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(id);
	return;
}

void Change(int id,int l,int r,int ql,int qr){
	if(ql>r||qr<l||Cut(id)) return;
	if(ql<=l&&qr>=r&&Check(id)){
		return;
	}
	int mid=(l+r)>>1;
	Change(ls,l,mid,ql,qr);
	Change(rs,mid+1,r,ql,qr);
	pushup(id);
	return;
} 

int ask(int id,int l,int r,int ql,int qr){
	if(ql>r||qr<l||Cut(id)) return 0;
	if(ql<=l&&qr>=r&&Check(id)){
		return d[id].mn;
	}
	int mid=(l+r)>>1,re1,re2;
	re1=ask(ls,l,mid,ql,qr);
	re2=ask(rs,mid+1,r,ql,qr);
	if(a[re1]>a[re2]) return re1;
	else return re2;
}

void MAIN(){
	int u,v;
	cin>>n>>m>>Q;a[0]=0;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=m;++i){
		cin>>e[i].l>>e[i].r;
		e[i].t=Q+1;
	}
	for(int i=1;i<=Q;++i){
		cin>>q[i].op>>q[i].x;
		if(q[i].op==2){
			e[q[i].x].t=i;
		}
	}
	sort(e+1,e+1+m,[&](edge &x,edge &y){
		return x.t>y.t;
	});
	cnt=n;
	for(int i=1;i<=n;++i) {
		fa[i]=i;
		V[i].clear();
	}
	for(int i=1;i<=m;++i){
		u=find(e[i].l);
		v=find(e[i].r);
		if(u==v) continue;
		++cnt;
		fa[cnt]=cnt;
		V[cnt].clear();
		a[cnt]=e[i].t;
		fa[u]=cnt;
		fa[v]=cnt;
		V[cnt].pb(u);
		V[cnt].pb(v);
	}
	u=find(1);
	for(int i=2;i<=n;++i){
		v=find(i);
		if(u==v) continue;
		++cnt;
		fa[cnt]=cnt;
		V[cnt].clear();
		a[cnt]=0;
		fa[u]=cnt;
		fa[v]=cnt;
		V[cnt].pb(u);
		V[cnt].pb(v);
		u=cnt;
	}
	fa[cnt]=0;F[cnt][0]=0;
	tot=0;
	dfs(cnt);
	
//	cout<<"tot "<<tot<<endl;
	build(1,1,tot);
//	for(int i=1;i<=tot;++i) cout<<dfn[i]<<" ";cout<<endl;
	for(int i=1;i<=Q;++i){
		if(q[i].op==2){
			continue;
		}
		u=gettp(q[i].x,i);
//		cout<<u<<" "<<L[u]<<" "<<R[u]<<endl;
		v=ask(1,1,n,L[u],R[u]);
//		cout<<"v "<<v<<endl;
		cout<<a[v]<<"\n";
		a[v]=0;
		if(v>0)Change(1,1,tot,L[v],R[v]);
	}
	return;
}

int main(){
	srand(time(0));
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
1
5 9 4
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5
*/