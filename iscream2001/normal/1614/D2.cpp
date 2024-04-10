#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
LL qpow(LL x,LL y,LL P){
	LL re=1;
	x=x%P;
	while(y){
		if(y&1) re=re*x%P;
		x=x*x%P;y>>=1;
	}
	return re;
}

const int N=1e6+10;
const double eps=1e-6;
const LL sed=1e9+7;
const LL P=998244353;
const LL INF=2e18;

LL fac[N+10],inv[N+10];
void init(){
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(LL i=2;i<=N;++i){
		fac[i]=fac[i-1]*i%P;
	}
	inv[N]=qpow(fac[N],P-2,P);
	for(LL i=N;i>1;--i){
		inv[i-1]=inv[i]*i%P;
	}
	return;
}
set<int> S;
set<int>::iterator it;
int n,m;
int a[20000005],b[N];
vector<int> V[N],pp[N];
LL dp[20000005];
void MAIN(){
	int x,y,K;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) {
		scanf("%d",&b[i]);
		V[i].clear();
		K=sqrt(b[i]);
		for(int j=1;j<=K;++j){
			x=b[i]/j;			
			if(b[i]==x*j){
				V[i].push_back(j);
				if(x!=j) V[i].push_back(x); 
			}
		}
		sort(V[i].begin(),V[i].end());
		for(int j=0;j<V[i].size();++j){
			a[V[i][j]]++;
		}
		for(int j=2;j<=sqrt(b[i]);++j){	
			if(b[i]%j==0){
				pp[i].push_back(j);
				b[i]/=j;
				while(b[i]%j==0){
					b[i]/=j;
				}
			}
		}
		if(b[i]>1) pp[i].push_back(b[i]);
	}
	LL ans=0,res;
	dp[1]=a[1];
	for(int i=1;i<=n;++i){
		for(int j=0;j<V[i].size();++j){
			if(dp[V[i][j]]) continue;
			res=a[V[i][j]];
			for(int k=0;k<pp[i].size();++k){
				x=V[i][j]/pp[i][k];
				if(V[i][j]==pp[i][k]*x){
					dp[V[i][j]]=max(dp[V[i][j]],dp[x]+res*(LL)(V[i][j]-x));
				}
			}
		}
		ans=max(ans,dp[V[i][V[i].size()-1]]);
	}
	printf("%lld\n",ans);
	return;
}
int main(){
	int ttt=1;//scanf("%d",&ttt);
	while(ttt--){
		MAIN();
	}
    return 0;
}