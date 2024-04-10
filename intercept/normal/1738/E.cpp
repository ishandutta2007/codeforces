#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
using namespace std;
const int mod=998244353;
const int M=1e5+9;
int n,k;
ll a[M],b[M],p[M],s[M],pr[M],sr[M],dp[M];
int inv[M],fac[M];
int c(int x,int y){
    if(x<y||y<0)return 0;
    return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*rex*x%mod;
    return rex;
}
void pre(){
    fac[0]=fac[1]=inv[0]=inv[1]=1;
    for(int i=2;i<M;++i){
        fac[i]=1ll*fac[i-1]*i%mod;
        inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    }
    for(int i=2;i<M;++i)inv[i]=1ll*inv[i]*inv[i-1]%mod;
}
void work(){
	cin>>n;
	s[n+1]=0;
	pr[0]=1;
	sr[n+1]=n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n+1;++i){
		p[i]=p[i-1]+a[i];
		pr[i]=a[i]?i:pr[i-1];
	}
	for(int i=n;i>=0;--i){
		s[i]=s[i+1]+a[i];
		sr[i]=a[i]?i:sr[i+1];
	}
	int ans;
	dp[n+1]=ans=1;
	for(int i=n;i>=1;--i){
		int j=upper_bound(p+1,p+i,s[i])-p-1;
		dp[i]=ans;
		if(s[i]!=p[j]||!j){
			continue;
		}
		int l=sr[i]+1,x=l-i,y=j-pr[j]+1;
		ans=(ans+1ll*dp[l]*c(x+y-1,x)%mod)%mod;
		dp[i]=ans;
	}
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	pre();
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
5
5
1 0 1 0 1
3
1 0 1
11
0 1 1 0 0 0 1 1 0 0 1
1
4
0 0 0 0
5
1 0 1 0 0

1
5
1 2 3 2 1
2
1 1
*/