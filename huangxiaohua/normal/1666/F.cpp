#include<bits/stdc++.h>
#define x first
#define y second
#define rnd (rand()<<15|rand())
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<'\n'
#define FOR(a,b,c) for(int a=(b),a##_end=(c);a<=a##_end;++a)
#define ROF(a,b,c) for(int a=(b),a##_end=(c);a>=a##_end;--a)
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f,N=5010,P=998244353;
template<class T>inline bool chkmin(T &x,const T &y){return y<x?x=y,1:0;}
template<class T>inline bool chkmax(T &x,const T &y){return x<y?x=y,1:0;}
int n,a[N],cnt[N],pos[N];
ll inv[N],Inv[N],Invcnt[N];
ll Pow(ll x,ll k){
	ll res=1;
	for(;k;k>>=1){
		if(k&1)res=res*x%P;
		x=x*x%P;
	}
	return res;
}
int dp[N][N],f[N][N],s[N][N];
int main(){
//	printf("%d\n",sizeof(dp)>>20);
	inv[1]=1;FOR(i,2,N-10)inv[i]=(P-P/i)*inv[P%i]%P;
	Inv[0]=1;FOR(i,1,N-10)Inv[i]=Inv[i-1]*inv[i]%P;
	Invcnt[0]=1;
	int cas;
	scanf("%d",&cas);
	while(cas--){
		scanf("%d",&n);
		FOR(i,1,n)scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		FOR(i,1,n)cnt[a[i]]++;
		FOR(i,1,n)pos[i]=pos[i-1]+cnt[i];
		FOR(i,1,n)Invcnt[i]=Invcnt[i-1]*Inv[cnt[i]]%P;
		dp[0][0]=1;
		FOR(i,1,n/2){
			FOR(j,1,n){
				if(pos[j]<2*i)continue;
				if(cnt[j]==0)continue;
				if(i==1&&pos[j-1]>0)
					f[i][j]=1ll*pos[j-1]*cnt[j]%P;
				else f[i][j]=1ll*cnt[j]*s[i-1][j-1]%P;
//				FOR(k,1,j-1)if(pos[k-1]-2*i+3>0){
//					dp[i][j]=(dp[i][j]+dp[i-1][k]*(pos[k-1]-2*i+3)%P*(Invcnt[j-1]*Pow(Invcnt[k],P-2)%P)%P*Inv[cnt[j]-1])%P;
//				}
			}
			FOR(j,1,n)
				if(pos[j-1]-2*i+1>0)
					s[i][j]=(s[i][j-1]+1ll*f[i][j]*(pos[j-1]-2*i+1))%P;
				else s[i][j]=s[i][j-1];
		}
		ll ans=0;
		FOR(j,1,n)
			ans=(ans+1ll*f[n/2][j]*Invcnt[j])%P;
		printf("%lld\n",ans);

		memset(cnt,0,sizeof(cnt));
		memset(pos,0,sizeof(pos));
		FOR(i,0,n){
			memset(dp[i],0,sizeof(int)*(n+5));
			memset(f[i],0,sizeof(int)*(n+5));
			memset(s[i],0,sizeof(int)*(n+5));
		}
	}
	return 0;
}