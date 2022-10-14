#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;

#define F(i, l, r) for(ll i = l; i < (r); i++)
#define G(x) ll x; cin >> x;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	G(n)
	set<string> shit;
	F(i,0,n) {
		string s; cin >> s;
		reverse(s.begin(), s.end());
		string t;
		for (ll i=0; i<s.size(); ++i) {
			if (s[i]=='u') {
				t+='o';
				t+='o';
			} else if (s[i]=='h') {
				t+='h';
				i++;
				while (i<s.size() && s[i]=='k') ++i;
				--i;
			} else t+=s[i];
		}
		shit.insert(t);	
	}
	cout << shit.size() << endl;
}