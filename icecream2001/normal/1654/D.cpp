#include<bits/stdc++.h>
#define LD long double
#define LL long long
using namespace std;
const LL INF=1e18;
const int inf=2e9;
//const LD PI=acos(-1.0);
const LL M=998244353;
//const LL M=1e9+7;
const int N=3e5+10;
const LD eps=1e-8;
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
bool is_pri[N+10];
LL pri[6000000];
//int mu[N+10];
int cntp=0;

void init_pri(){
//	mu[1]=1;
    for(int i=2;i<=N;++i){
        if(!is_pri[i]) {
            pri[++cntp]=i;
  //          mu[i]=-1;
        }
        for(int j=1;j<=cntp&&pri[j]*i<=N;++j){
            is_pri[pri[j]*i]=1;
            if(i%pri[j]==0) {
    //        	mu[pri[j]*i]=0;
                break;
            }
            else{
      //      	mu[pri[j]*i]=-mu[i];
			}
        }
    }
}
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
 
int n,m,K;
struct edge{
	LL r,x,y;
};
vector<edge> V[200005];
LL cnt[200005];
LL mn[200005],val[200005];
void dfs(int x,int y){
	LL z;
	for(int i=0;i<V[x].size();++i){
		if(V[x][i].r==y) continue;
		val[V[x][i].r]=val[x]*qpow(V[x][i].x,M-2,M)%M*V[x][i].y%M;
		z=V[x][i].x;
		for(LL o=1;pri[o]<=sqrt(z);++o){
			if(z%pri[o]==0){
				while(z%pri[o]==0){
					z/=pri[o];
					cnt[pri[o]]--;
				}
			}
		}
		if(z>1) cnt[z]--;
		z=V[x][i].y;
		for(LL o=1;pri[o]<=sqrt(z);++o){
			if(z%pri[o]==0){
				while(z%pri[o]==0){
					z/=pri[o];
					cnt[pri[o]]++;
				}
			}
		}
		if(z>1) cnt[z]++;
		
		
		z=V[x][i].x;
		for(LL o=1;pri[o]<=sqrt(z);++o){
			if(z%pri[o]==0){
				while(z%pri[o]==0){
					z/=pri[o];
					mn[pri[o]]=min(mn[pri[o]],cnt[pri[o]]);
				}
			}
		}
		if(z>1) mn[z]=min(mn[z],cnt[z]);
		z=V[x][i].y;
		for(LL o=1;pri[o]<=sqrt(z);++o){
			if(z%pri[o]==0){
				while(z%pri[o]==0){
					z/=pri[o];
					mn[pri[o]]=min(mn[pri[o]],cnt[pri[o]]);
				}
			}
		}
		if(z>1) mn[z]=min(mn[z],cnt[z]);
		
		dfs(V[x][i].r,x);
		
		
		z=V[x][i].x;
		for(LL o=1;pri[o]<=sqrt(z);++o){
			if(z%pri[o]==0){
				while(z%pri[o]==0){
					z/=pri[o];
					cnt[pri[o]]++;
				}
			}
		}
		if(z>1) cnt[z]++;
		z=V[x][i].y;
		for(LL o=1;pri[o]<=sqrt(z);++o){
			if(z%pri[o]==0){
				while(z%pri[o]==0){
					z/=pri[o];
					cnt[pri[o]]--;
				}
			}
		}
		if(z>1) cnt[z]--;
	}
	return;
}
void MAIN(){
	cin>>n;
	LL u,v,x,y;
	for(int i=1;i<=n;++i){
		cnt[i]=mn[i]=val[i]=0;
		V[i].clear();
	}
	for(int i=1;i<n;++i){
		cin>>u>>v>>x>>y;
		V[u].push_back((edge){v,x,y});
		V[v].push_back((edge){u,y,x});
	}
	val[1]=1LL;
	dfs(1,0);
	LL ans=0;
	for(int i=1;i<=n;++i){
		ans+=val[i];
	}
	ans%=M;
	for(LL i=1;i<=n;++i){
		ans=ans*qpow(i,abs(mn[i]),M)%M;
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
//	init();
	init_pri();
	int ttt=1;cin>>ttt; 
	while(ttt--) {
		MAIN();
	}
	return 0;
} 
/*

4 3
0 0
1 0
1 1
0 1
*/