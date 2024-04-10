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


struct line {
  LL k,b;
  LL at(LL x) { return k * x + b; }
  line(LL _k = 0, LL _b = INF) : k(_k), b(_b) {}
} ;//a[N * 10];
struct LC_SEG{
	line a[N*10];
	int tot, ls[N * 10], rs[N * 10];
	void init(){
		tot=0;
	}
	void modify(int &x, int l, int r, line v) {
		if(!x){
			x=++tot;
			a[x]=line();
			ls[x]=rs[x]=0;
		}
		if(v.at(l) <= a[x].at(l) && v.at(r) <= a[x].at(r)){
			a[x]=v;
			return;
		}
	    if(v.at(l) > a[x].at(l) && v.at(r) > a[x].at(r)) return;
		int mid = (l + r) >> 1;
		if(v.at(mid) <= a[x].at(mid)){
			swap(v,a[x]);
		}
		if(v.k<a[x].k){
			modify(rs[x], mid + 1, r, v);
		}
		else{
			modify(ls[x], l, mid, v);
		}
	}
	LL query(int x, int l, int r, LL pos){
		if(!x) return INF;
		if(l==r) return a[x].at(pos);
		int mid=(l+r)>>1;
		if(pos<=mid) 
			return min(query(ls[x],l,mid,pos),a[x].at(pos));
		else 
			return min(query(rs[x],mid+1,r,pos),a[x].at(pos));
	}
	int merge(int x,int y,int l,int r){
		if(x==0 || y==0) return x|y;
		int mid=(l+r)>>1;
		ls[x]=merge(ls[x],ls[y],l,mid);
		rs[x]=merge(rs[x],rs[y],mid+1,r);
		modify(x,l,r,a[y]);
		return x;
	}
}lcseg;

LL a[N],b[N],ans[N]; 
int n,m,cnt,dfn_co;
vector<int> V[N];
int fa[N];
int dfs(int x){
	int rt=0;
	for(auto to : V[x]) {
	    if (to == fa[x]) continue;
	    fa[to]=x;
	    rt = lcseg.merge(rt, dfs(to), -100000, 100000);
	}
	if (rt) {
	    ans[x] = lcseg.query(rt, -100000, 100000, a[x]);
	}
	lcseg.modify(rt, -100000, 100000, line(b[x], ans[x]));
	return rt;
}
void MAIN(){
	int u,v;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		cin>>b[i];
	}
	for(int i=1;i<n;++i){
		cin>>u>>v;
		V[u].push_back(v);
		V[v].push_back(u);
	}
	lcseg.init();
	dfs(1);
	for(int i=1;i<=n;++i) cout<<ans[i]<<" ";cout<<"\n";
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
*/