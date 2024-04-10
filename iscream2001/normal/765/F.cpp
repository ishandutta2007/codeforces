#include<bits/stdc++.h>
#define LD double
#define LL long long
#define pb push_back
#define pii pair<int,int>
using namespace std;
const LL INF=1e18;
const int inf=1e9+9;
const LD PI=acos(-1.0);
//const LL M=998244353;
LL M=998244353;
//const LL P=998244353;
const int N=1e6+10;
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
int n,m;
int rt=1,cnt=1;
int ls[4000000],rs[4000000],mx[4000000];
void ins(int &id,int l,int r,int x,int y){
	if(id==0) {
		id=++cnt;
		ls[id]=rs[id]=mx[id]=0;
	}
	mx[id]=max(mx[id],y);
	if(l==r) return;
	int mid=(l+r)>>1;
	if(x<=mid) ins(ls[id],l,mid,x,y);
	else ins(rs[id],mid+1,r,x,y);
}
int find(int id,int l,int r,int x,int y){
	if(id==0||r<x||l>y) return 0;
	if(l>=x&&r<=y) return mx[id];
	int mid=(l+r)>>1;
	return max(find(ls[id],l,mid,x,y),find(rs[id],mid+1,r,x,y));
}
int a[N];
struct query{
	int l,r,id;
}q[N];
int ans[N];

struct Segment{
	int l,r,mn;
}d[N<<1];
#define LS id<<1
#define RS id<<1|1

void build(int id,int l,int r){
	d[id].l=l;d[id].r=r;d[id].mn=inf;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(LS,l,mid);
	build(RS,mid+1,r);
}

void change(int id,int l,int r,int ql,int qr,int K){
	if(ql>r||qr<l) return;
	if(ql<=l&&qr>=r){
		d[id].mn=min(d[id].mn,K);
		return;
	}
	int mid=(l+r)>>1;
	change(LS,l,mid,ql,qr,K);
	change(RS,mid+1,r,ql,qr,K);
	return;
}

int ask(int id,int l,int r,int ql){
	if(ql>r||ql<l) return inf;
	if(ql<=l&&ql>=r){
		return d[id].mn;
	}
	int re=d[id].mn;
	int mid=(l+r)>>1;
	re=min(re,ask(LS,l,mid,ql));
	re=min(re,ask(RS,mid+1,r,ql));
	return re;
}

void MAIN(){
	int u,v,w;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;++i){
		cin>>q[i].l>>q[i].r;
		q[i].id=i;ans[i]=inf;
	}
	sort(q+1,q+1+m,[&](query &x,query &y){
		return x.r<y.r;
	});
	
	cnt=1;ls[1]=rs[1]=mx[1]=0;
	build(1,1,n);
//	cout<<"?"<<endl;
	for(int i=1,j=0;i<=m;++i){
		while(j<q[i].r){
			++j;
			int k=find(rt,0,inf,0,a[j]);
			while(k!=0){
				w=a[j]-a[k]; 
				change(1,1,n,1,k,w);
				if(w==0) break;
				w/=2;
				k=find(rt,0,inf,a[j]-w,a[j]);
			}
			ins(rt,0,inf,a[j],j);
		}
		ans[q[i].id]=min(ans[q[i].id],ask(1,1,n,q[i].l));
	}
//	cout<<"?"<<endl;
	reverse(a+1,a+1+n);
	
	for(int i=1;i<=m;++i){
		q[i].l=n+1-q[i].l;
		q[i].r=n+1-q[i].r;
		swap(q[i].l,q[i].r);
	}
	sort(q+1,q+1+m,[&](query &x,query &y){
		return x.r<y.r;
	});
//	cout<<"?"<<endl;
	cnt=1;ls[1]=rs[1]=mx[1]=0;
	build(1,1,n);
	for(int i=1,j=0;i<=m;++i){
//		cout<<i<<" "<<"?"<<" "<<q[i].r<<endl;
		while(j<q[i].r){
			++j;
			int k=find(rt,0,inf,0,a[j]);
			while(k!=0){
//				cout<<j<<" "<<k<<endl;
				w=a[j]-a[k]; 
				change(1,1,n,1,k,w);
				if(w==0) break;
				w/=2;
				k=find(rt,0,inf,a[j]-w,a[j]);
			}
			ins(rt,0,inf,a[j],j);
//			cout<<j<<endl;
		}
//		cout<<j<<endl;
		ans[q[i].id]=min(ans[q[i].id],ask(1,1,n,q[i].l));
	}
	for(int i=1;i<=m;++i) cout<<ans[i]<<"\n";
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
	for(int i=1;i<=ttt;++i){
		//printf("Case #%d: ",i);
		MAIN();
	}
	return 0;
} 
/*
laji rmj
*/