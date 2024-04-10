#ifndef __PROGTEST__
#include <bits/stdc++.h>
using namespace std;
#endif // __PROGTEST__

typedef long long ll;
typedef long double ld;
#define pb(x) push_back(x)
#define ff first
#define ss second
#define vec vector
#define all(x) (x).begin(), (x).end()
#define inf 9223372036854775807
#define mod 998244353
// #define endl '\n'
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// use merge(all(vec1), all(vec2), vec3.begin()) to merge 2 vectors, use vec3.resize(vec1.size() + vec2.size()) first
// ll pos = partition_point(all(vec), pred) - vec.begin(); bool pred(ll a){return a<3};
// print number in binary -> cout << bitset<20>(n);
ll nxt() {ll x; cin >> x; return x;}


void solve(ll test_number){
	ll n=nxt();
	vec<ll> arr(n);
	//cumsum,first ind that isn't counted
	vec<pair<ll,ll>> cum(n+1);
	vec<ll> nend(n, -2);
	generate(all(arr),nxt);
	cum[0]={0,0};
	for(ll i=0;i<n;++i)
		cum[i+1]={cum[i].ff+arr[i],i+1};
	sort(all(cum));
	pair<ll,ll> prev=cum[0];
	vec<pair<ll,ll>> prs;
	for(ll i=1;i<n+1;prev=cum[i],++i)
		if(prev.ff==cum[i].ff)
			prs.push_back({cum[i].ss,prev.ss});
	sort(all(prs));
	for(auto p:prs){
		// cout<<p.ss<<" "<<p.ff<<endl;
		while(p.ss>=0&&nend[p.ss]==-2){
			nend[p.ss]=p.ff-2;
			--p.ss;
		}
	}
	ll res=0;
	ll mx=-inf;
	for(ll i=0;i<n;++i){
		// cout<<nend[i]<<endl;
		if(nend[i]==-2)nend[i]=n-1;
		if(nend[i]<mx)continue;
		res+=(nend[i]-i+1)*(nend[i]-i+2)/2;
		if(mx!=-inf)res-=(mx-i+1)*(mx-i+2)/2;
		mx=nend[i];
	}
	cout<<res<<endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	ll t = 1;
	// cin >> t;
	for (ll i = 0; i < t; ++i){ 
		solve(i);
	}
}