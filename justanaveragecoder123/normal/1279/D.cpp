#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll fpow(ll a, ll b) {
	if(b==0) return 1;
	ll fele=fpow(a,b/2);
	ll ans=fele*fele%mod;
	if(b&1) ans=ans*a%mod;
	return ans;
}

ll inv(ll x) {
	return fpow(x,mod-2);
}
struct tort {
	ll a,b;
	tort(ll c, ll d) : a(c),b(d) {}
	
	tort() {
		a=0;
		b=1;
	}
	tort operator+(const tort& masik) const {
		tort res;
		res.a=(a*masik.b+b*masik.a)%mod;
		res.b=(b*masik.b)%mod;
		return res;
	}
	
	tort operator*(const tort& masik) const {
		tort res;
		res.a=(a*masik.a)%mod;
		res.b=(b*masik.b)%mod;
		return res;
	}
	
	ll val() const {
		return a*inv(b)%mod;
	}
};

tort p[1000001];
vector<ll> lst[1000001];
int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;++i) {
		int cnt;
		cin>>cnt;
		for(int j=0;j<cnt;++j) {
			int val;
			cin>>val;
			lst[i].push_back(val);
		}
	}
	
	tort base(1,n);
	for(int i=0;i<n;++i) {
		tort curr(1,lst[i].size());
		for(auto j:lst[i]) {
			p[j]=p[j]+base*curr;
		}
	}
	
	tort ans(0,1);
	for(int i=0;i<n;++i) {
		for(auto j:lst[i]) {
			ans=ans+p[j]*base;
		}
	}
	
	cout<<ans.val()<<"\n";
	return 0;
}