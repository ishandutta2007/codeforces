#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
inline int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
inline int sub(int a,int b){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline int qpow(ll a,ll b){a%=mod;int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
/*math*/
const int N=1e6+5;
int a[N],n;

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	ll ans=0;int cur=0;
	cur = 0x3f3f3f3f;
	for(int i=n;i;i--){
		ll t= min(cur-1,a[i]);
		if(t<0) t=0;
		cur = t;
		ans += t;
	}
	cout<<ans<<endl;
}