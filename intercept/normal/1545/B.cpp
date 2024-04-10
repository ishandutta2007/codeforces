#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int M=1e5+9;
int n,fac[M],inv[M];
char c[M];
int C(int x,int y){
	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void work(){
	int x=0,y=0;
	scanf("%d%s",&n,c+1);
	for(int i=1;i<=n;++i){
		if(c[i]=='0')x++;
		if(c[i]=='1'&&i+1<=n&&c[i+1]=='1')y++,i++;
	}
	printf("%d\n",C(x+y,y));
}
int main(){
	fac[0]=inv[0]=inv[1]=1;
	for(int i=1;i<M;++i)fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=2;i<M;++i)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<M;++i)inv[i]=1ll*inv[i]*inv[i-1]%mod;
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}