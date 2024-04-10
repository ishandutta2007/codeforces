#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
const int mod = 998244353;
inline int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
inline int sub(int a,int b){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b){return 1ll*a*b%mod;}
inline int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
/* math */
int a[N],n,buc[N];
int fac[N],ifac[N];
inline void init(int n=2e6){
	fac[0]=ifac[0]=1;for(int i=1;i<=n;i++)fac[i]=mul(fac[i-1],i);
	ifac[n]=qpow(fac[n],mod-2);for(int i=n-1;i;i--)ifac[i]=mul(ifac[i+1],i+1);
}
inline int binom(int a,int b){
	if(a==b)return 1;
	if(a<b)return 0;
	return mul(fac[a],mul(ifac[b],ifac[a-b]));
}

int main()
{
	init();
	cin >> n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]++,buc[a[i]]++;
	sort(a+1,a+n+1);
	int End=n+1000000;
	for(int i=n;i<=End;i++)buc[i]+=buc[i-n];
	for(int i=1;i<=End;i++)buc[i]+=buc[i-1];
	for(int i=1;i<=n;i++)if(a[i]<i){
		End=i-1;break;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(End-i<0)break;
		int S = End-i;
		int s2 = S-buc[S];
		ans=add(ans,binom(s2+n-1,n-1));
	}
	cout << ans << endl;
}