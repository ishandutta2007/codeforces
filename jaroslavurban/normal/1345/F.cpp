#ifndef __PROGTEST__
#include <bits/stdc++.h>
using namespace std;
#endif // __PROGTEST__

typedef long long ll;
typedef long double ld;
typedef string str;

typedef pair<ll,ll> pl;
typedef vector<ll> vl;
typedef vector<str> vs;
typedef vector<pl> vpl;

#define pb(x) push_back(x)
#define ff first
#define ss second
#define ft front
#define bk back
#define lb lower_bound
#define ub upper_bound
#define eb emplace_back
#define vec vector
#define ins insert
#define res resize
#define gen generate
#define ass assert
#define all(x) (x).begin(), (x).end()
#define sz(w) (ll) w.size()
#define fr(x, y) for(ll x=0;x<y;++x)
#define inf 9223372036854775807
#define mod 998244353
// #define endl '\n'
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// ll pos = partition_point(all(vec), pred) - vec.begin(); bool pred(ll a){return a<3};
// print number in binary -> cout << bitset<20>(n);
ll nxt() {ll x; cin >> x; return x;}

ll n,k;
vl a,b;

ll getsm(ll dmax){ //(-inf,dmax+(1|2)>
	ll sm=0;
	fr(i,n){
		ll l=1,r=a[i]+1;
		while(l<r){
			ll m=(l+r)/2;
			ll d=a[i]-3*m*m+3*m-1;
			if(dmax>d)r=m;
			else l=m+1;
		}
		l=min(l,a[i]);
		b[i]=l;
		sm+=l;
	}
	return sm;
}


void solve(ll test_number){
	n=nxt(),k=nxt();
	a.res(n);b.res(n);
	gen(all(a),nxt);
	if(k<=n){
		fr(i,n)cout<<(k-->0?1:0)<<" ";
		cout<<endl;
		return;
	}
	// getsm(0);
	// fr(i,n)cerr<<b[i]<<" ";
	// cerr<<endl;
	ll l=-4e18,r=4e18,sm;
	while(l<r){ // sm l will be <=k
		ll m=l+(r-l)/2;
		sm=getsm(m);
		if(sm>=k)l=m+1;
		else if(sm<k)r=m;
	}
	sm=getsm(l);
	vl res(b);
	getsm(l-(1+(l==1)));
	fr(i,n)if(sm<k&&res[i]+1==b[i]){
		++sm;
		++res[i];
	}
	fr(i,n)cout<<res[i]<<" ";
	cout<<endl;
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