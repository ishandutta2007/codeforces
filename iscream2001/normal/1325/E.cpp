#include<bits/stdc++.h>
#define LD long double
#define LL long long
using namespace std;
const LL INF=1e18;
const int inf=1e9;
//const LD PI=acos(-1.0);
//const LL M=998244353;
const LL M=1e9+7;
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
int a[N];
int vis[N];
int dis[N],fa[N];
vector<int> V[N];
int q[N];

int sol(int x){
//	cout<<x<<endl;
	dis[1]=inf;fa[1]=0;
	for(int j=1;pri[j]<=1000000;++j){
		dis[pri[j]]=inf;
		fa[pri[j]]=0;
	}
	int l=1,r=1,re=inf,z=x;
	dis[x]=0;q[1]=x;
	while(l<=r){
		x=q[l++];
		for(auto y: V[x]){
			if(dis[y]>dis[x]+1){
				dis[y]=dis[x]+1;
				fa[y]=x;
				q[++r]=y;
			}
		}
	}
//	cout<<dis[1]<<" "<<dis[2]<<" "<<dis[3]<<" "<<dis[5]<<" "<<dis[7]<<endl;
//	cout<<fa[1]<<" "<<fa[2]<<" "<<fa[3]<<" "<<fa[5]<<" "<<fa[7]<<endl;
	x=1;
	for(auto y:V[x]){
			if(y!=fa[x]&&fa[y]!=x)
				re=min(re,dis[x]+dis[y]+1);
	}
	for(int j=1;pri[j]<=1000000;++j){
		x=pri[j];
		for(auto y:V[x]){
			if(y!=fa[x]&&fa[y]!=x)
				re=min(re,dis[x]+dis[y]+1);
		}
	}
//	cout<<re<<endl;
	return re;
}

void MAIN(){
	int u,v;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		u=0;v=1;
		for(int j=1;pri[j]*pri[j]<=a[i];++j){
			if(a[i]%pri[j]==0){
				u=0;
				while(a[i]%pri[j]==0){
					u++;
					a[i]/=pri[j];
				}
				if(u&1) v*=pri[j];
			}
		}
		if(a[i]>1){
			v*=a[i];
		}
		a[i]=v;
	}
//	for(int i=1;i<=n;++i) cout<<a[i]<<" ";cout<<endl;
	for(int i=1;i<=n;++i){
		if(a[i]==1){
			cout<<"1\n";
			return;
		}
	}
	for(int i=1;i<=n;++i){
		vis[a[i]]++;
	}
	for(int i=1;i<=1000000;++i){
		if(vis[i]>1){
			cout<<"2\n";
			return;
		}
	}
//	cout<<"?"<<endl;
	int ans=inf;
	for(int i=1;i<=n;++i){
		if(is_pri[a[i]]==0){
			V[a[i]].push_back(1);
			V[1].push_back(a[i]);
		}
		else{
			for(int j=1;;++j){
				if(a[i]%pri[j]==0){
//					cout<<a[i]<<" "<<a[i]/pri[j]<<endl;
					V[pri[j]].push_back(a[i]/pri[j]);
					V[a[i]/pri[j]].push_back(pri[j]);
					break;
				}
			}
		}
	}
	ans=min(ans,sol(1));
//	cout<<ans<<endl;
	for(int j=1;pri[j]<=1000;++j){
		ans=min(ans,sol(pri[j]));
//		cout<<pri[j]<<" "<<ans<<endl;
	}
	if(ans==inf) cout<<"-1\n";
	else cout<<ans<<"\n";
	return;
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
//	init();
	init_pri();
	int ttt=1;//cin>>ttt; 
	while(ttt--) {
		MAIN();
	}
	return 0;
} 
/*
6
*/