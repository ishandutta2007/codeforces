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


int n,m,cnt,dfn_co,S,T;
int hed[N],fa[N];
struct edge{
	int r,nxt;
	LL val;
}e[N<<1];
void insert(int u,int v,LL w){
	e[++cnt].r=v;e[cnt].nxt=hed[u];hed[u]=cnt;e[cnt].val=w;
}
LL dis[N],vis[N];
struct Node{
	int l,r;
	LL val;
}a[100005];
priority_queue<pair<LL,int>,vector<pair<LL,int> >,greater<pair<LL,int> > > PQ;
void dij(){
	for(int i=1;i<=n;++i){
		dis[i]=INF;
		vis[i]=0;
	}
	while(!PQ.empty()) PQ.pop();
	dis[S]=0;
	PQ.push(make_pair(dis[S],S));
	int x;
	while(!PQ.empty()){
		x=PQ.top().second;
		PQ.pop();
		if(vis[x]){
			continue;
		}
		vis[x]=1;
		for(int i=hed[x];i;i=e[i].nxt){
			if(dis[e[i].r]>dis[x]+e[i].val){
				dis[e[i].r]=dis[x]+e[i].val;
				fa[e[i].r]=x;
				PQ.push(make_pair(dis[e[i].r],e[i].r));
			}
		}
	}
	return;
}
bool vis2[N]; 
void MAIN(){
	cin>>n>>m;
	LL L;
	cin>>L>>S>>T;++S;++T;
	for(int i=1;i<=m;++i){
		cin>>a[i].l>>a[i].r>>a[i].val;
		++a[i].l;
		++a[i].r;
	}
	cnt=0;
	memset(hed,0,sizeof(hed));
	for(int i=1;i<=m;++i){
		if(a[i].val){
			insert(a[i].l,a[i].r,a[i].val);
			insert(a[i].r,a[i].l,a[i].val);
		}
	}
	dij();
	if(dis[T]<L){
		cout<<"NO\n";
		return;
	}
	if(dis[T]==L){
		cout<<"YES\n";
		for(int i=1;i<=m;++i){
			cout<<a[i].l-1<<" "<<a[i].r-1<<" ";
			if(a[i].val==0) cout<<INF-1LL<<"\n";
			else cout<<a[i].val<<"\n";
		}
		return;
	}
	cnt=0;
	memset(hed,0,sizeof(hed));
	for(int i=1;i<=m;++i){
		if(a[i].val){
			insert(a[i].l,a[i].r,a[i].val);
			insert(a[i].r,a[i].l,a[i].val);
		}
		else{
			insert(a[i].l,a[i].r,1LL);
			insert(a[i].r,a[i].l,1LL);
		}
	}
	dij();
	if(dis[T]>L){
		cout<<"NO\n";
		return;
	}
	if(dis[T]==L){
		cout<<"YES\n";
		for(int i=1;i<=m;++i){
			cout<<a[i].l-1<<" "<<a[i].r-1<<" ";
			if(a[i].val==0) cout<<1<<"\n";
			else cout<<a[i].val<<"\n";
		}
		return;
	}
	int x,y,z,flag;
	while(dis[T]!=L){
		x=T;
		while(x!=S){
			y=fa[x];flag=0;
			for(int i=hed[y];i;i=e[i].nxt){
				if(e[i].r!=x) continue;
				z=(i+1)/2;
				if(a[z].val==0) ++flag;
			}
			if(flag==0){
				x=y;
				continue;
			}
			for(int i=hed[y];i;i=e[i].nxt){
				if(e[i].r!=x) continue;
				z=(i+1)/2;
				if(a[z].val==0){
					e[z*2-1].val=e[z*2].val=1LL+L-dis[T];
				}
			}
			break;
		}
		dij();
	}
	for(int i=1;i<=m;++i){
		a[i].val=e[i+i].val;
	}
	cout<<"YES\n";
		for(int i=1;i<=m;++i){
			cout<<a[i].l-1<<" "<<a[i].r-1<<" "<<a[i].val<<"\n";
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

3 2 10 0 2
0 1 0
1 2 0

*/