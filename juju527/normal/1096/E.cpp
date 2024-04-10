#include<bits/stdc++.h>
typedef long long ll;
#define fi first
#define se second
using namespace std;
const int maxn=2e7+5,mod=998244353;
int fc[maxn],ifc[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){return (x>=mod)?x-mod:x;}
inline int sub(int x){return (x<0)?x+mod:x;}
inline int power(int x,int b){
	int res=1;
	while(b){
		if(b&1)res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		b>>=1;
	}
	return res;
}
inline int binom(int n,int m){
	if(n<m||m<0)return 0;
	return 1ll*fc[n]*ifc[m]%mod*ifc[n-m]%mod;
}
inline int F(int n,int m){
	if(n<0)return 0;
	if(n==0&&m==0)return 1;
	return binom(n+m-1,m-1);
}
int main(){
    int n,m,k;
	n=read();m=read();k=read();
	fc[0]=1;for(int i=1;i<=m+n;i++)fc[i]=1ll*fc[i-1]*i%mod;
    ifc[m+n]=power(fc[m+n],mod-2);for(int i=m+n-1;i>=0;i--)ifc[i]=1ll*ifc[i+1]*(i+1)%mod;
	int inv=power(F(m,n),mod-2),pr=0;
	for(int i=0;m>=i*k&&i<=n;i++){
		int val=1ll*binom(n,i)*F(m-i*k,n)%mod;
		if(i&1)pr=sub(pr-val);else pr=add(pr+val);
	}
	pr=sub(1-1ll*pr*inv%mod);
	int res=1ll*pr*power(1ll*n*F(m-k,n)%mod*inv%mod,mod-2)%mod;
	printf("%d\n",res);
	return 0;
}