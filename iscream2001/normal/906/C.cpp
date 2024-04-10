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

int lowbit(int x){
	return (x&-x);
}
int popcount(int x){
	return x==0?0:1+popcount(x-lowbit(x));
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



int n,m,Q,cnt;
int to[(1<<22)+5];
bool vis[(1<<22)+5];
int S;
void dfs(int F){
	for(int j=0;j<n;++j){
		if((S&(1<<j))==0) continue;
		if(to[(1<<F)]&(1<<j)){
			S-=(1<<j);
			dfs(j);
			cout<<j+1<<" ";
		}
	}
	return;
}
void MAIN(){
	int u,v,ans;
	cin>>n>>m;ans=(1<<n)-1;
	for(int i=1;i<=m;++i){
		cin>>u>>v;
		--u;--v;
		to[(1<<u)]|=(1<<v);
		to[(1<<v)]|=(1<<u);
	}
	if(n==1){
		cout<<"0\n";
		return;
	}
	if(m==n*(n-1)/2){
		cout<<"0\n";
		return;
	}
	for(int i=1;i<(1<<n);++i){
		to[i]|=to[i-lowbit(i)];
		to[i]|=to[lowbit(i)];
	}
	for(int i=0;i<n;++i) vis[(1<<i)]=1;
	for(int i=1;i<(1<<n);++i){
		if(vis[i]==0) continue;
		for(int j=0;j<n;++j){
			if(i&(1<<j)) continue;
			if(to[i]&(1<<j)){
				vis[i|(1<<j)]=1;
			}
		}
		if(popcount(i)>=popcount(ans)) continue;
		bool flag=1;
		for(int j=0;j<n;++j){
			if(i&(1<<j)) continue;
			if(to[i]&(1<<j)) continue;
			flag=0;
			break;
		}
		if(flag) ans=i;
	}
	//cout<<ans<<"\n";
	cout<<popcount(ans)<<"\n";
	for(int j=0;j<n;++j){
		if(ans&(1<<j)){
			S=ans-(1<<j);
			dfs(j);
			cout<<j+1<<"\n";
			break;
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
1
8
-1 -1 -1 0 -1 6 -7 2 
3
1 2 3
3
1 -2 -3
*/