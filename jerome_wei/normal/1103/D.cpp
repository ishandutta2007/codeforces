#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=10000000000000000ll;
ll read(){
	char x=0;ll ret=0;while(x<'0'||x>'9')x=getchar();
	while(x>='0'&&x<='9')ret=ret*10ll+x-'0',x=getchar();return ret;
}
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
int n;ll k,G;

map <vector<ll>,vector<int> >f;
ll a[1000010],e[1000010];
vector<ll> primes;
ll dp[1<<15][20];
int can[1<<20];

int main()
{
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
//		cout<<a[i]<<endl;
		G=gcd(a[i],G);
//		cout<<G<<endl;
	}
	for(int i=1;i<=n;i++)e[i]=read();
	for(int i=2;1ll*i*i<=G;i++){
		if(G%i==0){
			primes.push_back(i);
			while(G%i==0)G/=i;
		}
	}
	if(G>1)primes.push_back(G);
	int m=primes.size();
	for (int i=1;i<=n;i++){
		vector<ll> p(m,1);
		for(int j=0;j<m;j++){
			while(a[i]%primes[j]==0){
				a[i]/=primes[j];
				p[j]*=primes[j];
			}
		}
		f[p].push_back(e[i]);
	}
	for(int i=0;i<1<<m;i++) for(int j=0;j<=m;j++)dp[i][j]=INF;
	dp[0][0]=0;
	for(auto  p:f){
		sort(p.second.begin(),p.second.end());
		for(int i=0;i<1<<m;i++)can[i]=0;
		for(int i=0;i<1<<m;i++){
			ll KK=1;
			for(int j=0;j<m;++j)if((i>>j)&1){
				KK*=p.first[j];
			}
			if(KK<=k)can[i]=1;
		}
		for(int i=1;i<1<<m;i<<=1)
			for(int j=0;j<m;j+=i<<1){
				for(int k=0;k<i;++k)
					can[j+k]+=can[j+k+i];
			}
		vector<int>useful;
		for(int i=1;i<1<<m;++i)if(can[i]==1)useful.push_back(i);
		for(auto v :p.second){
			bool chg=false;
			for(int i=(1<<m)-1;~i;i--){
				for(int j=m-1;~j;j--){
					for(auto k:useful){
						if(dp[i|k][j+1]>dp[i][j]+v){
							dp[i|k][j+1]=dp[i][j]+v;
							chg=1;
						}
					}
				}
			}
			if(!chg)break;
		}
	}
	ll ans=INF;
	for(int i=0;i<=m;i++){
		if(dp[(1<<m)-1][i]!=INF)ans=min(ans,dp[(1<<m)-1][i]*i);
	}
	if(ans==INF)ans=-1;
	cout<<ans<<endl;
	return 0;
}