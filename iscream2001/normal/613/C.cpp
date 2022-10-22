#include<bits/stdc++.h>
#define LD long double
#define LL long long
using namespace std;
const LL INF=1e18;
const int inf=2e9;
//const LD PI=acos(-1.0);
//const LL M=998244353;
const LL M=1e9+7;
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
//LL fac[1000005],finv[1000005];
//LL C(int x,int y,LL mod=M){
//	if(x<y) return 0;
//	return fac[x]*finv[y]%mod*finv[x-y]%mod;
//}
//void init(){
//	fac[0]=fac[1]=finv[0]=finv[1]=1;
//	for(LL i=2;i<=1000000;++i) fac[i]=fac[i-1]*i%M;
//	finv[1000000]=qpow(fac[1000000],M-2,M);
//	for(LL i=1000000;i>1;--i) finv[i-1]=finv[i]*i%M;
//	return;
//}

int n,m;
int num[30],a[30]; 
int X=0,Y=0;
char s[100005];
void check(int x){
//	cout<<x<<endl;
	if(((m/x)%2==0?x+x:x)<=(Y%2==0?X+X:X)) return;
	int flag=0,l=1,r=0,len;
	for(int i=0;i<n;++i){
		a[i]=num[i]/x;
		r+=a[i];
		if(a[i]&1) ++flag;
	}
//	cout<<"f "<<flag<<endl;
	len=r;
	if(flag>1) return;
	for(int i=0;i<n;++i){
		while(a[i]>=2){
			s[l]=s[r]='a'+i;
			a[i]-=2;
			l++;r--;
		}
	}
	for(int i=0;i<n;++i){
		if(a[i]>0){
			s[l]=s[r]='a'+i;
			a[i]--;
		}
	}
	Y=len;X=x;
	return;
}
void MAIN(){
	int g=0;
	cin>>n;m=0;
	for(int i=0;i<n;++i){
		cin>>num[i];
		g=__gcd(num[i],g);
		m+=num[i];
	}
//	cout<<g<<endl;
	
	X=0;Y=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<num[i];++j){
			s[++Y]='a'+i;
		}
	}
	for(int i=1;i<=sqrt(g);++i){
		if(g%i==0){
			check(i);
			check(g/i);
		}
	}
	if(Y%2==0){
		cout<<X+X<<"\n";
	}
	else cout<<X<<"\n";
	for(int i=1;i<=max(X,1);++i){
		for(int j=1;j<=Y;++j){
			cout<<s[j];
		}
	}
	cout<<"\n";
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