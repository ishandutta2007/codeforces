#pragma GCC target ("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < r; i++)
#define N 1010

string names[N];
set<ll> del;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	G(n) G(m)
	F(i, 0, n) cin >> names[i];
	while(m--) { G(x) del.insert(x - 1); }
	string s = names[*del.begin()];
	ll k = s.size();
	for(ll x : del) {
		if(names[x].size() != k) { cout << "No\n"; exit(0); }
		F(i, 0,	k) if(s[i] != names[x][i]) s[i] = '?';
	}
	F(i, 0, n) if(!del.count(i)) {
		if(names[i].size() != k) continue;
		bool ok = true;
		F(y, 0, k) if(s[y] != names[i][y] && s[y] != '?') ok = false;
		if(ok) { cout << "No\n"; exit(0); }
	}
	cout << "Yes\n" << s << '\n';
}