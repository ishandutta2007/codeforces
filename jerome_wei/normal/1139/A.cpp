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
int n;char s[N];
int main()
{
	cin >>n ;
	scanf("%s",s+1);
	ll ans=0;
	for(int i=1;i<=n;i++){
		if((s[i]-'0')%2==0)ans += i;
	}
	cout<<ans<<endl;
}