#include<cstdio>
#include<tr1/unordered_map>
using namespace std;
typedef long long ll;
int n,m,q,l,r,a[110000];
tr1::unordered_map<ll,ll> mp;
inline ll MOD(ll a,ll p){
	return a>=p?a%p+p:a;
}
ll phi(ll n){
	if (mp.count(n)) return mp[n];
	ll x=n;
	for (ll i=2;i*i<=n;i++)
		if (n%i==0){
			x=x*(i-1)/i;
			while (n%i==0) n/=i;
		}
	if (n>1) x=x*(n-1)/n;
	mp[n]=x;
	return x;
}
ll qpow(ll x,ll a,ll p){
	ll res=1;
	while (a){
		if (a&1) res=MOD(res*x,p);
		x=MOD(x*x,p); a>>=1;
	}
	return res;
}
int solve(ll l,ll r,ll m){
	if (l==r||m==1) return MOD(a[r],m);
	return qpow(a[l],solve(l+1,r,phi(m)),m);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&q);
	while (q--){
		scanf("%d%d",&l,&r);
		printf("%d\n",solve(l,r,m)%m);
	}
	return 0;
}