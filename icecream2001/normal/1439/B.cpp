#include<bits/stdc++.h>
#define LD long double
#define LL long long
#define pb push_back
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



int n,m,K;
bool vis[N];
int du[N];
vector<int> V[N],U;
unordered_map<int,int> mp[N];
queue< int > Q;
bool check(){
	sort(U.begin(),U.end());
	for(int i=0;i<U.size();++i){
		for(int j=i+1;j<U.size();++j){
//			cout<<U[i]<<" "<<U[j]<<endl;
//			for(auto k:V[U[i]]){
//				cout<<k<<" ";
//			}
//			cout<<endl;
//			cout<<binary_search(V[U[i]].begin(), V[U[i]].end(), U[j])<<endl;
			if(binary_search(V[U[i]].begin(), V[U[i]].end(), U[j])==0){
				return 0;
			}
		}
	}
	return 1;
}
bool flag=1;
void MAIN(){
	int u,v;
	cin>>n>>m>>K;
	for(int i=1;i<=n;++i){
		V[i].clear();
		vis[i]=1;
		du[i]=0;
		mp[i].clear();
	}
	for(int i=1;i<=m;++i){
		cin>>u>>v;
		V[u].push_back(v);
		V[v].push_back(u);
		++du[u];++du[v];
		//mp[u][v]=1;
	}
//	if(n==100000&&m==100000&&K==10){
//		cout << -1 <<"\n";
//		//flag=0;
//	   return;
//	}
	for(int i=1;i<=n;++i){
		sort(V[i].begin(),V[i].end());
	}
	if(K > 450) {
	   cout << -1 <<"\n";
	   return;
	}
	while(!Q.empty()) Q.pop();
	for(int i=1;i<=n;++i) if(du[i]<K)Q.push(i);
	int x;
//	for(int i=1;i<=n;++i) cout<<du[i]<<" ";cout<<endl;
	while(!Q.empty()){
		x=Q.front();Q.pop();
		if(vis[x]==0) continue;
		if(du[x]>=K) continue;
		if(du[x]==K-1){
			U.clear();
			U.push_back(x);
			for(auto y:V[x]){
				if(vis[y]==0) continue;
				U.push_back(y);
			}
			if(check()){
				cout<<2<<"\n";
				for(auto y:U){
					cout<<y<<" ";
				}
				cout<<"\n";
				return;
			}
		}
		vis[x]=0;
		for(auto y:V[x]){
			if(vis[y]==0) continue;
			--du[y];
			if(du[y]<K) Q.push(y);
		}
//		for(int i=1;i<=n;++i) cout<<du[i]<<" ";cout<<endl;
	}
	
	U.clear();
	for(int i=1;i<=n;++i) if(vis[i]) U.push_back(i);
	if(U.size()>K){
		cout<<1<<" "<<U.size()<<"\n";
		for(auto y:U){
			cout<<y<<" ";
		}
		cout<<"\n";
	}
	else{
		cout<<"-1\n";
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
	int ttt=1;cin>>ttt; 
	while(ttt--&&flag) {
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