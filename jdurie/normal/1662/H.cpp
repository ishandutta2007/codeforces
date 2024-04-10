#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define all(a) begin(a), end(a)
#define K first
#define V second

set<ll> s;

void ge(ll a, ll b){
	ll g = __gcd(a, b);
	for(ll i = 1; i * i <= g; i++){
		if(g % i == 0){
			s.insert(i);
			s.insert(g/i);
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	G(t)
	while(t--){
		G(w) G(l)
		s.clear();
		ge(w-2, l);
		ge(w-1, l-1);
		ge(w, l-2);
		s.insert(2);
		cout << s.size() << " ";
		for(ll i : s) cout << i << " ";
		cout << endl;
	}
}