#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
inline ll add(ll a,ll b){a+=b;return a>=mod?a-mod:a;}
inline ll sub(ll a,ll b){a-=b;return a<0?a+mod:a;}
inline ll mul(ll a,ll b){return 1ll*a*b%mod;}
inline ll qpow(ll a,ll b){a%=mod;ll ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
/* math */
ll n,m,l,r;

vector<ll> s;

vector<ll> Mul(vector<ll> a,vector<ll> b){
	vector<ll> c(2,0);
	for(int i=0;i<2;i++)for(int j=0;j<2;j++){
		c[i^j]=add(c[i^j],mul(a[i],b[j]));
	}return c;
}

int main()
{
	cin >> n >> m >> l >> r;
	if(n*m%2){
		cout << qpow(r-l+1ll,n*m) << endl;
		return 0;
	}
	--l;
	vector<ll> a(2,0);
	a[0]+=r/2,a[1]+=(r+1)/2;
	a[0]-=l/2,a[1]-=(l+1)/2;
	a[0]%=mod,a[1]%=mod;
	ll d=n*m;
	vector<ll> res(2,0);
	res[0]=1;
	for(;d;d>>=1,a=Mul(a,a))if(d&1){
		res=Mul(res,a);
	}
	cout << (res[0]%mod+mod)%mod << endl;
}