#include<bits/stdc++.h>
#define LD long double
#define LL long long
using namespace std;
const LL INF=1e18;
const int inf=1e9+9;
//const LD PI=acos(-1.0);
//const LL M=998244353;
const LL M=1e9+7;
//const LL P=998244353;
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



int n,m;
char s[105][105]; 
int b[105][105];
int tp=0;
int c[20005][8];
void MAIN(){
	int u,v,op;
	cin>>n>>m;tp=0;
	for(int i=0;i<n;++i){
		cin>>s[i];
		for(int j=0;j<m;++j){
			b[i][j]=s[i][j]-'0';
		}
	}
	for(int i=n-1;i>1;--i){
		for(int j=0;j+1<m;++j){
			if(b[i][j]==0&&b[i][j+1]==0) continue;
			if(b[i][j+1]==0){
				++tp;
				c[tp][1]=i;c[tp][2]=j;
				c[tp][3]=i-1;c[tp][4]=j;
				c[tp][5]=i-1;c[tp][6]=j+1;
			}
			else if(b[i][j]==0){
				++tp;
				c[tp][1]=i;c[tp][2]=j+1;
				c[tp][3]=i-1;c[tp][4]=j;
				c[tp][5]=i-1;c[tp][6]=j+1;
			}
			else{
				++tp;
				c[tp][1]=i;c[tp][2]=j+1;
				c[tp][3]=i;c[tp][4]=j;
				c[tp][5]=i-1;c[tp][6]=j+1;
			}
			b[c[tp][1]][c[tp][2]]^=1;
			b[c[tp][3]][c[tp][4]]^=1;
			b[c[tp][5]][c[tp][6]]^=1;
		}
	}
	for(int i=1;i<=1;++i){
		for(int j=m-1;j>1;--j){
			if(b[i][j]==0&&b[i-1][j]==0) continue;
			if(b[i-1][j]==0){
				++tp;
				c[tp][1]=i;c[tp][2]=j;
				c[tp][3]=i;c[tp][4]=j-1;
				c[tp][5]=i-1;c[tp][6]=j-1;
			}
			else if(b[i][j]==0){
				++tp;
				c[tp][1]=i-1;c[tp][2]=j;
				c[tp][3]=i;c[tp][4]=j-1;
				c[tp][5]=i-1;c[tp][6]=j-1;
			}
			else{
				++tp;
				c[tp][1]=i-1;c[tp][2]=j;
				c[tp][3]=i;c[tp][4]=j;
				c[tp][5]=i;c[tp][6]=j-1;
			}
			b[c[tp][1]][c[tp][2]]^=1;
			b[c[tp][3]][c[tp][4]]^=1;
			b[c[tp][5]][c[tp][6]]^=1;
		}
	}
	if(b[1][0]==1&&b[1][1]==1){
		++tp;
		c[tp][1]=0;c[tp][2]=1;
		c[tp][3]=1;c[tp][4]=0;
		c[tp][5]=1;c[tp][6]=1;
		b[c[tp][1]][c[tp][2]]^=1;
		b[c[tp][3]][c[tp][4]]^=1;
		b[c[tp][5]][c[tp][6]]^=1;
	}
	if(b[1][1]==1){
		++tp;
		c[tp][1]=0;c[tp][2]=0;
		c[tp][3]=0;c[tp][4]=1;
		c[tp][5]=1;c[tp][6]=1;
		b[c[tp][1]][c[tp][2]]^=1;
		b[c[tp][3]][c[tp][4]]^=1;
		b[c[tp][5]][c[tp][6]]^=1;
	}
	if(b[1][0]==1){
		++tp;
		c[tp][1]=0;c[tp][2]=0;
		c[tp][3]=0;c[tp][4]=1;
		c[tp][5]=1;c[tp][6]=0;
		b[c[tp][1]][c[tp][2]]^=1;
		b[c[tp][3]][c[tp][4]]^=1;
		b[c[tp][5]][c[tp][6]]^=1;
	}
	if(b[0][0]==1&&b[0][1]==1){
		++tp;
		c[tp][1]=0;c[tp][2]=0;
		c[tp][3]=1;c[tp][4]=0;
		c[tp][5]=1;c[tp][6]=1;
		b[c[tp][1]][c[tp][2]]^=1;
		b[c[tp][3]][c[tp][4]]^=1;
		b[c[tp][5]][c[tp][6]]^=1;
		++tp;
		c[tp][1]=0;c[tp][2]=1;
		c[tp][3]=1;c[tp][4]=0;
		c[tp][5]=1;c[tp][6]=1;
		b[c[tp][1]][c[tp][2]]^=1;
		b[c[tp][3]][c[tp][4]]^=1;
		b[c[tp][5]][c[tp][6]]^=1;
	}
	if(b[0][0]==1){
		++tp;
		c[tp][1]=0;c[tp][2]=0;
		c[tp][3]=1;c[tp][4]=0;
		c[tp][5]=1;c[tp][6]=1;
		b[c[tp][1]][c[tp][2]]^=1;
		b[c[tp][3]][c[tp][4]]^=1;
		b[c[tp][5]][c[tp][6]]^=1;
	}
	if(b[0][1]==1){
		++tp;
		c[tp][1]=0;c[tp][2]=1;
		c[tp][3]=1;c[tp][4]=0;
		c[tp][5]=1;c[tp][6]=1;
		b[c[tp][1]][c[tp][2]]^=1;
		b[c[tp][3]][c[tp][4]]^=1;
		b[c[tp][5]][c[tp][6]]^=1;
	}
	if(b[1][0]==1&&b[1][1]==1){
		++tp;
		c[tp][1]=0;c[tp][2]=0;
		c[tp][3]=0;c[tp][4]=1;
		c[tp][5]=1;c[tp][6]=0;
		b[c[tp][1]][c[tp][2]]^=1;
		b[c[tp][3]][c[tp][4]]^=1;
		b[c[tp][5]][c[tp][6]]^=1;
		++tp;
		c[tp][1]=0;c[tp][2]=0;
		c[tp][3]=0;c[tp][4]=1;
		c[tp][5]=1;c[tp][6]=1;
		b[c[tp][1]][c[tp][2]]^=1;
		b[c[tp][3]][c[tp][4]]^=1;
		b[c[tp][5]][c[tp][6]]^=1;
	}
	cout<<tp<<"\n";
	for(int i=1;i<=tp;++i){
		cout<<c[i][1]+1<<" "<<c[i][2]+1<<" "<<c[i][3]+1<<" "<<c[i][4]+1<<" "<<c[i][5]+1<<" "<<c[i][6]+1<<"\n";
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
	int ttt=1;cin>>ttt; 
	while(ttt--) {
		MAIN();
	}
	return 0;
} 
/*
6
10 8 75 6 7 35
*/