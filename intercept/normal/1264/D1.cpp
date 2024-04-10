#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int mod=998244353;
const int M=1e6+9;
int n;
char s[M];
int fac[M],inv[M],L[M],R[M],lp[M],rp[M];
int c(int x,int y){
    if(x<y||y<0)return 0;
    return 1ll*fac[x]*inv[x-y]%mod*inv[y]%mod;
}
void pre(){
    fac[0]=fac[1]=inv[0]=inv[1]=1;
    for(int i=2;i<M;++i){
        fac[i]=1ll*fac[i-1]*i%mod;
        inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    }
    for(int i=2;i<M;++i)inv[i]=1ll*inv[i]*inv[i-1]%mod;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	pre();
	cin>>(s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i){
		L[i]=L[i-1];
		lp[i]=lp[i-1];
		if(s[i]=='(')L[i]++;
		if(s[i]=='?')lp[i]++;
	}
	for(int i=n;i>=1;--i){
		R[i]=R[i+1];
		rp[i]=rp[i+1];
		if(s[i]==')')R[i]++;
		if(s[i]=='?')rp[i]++;
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		int l=L[i],r=R[i+1],x=lp[i],y=rp[i+1];
		ans=(ans+1ll*l*c(x+y,y-l+r)%mod+1ll*x*c(x+y-1,y-l+r-1)%mod)%mod;
	}
	cout<<ans<<"\n";
	return 0;
}