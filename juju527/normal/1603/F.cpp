#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxk=1e7+5,iv2=499122177,mod=998244353;
int fc[maxk],iv[maxk];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){return x>=mod?x-mod:x;}
inline int sub(int x){return x<0?x+mod:x;}
inline int power(int x,int b){
	int res=1;
	while(b){
		if(b&1)res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		b>>=1;
	}
	return res;
}
int main(){
	int T;
	T=read();
	while(T--){
		int n,k,x,lim;
		n=read();k=read();x=read();
		lim=min(n,k);
		if(x==0){
			if(n>k)puts("0");
			else{
				int res=1,tmp=1,pwk=power(2,k);
				for(int i=1;i<=n;i++)res=1ll*res*sub(pwk-tmp)%mod,tmp=add(tmp+tmp);
				printf("%d\n",res);
			}
		}
		else{
			n++;lim=min(n,k);
			int tmp=2;
			fc[0]=1;for(int i=1;i<=lim;i++)fc[i]=1ll*fc[i-1]*sub(tmp-1)%mod,tmp=add(tmp+tmp);
			tmp=1ll*tmp*iv2%mod;
			iv[lim]=power(fc[lim],mod-2);for(int i=lim-1;i>=1;i--)iv[i]=1ll*iv[i+1]*sub(tmp-1)%mod,tmp=1ll*tmp*iv2%mod;
			for(int i=lim;i>=1;i--)iv[i]=1ll*iv[i]*fc[i-1]%mod;
			tmp=2;
			int pwk=power(2,k);
			int prod=sub(pwk-1),pw=1,pw2=power(2,n),res=0;
			tmp=1;
			for(int r=1;r<=lim;r++){
				res=add(res+1ll*prod*pw%mod);
				tmp=add(tmp+tmp);
				prod=1ll*prod*sub(pwk-tmp)%mod;
				pw2=1ll*pw2*iv2%mod;
				pw=1ll*pw*sub(pw2-1)%mod*iv[r]%mod;
			}
			res=1ll*res*power(sub(pwk-1),mod-2)%mod;
			printf("%d\n",res);
		}
	}
    return 0;
}