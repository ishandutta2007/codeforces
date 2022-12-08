#include<bits/stdc++.h>
using namespace std;
const int N = 5010;
typedef long long ll;
const int mod = 998244353;
inline int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
inline int sub(int a,int b){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b){return 1ll*a*b%mod;}
inline int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
/* math */
int g[N][N];
int fac[N], ifac[N];
void init(int n=5000){
	fac[0]=ifac[0]=1;for(int i=1;i<=n;i++)fac[i]=mul(fac[i-1],i);
	ifac[n]=qpow(fac[n],mod-2);for(int i=n-1;i;i--)ifac[i]=mul(ifac[i+1],i+1);
}
int ans[N],n;
int main()
{
	init();
	cin >> n;
	g[0][0]=1;for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			g[i][j] = add(mul(g[i-1][j],j), mul(i-(j-1),g[i-1][j-1]));
			ans[j]=add(ans[j], mul(g[i][j], mul(fac[n],ifac[i])));
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	puts("");
}