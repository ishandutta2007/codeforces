#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
inline int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
inline int sub(int a,int b){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b){return 1ll*a*b%mod;}
inline int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
/* math */
const int N = 3e5+5;
int f[N], g[N];

int n,a[N],m;

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		m+=a[i];
	}
	int t = mul(m,n-1);
	f[0]=n-1;for(int i=1;i<=max(n,m);i++)f[i]=mul(add(mul(mul(f[i-1],n-1), i), t),qpow(m-i,mod-2));
	for(int i=m-1;~i;i--)f[i]=add(f[i],f[i+1]);
	int ans=0;
	for(int i=1;i<=n;i++)ans=add(ans,f[a[i]]);
	ans=sub(ans, mul(f[0], n-1));
	printf("%d\n",mul(ans, qpow(n,mod-2)));
}