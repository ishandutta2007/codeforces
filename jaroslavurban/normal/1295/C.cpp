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
	string s,t;
	cin>>s>>t;
	const ll n=s.size();
	const ll m=t.size();
	vec<vec<ll>> nextc(26,vec<ll>(n));
	for(ll j=0;j<26;++j){
		ll last=-1;
		for(ll i=n-1;i>=0;--i){
			if(s[i]==j+'a')last=i;
			nextc[j][i]=last;
		}
	}
	ll res=0;
	ll p=0;
	ll p2=0;
	while(p<m){
		// cout<<p<<" "<<p2<<endl;
		if(!p2&&nextc[t[p]-'a'][p2]==-1){
			cout<<-1<<endl;
			return;
		}
		while(p2<n&&p<m&&nextc[t[p]-'a'][p2]!=-1){
			p2=nextc[t[p]-'a'][p2]+1;
			++p;
		}
		p2=0;
		++res;
	}
	cout<<res<<endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	ll t = 1;
	cin >> t;
	for (ll i = 0; i < t; ++i){ 
		solve(i);
	}
}