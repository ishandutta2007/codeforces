#include<bits/stdc++.h>
#define LD long double
#define LL long long
using namespace std;
const LL INF=1e18;
const int inf=2e9;
//const LD PI=acos(-1.0);
const LL M=998244353;
const int N=2e5+10;
const LD eps=1e-7;
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
LL fac[1000005],finv[1000005];
LL C(int x,int y,LL mod=M){
	if(x<y) return 0;
	return fac[x]*finv[y]%mod*finv[x-y]%mod;
}
void init(){
	fac[0]=fac[1]=finv[0]=finv[1]=1;
	for(LL i=2;i<=1000000;++i) fac[i]=fac[i-1]*i%M;
	finv[1000000]=qpow(fac[1000000],M-2,M);
	for(LL i=1000000;i>1;--i) finv[i-1]=finv[i]*i%M;
	return;
}

int n,m,lim;
int a[200005],b[200005];
#define ls id<<1
#define rs id<<1|1
struct Segment{
	int l,r;
	//Val
	
	//LazyTag 
	LL c,v;
}d[N<<2];

bool Cut(int id){
	//
	return 0;
}

bool Check(int id){
	//
	return 1;
}

void PutTag(int id){
	//
	
	return;
}

void pushup(int id){
	//
	if(d[id].l==d[id].r) return;
	d[id].v=d[ls].v+d[rs].v;
	d[id].c=d[ls].c*d[rs].c%M*C(d[id].v,d[ls].v)%M;
	return;
}

void pushdown(int id){
	//
	
	return;
}

void build(int id,int l,int r){
	//
	d[id].l=l;d[id].r=r;
	
	if(l==r){
		//
		d[id].c=1;
		d[id].v=0;
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(id);
	return;
}
void Change(int id,int l,int r,int ql,int x){
	if(ql>r||ql<l||Cut(id)) return;
	if(l==r){
		d[id].v+=x;
		d[id].c=1;
		return;
	}
	int mid=(l+r)>>1;
	if(ql<=mid) Change(ls,l,mid,ql,x);
	else Change(rs,mid+1,r,ql,x);
	pushup(id);
	return;
} 

LL re1,re2;
/*
3 3
1 2 3
3 2 1
*/
void ask2(int id,int l,int r,int ql,int qr){
	if(ql>r||qr<l||Cut(id)) return;
	if(ql<=l&&qr>=r&&Check(id)){
	//	cout<<"?"<<endl;
		re2+=d[id].v;
		re1=re1*d[id].c%M*C(re2,d[id].v)%M;
		return;
	}
	int mid=(l+r)>>1;
	ask2(ls,l,mid,ql,qr);
	ask2(rs,mid+1,r,ql,qr);
	return;
} 
int num[200005];
int t[200005];

void add(int x,int y){
	while(x<=lim){
		t[x]+=y;
		x+=x&-x;
	}
}
int ask(int x){
	int re=0;
	while(x){
		re+=t[x];
		x-=x&-x;
	}
	return re;
}

void MAIN(){
	int x;
	cin>>n>>m;lim=200000;
	build(1,1,lim);
	for(int i=1;i<=lim;++i) num[i]=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		num[a[i]]++;
	}
	for(int i=1;i<=lim;++i){
		if(num[i]>0){
			Change(1,1,lim,i,num[i]);
		}
	}
	for(int i=1;i<=m;++i){
		cin>>b[i];
	}
	int it=1;
	LL ans=0,now1,now2;
	while(1){
	//	cout<<it<<" "<<ans<<endl;
		if(it>m){
			break;
		}
		if(it>n){
			++ans;
			break;
		}
		
		re1=1;re2=0;
	//	cout<<b[it]-1<<endl;
		if(1<=b[it]-1) ask2(1,1,lim,1,b[it]-1);
		now1=re1;now2=re2;
	//	cout<<"?"<<now1<<" "<<now2<<endl;
		re1=1;re2=0;
		if(b[it]<=lim) ask2(1,1,lim,b[it],lim);
		if(now2>0){
			ans+=re1*now1%M*C(now2+re2-1,re2)%M;
		}
		if(num[b[it]]>0){
			num[b[it]]--;
			Change(1,1,lim,b[it],-1);
		}
		else{
			break;
		}
		++it;
	}
	ans=(ans%M+M)%M;
	
	cout<<ans<<"\n";
	return;
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	init();
//	init_pri();
	int ttt=1;//cin>>ttt; 
	while(ttt--) {
		MAIN();
	}
	return 0;
}