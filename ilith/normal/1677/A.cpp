#include<bits/stdc++.h>
#define pbk push_back
#define FOR(i,a,b) for(int i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(int i=a,i##i=b;i>=i##i;--i)
using namespace std;
typedef long long ll;
const int N=5e3+7;
int T,n,m,p[N],s[N][N];
ll ans;
void solve(){
	scanf("%d",&n),ans=0;
	FOR(i,1,n){
		scanf("%d",p+i);
		FOR(j,1,n)s[i][j]=s[i-1][j]+(p[i]<=j);
	}
	FOR(i,1,n)FOR(j,i+1,n){
		ans+=1ll*s[i-1][p[j]-1]*(s[n][p[i]-1]-s[j][p[i]-1]);
	}
	FOR(i,1,n)FOR(j,1,n)s[i][j]=0;
	printf("%lld\n",ans);
}
signed main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}