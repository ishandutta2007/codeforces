#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int M=4e6+9;
int n,m;
char s[2009];
int fac[M],inv[M];
int c(int x,int y){
	if(x<y)return 0;
	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void work(){
	int num=0,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		for(int j=1;j<=m;++j){
			if(s[j]=='0')num++;
		}
	}
	if(num)ans=1;
	for(int i=1;i<=n*m;++i){
		ans=(ans+c(n*m-num,i))%mod;
	}
	printf("%d\n",ans);
}
int main(){
	fac[0]=inv[0]=inv[1]=1;
	for(int i=1;i<M;++i)fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=2;i<M;++i)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<M;++i)inv[i]=1ll*inv[i-1]*inv[i]%mod;
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}