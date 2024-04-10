#include<bits/stdc++.h>
#define LD long double
#define LL long long
using namespace std;
const LL INF=1e18;
const int inf=1e9;
//const LD PI=acos(-1.0);
//const LL M=998244353;
const LL M=1e9+7;
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
pair<int,int> ed[N];
vector<int> V[N],V2[N];
bool vis[N],vis2[N];
int du[N];
queue<int> Q;
char ANS[N];
void dfs1(int x){
	vis[x]=1;
	for(int i=0;i<V[x].size();++i){
		if(vis[V[x][i]]==0){
			dfs1(V[x][i]);
		}
	}
}
void dfs2(int x){
	vis2[x]=1;
	for(int i=0;i<V2[x].size();++i){
		if(vis2[V2[x][i]]==0){
			dfs2(V2[x][i]);
		}
	}
}
void MAIN(){
	cin>>n>>m;
	memset(du,0,sizeof(du));
	for(int i=1;i<=m;++i){
		cin>>ed[i].first>>ed[i].second;
		++du[ed[i].second];
		V[ed[i].first].push_back(ed[i].second);
		V2[ed[i].second].push_back(ed[i].first);
	}
	while(!Q.empty()) Q.pop();
	for(int i=1;i<=n;++i){
		if(du[i]==0){
			Q.push(i);
		}
	}
	int u,v;
	while(!Q.empty()){
		u=Q.front();
		Q.pop();
		for(int i=0;i<V[u].size();++i){
			--du[V[u][i]];
			if(du[V[u][i]]==0){
				Q.push(V[u][i]);
			} 
		}
	}
	for(int i=1;i<=n;++i){
		if(du[i]>0){
			cout<<"-1\n";
			return;
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		if(vis[i]==0&&vis2[i]==0) {
			++ans;
			ANS[i]='A';
		}
		else{
			ANS[i]='E';
		}
		if(vis[i]==0){
			dfs1(i);
		}
		if(vis2[i]==0){
			dfs2(i);
		}
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;++i) cout<<ANS[i];
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
/*


*/