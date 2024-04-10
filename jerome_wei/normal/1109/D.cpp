#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
int sub(int a,int b){a-=b;return a<0?a+mod:a;}
int mul(int a,int b){return (ll)a*b%mod;}
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
/* math */
const int N=1e6+5;
int fac[N],ifac[N];
void init(int n){
	fac[0]=ifac[0]=1;for(int i=1;i<=n;i++)fac[i]=mul(fac[i-1],i);
	ifac[n]=qpow(fac[n],mod-2);for(int i=n-1;i;i--)ifac[i]=mul(ifac[i+1],i+1);
}
int comb(int x,int y){
	if(y>x)return 0;
	return mul(fac[x],mul(ifac[y],ifac[x-y]));
}
int n,m;

int main()
{
	scanf("%d%d",&n,&m);
	init(1000000);
	int ans=0;
	for(int i=2;i<=n;i++){
		int tmp=mul(fac[i-2],comb(n-2,i-2));
		int tmp_edge=comb(m-1,i-2);
		if(i==n){
			ans=add(ans,mul(tmp,tmp_edge));
		}else{
			int restnode=n-i+1;
			int restQ=n;//(n-i)*1  + 1*i
			
			int type=qpow(restQ,restnode-2);
			type=mul(type,i);
			int all=mul(type,qpow(m,restnode-1));
			ans=add(ans,mul(mul(tmp,tmp_edge),all));
		}
	}
	printf("%d\n",ans);
}