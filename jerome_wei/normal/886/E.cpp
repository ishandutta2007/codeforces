#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
inline int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
inline int sub(int a,int b){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b){return 1ll*a*b%mod;}
inline int qpow(int a,int b){
	int ret=1;for(;b;b>>=1,a=1ll*a*a%mod)if(b&1)ret=1ll*ret*a%mod;
	return ret;
}
const int N = 2e6+5;
int n,k;
int fac[N],ifac[N];
inline int calc(int l,int r){
	// cout << l << " " << r << ">" << mul(ifac[l-1],fac[r-1]) << endl;
	return 1ll*fac[r-1]*ifac[l-1]%mod;
}

int f[N];

int main()
{
	cin >> n >> k;
	fac[0]=ifac[0]=1;for(int i=1;i<=n;i++)fac[i] = 1ll*fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n],mod-2);for(int i=n-1;i;i--)ifac[i] = 1ll*ifac[i+1]*(i+1)%mod;
	f[0]=1;
	for(int i=1;i<=n;i++){
		f[i]=1ll*f[i-1]*i%mod;
		// cout << i << ":" << f[i] << endl;
		if(i-k-1>=0)f[i] = sub(f[i], mul(f[i-k-1],calc(i-k,i)));
		// f[i]=(1ll*f[i]+mod-1ll*f[i-k-1]*calc(i-k,i))%mod;
		// cout << i << ":" << f[i] << endl;
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		int temp=mul(f[i],calc(i+1,n));
		ans = add(ans, temp);
	}
	cout << sub(fac[n],ans) << endl;
	// cout << f[n-1] << endl;
}