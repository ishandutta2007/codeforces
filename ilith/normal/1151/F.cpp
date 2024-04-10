#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define FOR(i,a,b) for(rgi i=a;i<=b;++i)
#define log(a) cerr<<#a<<'='<<(a)<<" @ line "<<__LINE__<<endl
typedef long long ll;
using namespace std;
const int N=110,mod=1e9+7;
int n,t,a[N],m,cnt,g;
ll qpow(ll a,ll b){
	ll ans=1;
	for(;b;b>>=1,(a*=a)%=mod)if(b&1)(ans*=a)%=mod;
	return ans;
}
struct node{
	ll a[N][N];
	node(){memset(a,0,sizeof a);}
	node operator*(node x)const{
		node ans;
		FOR(i,0,m)FOR(j,0,m){
			FOR(k,0,m)(ans.a[i][j]+=a[i][k]*x.a[k][j])%=mod;
		}
		return ans;
	}
	void work(){
		FOR(i,0,m){
			if(i)a[i][i-1]=i*(n-2*m+i);
			a[i][i+1]=(m-i)*(m-i);
			a[i][i]=n*(n-1)/2-(i?a[i][i-1]:0)-a[i][i+1];
		}
	}
}j8,ans;
signed main(){
	scanf("%d%d",&n,&t),g=t;
	FOR(i,1,n)scanf("%d",a+i),m+=a[i];
	FOR(i,n-m+1,n)cnt+=a[i];
	j8.work(),ans=j8;
	for(--t;t;t>>=1,j8=j8*j8)if(t&1)ans=ans*j8;
	printf("%lld",ans.a[cnt][m]*qpow(n*(n-1)/2,mod-1-g)%mod);
	return 0;
}