#include<bits/stdc++.h>
#define LD long double
#define LL long long
using namespace std;
const LL INF=1e18;
const int inf=1e9+9;
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

int n,m,T,cnt;

#define ls id<<1
#define rs id<<1|1

struct LazyTag{
	LL x;
};

struct Segment{
	int l,r;
	LL sum,mx;
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
	
	return;
}

void pushup(int id){
	//
	d[id].sum=d[ls].sum+d[rs].sum;
	d[id].mx=max(d[ls].mx,d[rs].mx);
	return;
}


void build(int id,int l,int r){
	//
	d[id].l=l;d[id].r=r;
	
	if(l==r){
		//
		d[id].mx=d[id].sum=0;
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(id);
	return;
}

void Change2(int id,int l,int r,int ql,int qr,LazyTag K){
	if(ql>r||qr<l||Cut(id)) return;
	if(d[id].mx<K.x) return;
	if(l==r){
		d[id].mx%=K.x;
		d[id].sum=d[id].mx;
		return;
	}
	int mid=(l+r)>>1;
	Change2(ls,l,mid,ql,qr,K);
	Change2(rs,mid+1,r,ql,qr,K);
	pushup(id);
	return;
} 

void Change3(int id,int l,int r,int ql,int qr,LazyTag K){
	if(ql>r||qr<l||Cut(id)) return;
	if(ql<=l&&qr>=r&&Check(id)){
		d[id].mx=d[id].sum=K.x;
		return;
	}
	int mid=(l+r)>>1;
	Change3(ls,l,mid,ql,qr,K);
	Change3(rs,mid+1,r,ql,qr,K);
	pushup(id);
	return;
} 

LL ask(int id,int l,int r,int ql,int qr){
	if(ql>r||qr<l||Cut(id)) return 0;
	if(ql<=l&&qr>=r&&Check(id)){
		return d[id].sum;
	}
	int mid=(l+r)>>1;
	return ask(ls,l,mid,ql,qr)+ask(rs,mid+1,r,ql,qr);
} 

void MAIN(){
	int u,v,op;LL x;
	cin>>n>>m;
	build(1,1,n);
	for(int i=1;i<=n;++i){
		cin>>x;
		Change3(1,1,n,i,i,(LazyTag){x});
	}
	for(int i=1;i<=m;++i){
		cin>>op;
		if(op==1){
			cin>>u>>v;
			cout<<ask(1,1,n,u,v)<<"\n";
		}
		else if(op==2){
			cin>>u>>v>>x;
			Change2(1,1,n,u,v,(LazyTag){x});
		}
		else if(op==3){
			cin>>u>>x;
			Change3(1,1,n,u,u,(LazyTag){x});
		}
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
6
10 8 75 6 7 35
*/