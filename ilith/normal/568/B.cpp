#include<bits/stdc++.h>
#define pbk push_back
#define FOR(i,a,b) for(int i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(int i=a,i##i=b;i>=i##i;--i)
using namespace std;
typedef long long ll;
const int N=1e5+7,mod=1e9+7;
ll n,f[N][2],g[N][2],ans;
signed main(){
	scanf("%lld",&n),**f=1;
	FOR(i,1,n){
		FOR(j,1,i){
			g[j][0]=(f[j-1][0]+f[j][0]*j)%mod;
			g[j][1]=(f[j-1][1]+f[j][1]*(j+1ll)+f[j][0])%mod;
		}
		**g=0,g[0][1]=1,swap(f,g);
	}
	FOR(i,0,n)(ans+=f[i][1])%=mod;
	printf("%lld",(ans+mod)%mod);
	return 0;
}