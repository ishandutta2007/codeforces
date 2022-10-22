#include<bits/stdc++.h>
using namespace std;
const int Mod=1e9+7;
typedef long long ll;
int n,k,x[110000],y[110000],z[110000],p[110000],q[110000],numx[110000],numy[110000];
ll fac[110000],sta[110000]; vector<pair<int,ll>> vec[110000]; map<ll,int> dp[55][55];
int main(){
	srand(time(NULL));
	fac[0]=1; for (int i=1;i<=100000;i++) fac[i]=fac[i-1]*i%Mod;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){ p[i]=i; swap(p[i],p[rand()%i+1]);}
	for (int i=1;i<=n;i++){ q[i]=i; swap(q[i],q[rand()%i+1]);}
	for (int i=1;i<=k;i++){
		scanf("%d%d%d",&x[i],&y[i],&z[i]); z[i]--;
		x[i]=p[x[i]]; y[i]=q[y[i]];
		numx[i]=x[i]; numy[i]=y[i];
	}
	sort(numx+1,numx+k+1); int cntx=unique(numx+1,numx+k+1)-numx-1;
	sort(numy+1,numy+k+1); int cnty=unique(numy+1,numy+k+1)-numy-1;
	for (int i=1;i<=k;i++){
		x[i]=lower_bound(numx+1,numx+cntx+1,x[i])-numx-1;
		y[i]=lower_bound(numy+1,numy+cnty+1,y[i])-numy-1;
		vec[x[i]].push_back(make_pair(y[i],z[i]));
	}
	for (int i=cntx-1;i>=0;i--){
		sta[i]=sta[i+1];
		for (pair<int,ll> v:vec[i]) sta[i]|=(1ll<<v.first);
	}
	
	dp[0][0][0]=1;
	for (int i=0;i<cntx;i++)
		for (int j=0;j<=i;j++)
			for (pair<ll,int> k:dp[i][j]){
				dp[i+1][j][k.first&sta[i+1]]=(dp[i+1][j][k.first&sta[i+1]]+k.second)%Mod;
				for (pair<int,ll> t:vec[i])
					if (!(k.first&(1ll<<t.first)))
						dp[i+1][j+1][(k.first|(1ll<<t.first))&sta[i+1]]=(dp[i+1][j+1][(k.first|(1ll<<t.first))&sta[i+1]]+k.second*t.second)%Mod;
			}
			
	ll ans=0;
	for (int i=0;i<=cntx;i++) ans=(ans+fac[n-i]*dp[cntx][i][0])%Mod;
	printf("%lld\n",ans);
	return 0;
}