// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
const long long mod=998244353;
long long i,j,k;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
long long n,ans,thi;
int main(){
	n=read();
	ans=1; for (i=1;i<=n;i++) ans=(ans*i)%mod;
	thi=1;
	for (i=n;i>=1;i--){
		ans=ans+thi*(i-1)%mod*(n-i)%mod;
		ans=ans%mod; 
		thi=(thi*i)%mod;
	}
	printf("%I64d\n",ans);
	return 0;
}