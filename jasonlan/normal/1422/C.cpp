#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=101000,mod=1e9+7,inv=7e8+5;
int n,ans;
int bsum[maxn],mi[maxn],fsum[maxn];
char s[maxn];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	mi[0]=1;
	for(register int i=1;i<=n;++i)
		mi[i]=mi[i-1]*10ll%mod;
	for(register int i=n;i;--i)
		fsum[i]=(fsum[i+1]+(s[i]-'0')*1ll*mi[n-i])%mod;
	int tnt=0,tfrt=0;
	for(register int i=2;i<=n;++i){
		ans=(ans+1ll*fsum[i]*(i-1)%mod)%mod;
		ans=(ans+1ll*tnt*mi[n-i+1])%mod;
		tfrt=(10ll*tfrt+s[i-1]-'0')%mod;
		tnt=(tnt+tfrt)%mod;
	}
	printf("%d\n",(ans+tnt)%mod);
	return 0;
}