#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef long long ll;
int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
int sub(int a,int b){a-=b;return a<0?a+mod:a;}
int mul(int a,int b){return (ll)a*b%mod;}
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
/*math*/
const int N=1e6+5;
int n;
int fac[N],ifac[N];
inline void init(){
	fac[0]=ifac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=mul(fac[i-1],i);
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i;i--)ifac[i]=mul(ifac[i+1],i+1);
}
int comb(int a,int b){
	if(b>a)return 0;
	return mul(fac[a],mul(ifac[b],ifac[a-b]));
}


int main()
{
	scanf("%d",&n);
	init();
	int ans=0;
	for(int len=1;len<n;len++){
		// not FAC
		int tot=sub(fac[len],1);
		int num=mul(comb(n,len),fac[n-len]);
		ans=add(ans,mul(tot,num));
	}
	ans=add(ans,fac[n]);
	cout<<ans<<endl;
}