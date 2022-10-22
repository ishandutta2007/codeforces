#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define ll long long
#define eb emplace_back
using namespace std;
const int mod=998244353;
const int M=5009;
int n,k;
int inv[M],fac[M];
int c(int x,int y){
    if(x<y||y<0)return 0;
    return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void pre(){
    fac[0]=fac[1]=inv[0]=inv[1]=1;
    for(int i=2;i<M;++i){
        fac[i]=1ll*fac[i-1]*i%mod;
        inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    }
    for(int i=2;i<M;++i)inv[i]=1ll*inv[i]*inv[i-1]%mod;
}
int p[M];
char s[M];
int main(){
	pre();
	cin>>n>>k>>(s+1);
	int t=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='1'){
			p[++t]=i;
		}
	}
	if(k==0||k>t){
		puts("1");
		return 0;
	}
	int ans=0;
	p[t+1]=n+1;
	for(int i=k;i<=t;++i){
		int x=p[i+1]-1,y=p[i-k];
		ans=(ans+c(x-y,k))%mod;
	}
	for(int i=k;i<t;++i){
		int x=p[i+1]-1,y=p[i-k+1];
		ans=(ans+mod-c(x-y,k-1))%mod;
	}
	cout<<ans<<endl;
	return 0;
}
/*
1
5 2
00110
*/