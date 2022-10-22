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
const int N=5e5+10;
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

int B_S(int *a,int l,int r,int x){
	int mid;
	while(l<=r){
		mid=(l+r)/2;
		if(a[mid]==x) return mid;
		a[mid]>x?r=mid-1:l=mid+1;
	}
	return -1;
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



int n,m,cnt,Q,K,L;
struct query{
	int op,x,y;
}que[N];
int cntx,cnty;
int X[N],Y[N];
multiset<int> S[N];
multiset<int>::iterator it;

#define ls id<<1
#define rs id<<1|1

struct Segment{
	int l,r;
	int mx;
}d[N<<2];

void pushup(int id){
	d[id].mx=max(d[ls].mx,d[rs].mx);
	return;
}

void build(int id,int l,int r){
	d[id].l=l;d[id].r=r;
	if(l==r){
		d[id].mx=-1;
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
		d[id].mx=K;
		return;
	}
	int mid=(l+r)>>1;
	Change(ls,l,mid,ql,qr,K);
	Change(rs,mid+1,r,ql,qr,K);
	pushup(id);
	return;
} 

int res;
void Ask(int id,int l,int r,int ql,int qr,int K){
	if(ql>r||qr<l) return;
	if(d[id].mx<=K) return;
	if(l>=res) return;
	if(l==r){
		res=l;
		return;
	}
	int mid=(l+r)>>1;
	Ask(ls,l,mid,ql,qr,K);
	Ask(rs,mid+1,r,ql,qr,K);
	return;
} 
void MAIN(){
	LL u,v;
	char opp[10];
	cin>>K;
	for(int i=1;i<=K;++i){
		cin>>opp>>que[i].x>>que[i].y;
		if(opp[0]=='a') que[i].op=1;
		if(opp[0]=='r') que[i].op=2;
		if(opp[0]=='f') que[i].op=3;
		X[i]=que[i].x;
		Y[i]=que[i].y;
	}
	sort(X+1,X+1+K);sort(Y+1,Y+1+K);
	cntx=unique(X+1,X+1+K)-X-1;
	cnty=unique(Y+1,Y+1+K)-Y-1;
	for(int i=1;i<=K;++i){
		que[i].x=B_S(X,1,cntx,que[i].x);
		que[i].y=B_S(Y,1,cnty,que[i].y);
	}
	for(int i=1;i<=cntx;++i) S[i].insert(-1);
	build(1,1,cntx);
	for(int i=1;i<=K;++i){
		if(que[i].op==1){
			S[que[i].x].insert(que[i].y);
			it=S[que[i].x].end();
			--it;
			Change(1,1,cntx,que[i].x,que[i].x,(*it));
		}
		if(que[i].op==2){
			it=S[que[i].x].lower_bound(que[i].y);
			S[que[i].x].erase(it);
			it=S[que[i].x].end();
			--it;
			Change(1,1,cntx,que[i].x,que[i].x,(*it));
		}
		if(que[i].op==3){
			res=cntx+1;
			Ask(1,1,cntx,que[i].x+1,cntx,que[i].y);
			if(res>cntx){
				cout<<"-1\n";
				continue;
			}
			it=S[res].upper_bound(que[i].y);
			cout<<X[res]<<" "<<Y[(*it)]<<"\n";
		}
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
*/