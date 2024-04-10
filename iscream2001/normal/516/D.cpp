#include<bits/stdc++.h>
#define LD long double
#define LL long long
#define pb push_back
#define pii pair<int,int>
using namespace std;
const LL INF=1e18;
const int inf=1e9;
const LD PI=acos(-1.0);
//const LL M=998244353;
LL M=1e9+7;
//const LL P=998244353;
const int N=1e5+10;
const LD eps=1e-8;
const LD eps2=1e-10;
//wth
int ran=0;
bool rand01(){
	while(!ran) ran=abs(rand());
	bool res=ran&1;ran>>=1;
	return res;
}

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

struct HeapNode{
	LL x;
};

bool operator < (HeapNode x,HeapNode y){
	return x.x<y.x;
}

struct HeapTree{
	int n,op;
	int ch[N][2],rt[N];
	bool die[N];
	HeapNode he[N];
	void init(){
		n=0;rt[0]=0;return;
	}
	int NewNode(HeapNode K){
		++n;
		he[n]=K;
		ch[n][0]=ch[n][1]=0;
		rt[n]=n;
		die[n]=0;
		return n;
	}
	int merge(int x,int y){
		if(x==0||y==0) return x|y;
		if(he[x]<he[y]) swap(x,y);
		op^=rand01();
		ch[x][op]=merge(ch[x][op],y);
		return x;
	}
	int findrt(int x){
		return rt[x]==x?x:rt[x]=findrt(rt[x]);
	}
	bool empty(int x){
		return die[x];
	}
	HeapNode top(int x){
		x=findrt(x);
		return he[x];
	}
	void pop(int x){
		if(die[x]) return;
		x=findrt(x);
		rt[x]=merge(ch[x][0],ch[x][1]);
		rt[rt[x]]=rt[x];
		
		die[x]=1;
		return;
	}
	int uni(int x,int y){
		if(die[x]) x=0;
		if(die[y]) y=0;
		x=findrt(x);
		y=findrt(y);
		if(x==y||x==0||y==0) return x|y;
		int z=merge(x,y);
		rt[x]=rt[y]=z;
		return z;
	}
}Heap1;

int n,m,rt;

struct edge{
	int r,w;
};

vector<edge> V[N];

LL lim;
LL dis[N],val[N];

void dfs1(int x,int fa){
	for(auto ed:V[x]){
		int y=ed.r;
		if(y==fa) continue;
		dis[y]=dis[x]+ed.w;
		dfs1(y,x);
	}
}

int siz[N];
void dfs2(int x,int fa){
	siz[x]=1;
	for(auto ed:V[x]){
		int y=ed.r;
		if(y==fa) continue;
		dfs2(y,x);
		Heap1.uni(x,y);
		siz[x]+=siz[y];
	}
	while(siz[x]>0&&Heap1.top(x).x>val[x]+lim){
		Heap1.pop(x);
		siz[x]--;
	}
}

void MAIN(){
	int u,v,w;
	cin>>n;
	for(int i=1;i<=n;++i) {
		val[i]=0;
	}
	for(int i=1;i<n;++i){
		cin>>u>>v>>w;
		V[u].pb((edge){v,w});
		V[v].pb((edge){u,w});
	}
	rt=1;
	dis[rt]=0;dfs1(rt,0);
	rt=1;for(int i=1;i<=n;++i) {
		if(dis[i]>dis[rt]) rt=i;
	}
	dis[rt]=0;dfs1(rt,0);
	for(int i=1;i<=n;++i) {
		val[i]=max(val[i],dis[i]);
		if(dis[i]>dis[rt]) rt=i;
	}
	dis[rt]=0;dfs1(rt,0);
	for(int i=1;i<=n;++i) {
		val[i]=max(val[i],dis[i]);
	}
	for(int i=1;i<=n;++i){
		if(val[i]<val[rt]) rt=i;
	}
	
	
	cin>>m;
	int ans;
	while(m--){
		cin>>lim;ans=0;
		Heap1.init();
		for(int i=1;i<=n;++i){
			Heap1.NewNode((HeapNode){val[i]});
		}
		dfs2(rt,0);
		for(int i=1;i<=n;++i) ans=max(ans,siz[i]);
		cout<<ans<<endl;
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
bad
remotejudge
*/