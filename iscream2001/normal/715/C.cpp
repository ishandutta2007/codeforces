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



int n;
LL ans;
vector<pii> e[N];
vector<LL> pwInv;
vector<LL> pw;
LL A[N],B[N],dep[N];
map<LL,LL> sA[N],sB[N];

void dfs(int u,int F){
	sA[u][A[u]]++;
	sB[u][B[u]]++;
	for(auto x : e[u]){
		int v=x.first;
		LL w=x.second;
		if(v==F) continue;
		dep[v]=dep[u]+1;
		A[v]=(A[u]+w*pw[dep[u]])%M;
		B[v]=(B[u]+w*pwInv[dep[v]])%M;
		dfs(v,u);
		if(sA[v].size()+sB[v].size() > sA[u].size()+sB[u].size()){
			swap(sA[u],sA[v]);
			swap(sB[u],sB[v]);
		}
		for(auto y:sA[v]) {
			LL a=y.first,c=y.second;
			LL b=(B[u]+(A[u]-a+M)*pwInv[2*dep[u]])%M;
			if(sB[u].find(b)!=sB[u].end()){
				ans+=sB[u][b]*c;
			}
        }
        for(auto y:sB[v]){
        	LL b=y.first,c=y.second;
        	LL a=(A[u]+(B[u]-b+M)*pw[2*dep[u]])%M;
        	if(sA[u].find(a)!=sA[u].end()){
        		ans+=sA[u][a]*c;
			}
		}
		for(auto y:sA[v]) {
			LL a=y.first,c=y.second;
        	sA[u][a]+=c;
        }
        for(auto y:sB[v]){
        	LL b=y.first,c=y.second;
        	sB[u][b]+=c;
		}
        sA[v].clear();
        sB[v].clear();
	}
}

void MAIN(){
	int u,v,w;
	cin>>n>>M;
//	int invM = 0;
//    while (M % 10 * invM % 10 != 1) {
//        invM++;
//    }
//    cout<<invM<<endl;
	LL invM=0;
	while(M*invM%10!=1) invM++;
    LL inv10=(1LL+M*(10LL-invM))/10LL%M;
    pw.clear();
    pw.pb(1LL%M);
    for(int i=1;i<2*n;++i) pw.pb(pw[i-1]*10LL%M);
    pwInv.clear();
    pwInv.pb(1LL%M);
    for(int i=1;i<2*n;++i) pwInv.pb(pwInv[i-1]*inv10%M);
    for(int i=0;i<=n;++i) e[i].clear();
    for(int i=1;i<n;++i){
    	cin>>u>>v>>w;
    	e[u].pb(make_pair(v,w));
    	e[v].pb(make_pair(u,w));
	}
	ans=0;
	memset(A,0,sizeof(A));
	memset(B,0,sizeof(B));
	memset(dep,0,sizeof(dep));
	for(int i=0;i<=n;++i){
		sA[i].clear();
		sB[i].clear();
	}
	dfs(0,-1);
	cout<<ans<<"\n";
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
5 9 4
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5
*/