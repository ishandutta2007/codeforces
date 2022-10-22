#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int mod=998244353;
const int M=209;
int n;
int dp[M][2];
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
	for(int i=2;i<=n;i+=2){
		dp[i][0]=(c(i-1,(i-2)/2)+dp[i-2][1])%mod;
		dp[i][1]=(c(i-2,i/2)+dp[i-2][0])%mod;
	}
	cout<<dp[n][0]<<" "<<dp[n][1]<<" "<<1<<endl;
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
3 10
1 4 2
1
1 4



1000000000
0010000000
0010000000
0000001000
0001000000
0100000000
0000010000
0000000010
*/