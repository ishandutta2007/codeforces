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
#define K first
#define V second
#define N 400010

map<char, ll> m;
char mids[N];
string nds[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	G(n)
	string s; cin >> s;
	for(char c : s) m[c]++;
	ll oCt = 0;
	for(auto a : m) if(a.V & 1) oCt++;
	F(x, 1, n + 1) {
		ll l = n / x;
		if(n % x || (oCt && !(l & 1)) || (x < oCt)) continue;
		if(l & 1) {
			ll idx = 0;
			for(auto& a : m) if(a.V & 1) {mids[idx++] = a.K; a.V--;}
			for(auto& a : m) while(a.V && idx < x) {mids[idx++] = a.K; mids[idx++] = a.K; a.V -= 2;}
		}
		ll idx = 0;
		for(auto& a : m) F(i, 0, a.V / 2) {
			nds[idx] += a.K;
			if(nds[idx].size() == n / x / 2) idx++;
		}
		cout << x << '\n';
		F(i, 0, x) {
			cout << nds[i];
			if(l & 1) cout << mids[i];
			reverse(nds[i].begin(), nds[i].end());
			cout << nds[i] << ' ';
		}
		cout << '\n';
		exit(0);
	}
}