#include<bits/stdc++.h>
#define LD long double
#define LL long long
using namespace std;
const LL INF=1e18;
const int inf=1e9+9;
//const LD PI=acos(-1.0);
//const LL M=998244353;
const LL M=1e9+7;
const LL P=998244353;
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

LL T[3][2][2];
LL inv2=qpow((LL)2,P-2,P);
void findFWT(int x){
	for(int l=0;l<531441;++l){
		int tmp=l;
		for(int k=0;k<3;++k){
			for(int i=0;i<2;++i){
				for(int j=0;j<2;++j){
					T[k][i][j]=1-tmp%3;
					tmp/=3;
				}
			}
		}
		int det=T[2][0][0]*T[2][1][1]-T[2][0][1]*T[2][1][0];
		if(!det) continue;
		bool f=1;
		for(int k=0;k<2;++k){
			int cnf[4]={0,0,0,0};
			for(int i=0;i<2;++i){
				for(int j=0;j<2;++j){
					cnf[i<<1|j]+=T[0][k][i]*T[1][k][j];
				}
			}
			for(int i=0;i<4;++i)
				if(cnf[i]!=T[2][k][((x>>i)&1)])
					f=0;
		}
		if(f){
			swap(T[2][0][0],T[2][1][1]);
			T[2][0][1]*=-1;
			T[2][1][0]*=-1;
			for(int i=0;i<2;i++)
				for(int j=0;j<2;j++){
					T[2][i][j]=T[2][i][j]*2/det;
				}
			break;
		}
	}
	return;
}

void FWT(LL *a,int n,int flag){
	LL x,y;
	for(int l=2;l<=n;l<<=1){
		int m=l>>1;
		for(LL *p=a;p!=a+n;p+=l)
			for(int k=0;k<m;++k){
				x=p[k];y=p[k+m];
				p[k]=(T[flag][0][0]*x+T[flag][0][1]*y)%P;
				p[k+m]=(T[flag][1][0]*x+T[flag][1][1]*y)%P;
				//x0y1
				//p[k]0p[k+m]1
				if(flag==2) {
					p[k]=p[k]*inv2%P;
					p[k+m]=p[k+m]*inv2%P;
					//
				}
			}	
	}
	return;
}

int n,m;
char s[N];
int c[N];
LL a[(1<<20)+5],b[(1<<20)+5];
int popcount(int x){
	int re=0;
	while(x){
		x-=x&-x;
		++re;
	}
	return re;
}
void MAIN(){
	int u,v,op;
	cin>>n>>m;
	for(int j=0;j<m;++j) c[j]=0;
	for(int i=0;i<n;++i){
		cin>>s;
		for(int j=0;j<m;++j){
			c[j]+=((s[j]-'0')<<i);
		}
	} 
//	for(int j=0;j<m;++j) cout<<c[j]<<" ";cout<<endl;
	for(int j=0;j<m;++j){
		a[c[j]]++;
	}
	for(int i=0;i<(1<<n);++i){
		b[i]=min(popcount(i),n-popcount(i));
	}
//	for(int i=0;i<(1<<n);++i) cout<<a[i]<<" ";cout<<endl;
	findFWT(6);
	FWT(a,(1<<n),0);
	FWT(b,(1<<n),1);
	for(int i=0;i<(1<<n);++i) a[i]=a[i]*b[i]%P;
	FWT(a,(1<<n),2);
	LL ans=INF;
	for(int i=0;i<(1<<n);++i){
		if(a[i]<0) a[i]+=P;
		ans=min(ans,a[i]);
	}
	cout<<ans<<"\n";
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