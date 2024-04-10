#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"

map<ll,ll> len;

inline ll g(ll n){
	if(n<=1) return 1;
	return 2*g(n/2) + 1;
}
ll f(ll n, ll l, ll r){
	if(r < l) return 0;
	if(n==1){
		if(l == 1 && r == 1) return 1;
		return 0;
	}
	if(n==0){
		return 0;
	}
	ll ans = 0;
	ll leftl = g(n/2);
	// cerr<<n<<" "<<l<<" "<<r<<" "<<leftl<<endl;
	if(leftl + 1 >=l && leftl + 1<= r) ans += (n%2);
	ans += f(n/2,max(l,1LL), min(r,leftl)) + f(n/2, max(l,leftl + 2) - leftl - 1, r - leftl - 1);
	return ans;
}
int main(){
	ll n,l,r;
	cin>>n>>l>>r;
	cout<<f(n,l,r)<<endl;
}