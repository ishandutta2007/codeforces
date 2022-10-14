#pragma GCC target("avx2")
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define F(i, l, r) for(ll i = l; i < (r); i++)
#define G(x) ll x; cin >> x;
#define K first
#define V second

typedef long long int ll;
typedef pair<ll, ll> pl;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s; cin >> s;
	ll n = s.length();
	ll su = 0;
	set<char> se = {'A', 'a', '.', '0'};
	F(i, 0, n){
		char c = s[i];
		ll p = *prev(se.upper_bound(c));
		su = su + ((('@' < c) & ('[' > c)) - (('`' < c) & ('{' > c))) * (c - p + 1);
	}
	cout << su << "\n";
}