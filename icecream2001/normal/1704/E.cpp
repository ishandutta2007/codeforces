#include<bits/stdc++.h>
#define LD double
#define LL long long
#define pb push_back
#define pii pair<int,int>
using namespace std;
const LL INF=1e18;
const int inf=1e9;
const LD PI=acos(-1.0);
//const LL M=998244353;
LL M=998244353;
//const LL P=998244353;
const int N=1e6+10;
const LD eps=1e-6;
const LD eps2=1e-10;

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

LL fac[1000005],finv[1000005];
LL C(LL x,LL y,LL mod=M){
	if(x<y) return 0;
	if(x<=1000000) return fac[x]*finv[y]%mod*finv[x-y]%mod;
	LL re=1;
	y=min(y,x-y);
	for(LL i=x-y+1;i<=x;++i){
		re=re*i%M;
	}
	re=re*finv[y]%M;
	return re;
}
void init(){
	fac[0]=fac[1]=finv[0]=finv[1]=1;
	for(LL i=2;i<=1000000;++i) fac[i]=fac[i-1]*i%M;
	finv[1000000]=qpow(fac[1000000],M-2,M);
	for(LL i=1000000;i>1;--i) finv[i-1]=finv[i]*i%M;
	return;
}


//double rad(double d){
//    return d*PI/180.0;
//}
//double cal(double lat1,double lng1,double lat2,double lng2){
//	double a,b,radLat1 = rad(lat1),radLat2 = rad(lat2);
//    a = radLat1 - radLat2;
//    b = rad(lng1) - rad(lng2);
//    double s = 2 * asin(sqrt(pow(sin(a/2),2) + cos(radLat1)*cos(radLat2)*pow(sin(b/2),2)));
//    return s;
//}

int n,m,cnt;
LL a[N];
int du[1050];
vector<int> V[1050];
int l,r;
int q[N];
struct node{
	LL t,sum;
};
vector<node> W[1050],A;
void MAIN(){
	LL sum=0;
	int u,v;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		du[i]=0;
		cin>>a[i];
		W[i].clear();
		if(a[i]>0) W[i].pb((node){1LL,a[i]});
		V[i].clear();
	}
	for(int i=1;i<=m;++i){
		cin>>u>>v;
		du[v]++;
		V[u].pb(v);
	}
	l=1;r=0;
	for(int i=1;i<=n;++i){
		if(du[i]==0){
			q[++r]=i;
		}
	}
	LL ans=0;
	node tmp;
//	for(int i=1;i<=n;++i) cout<<W[i].size()<<endl;
	while(l<=r){
		u=q[l++];
		A.clear();
		if(W[u].size()!=0){
//			cout<<W[u].size()<<endl;
			sort(W[u].begin(),W[u].end(),[&](node &x,node &y){
				return x.t<y.t;
			});
			tmp=W[u][0];
			for(int i=1;i<W[u].size();++i){
				if(tmp.t+tmp.sum>=W[u][i].t){
					tmp.sum+=W[u][i].sum;
					if(tmp.sum>=M) tmp.sum=tmp.sum%M+M;
				}
				else{
					A.pb(tmp);
					tmp=W[u][i];
				}
			}
			A.pb(tmp);
			ans=tmp.t+tmp.sum-1;
//			cout<<u<<endl;
//			for(int i=0;i<A.size();++i){
//				cout<<A[i].t<<" "<<A[i].sum<<endl;
//			}
		}
		
		for(auto x:V[u]){
			for(int i=0;i<A.size();++i){
				tmp=A[i];
				tmp.t++;
				W[x].pb(tmp);
			}
			--du[x];
			if(du[x]==0){
				q[++r]=x;
			}
		}
	}
	
	cout<<(ans%M+M)%M<<endl;
	return;
	//cout<<V[V.size()-1]<<endl;
//	cout<<qpow((LL)2,n,M)*2*n%M<<endl;
//	double x;
//	scanf("%lf",&x);
//	printf("%0.10lf\n",x*1.003);
//	printf("%0.10lf\n",x*0.992);
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
	int ttt=1;cin>>ttt; 
	for(int i=1;i<=ttt;++i){
		//printf("Case #%d: ",i);
		MAIN();
	}
	return 0;
}
/*
*/