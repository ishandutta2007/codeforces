#pragma GCC target("avx2")
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;

#define G(x) ll x; cin>>x;
#define GS(s) string s; cin >> s;
#define F(i, l, r) for (ll i=l i<(r); ++i)
#define all(a) begin(a), end(a)
#define K first
#define V second

int main() {
	cin.tie(0)->sync_with_stdio(0);
	GS(s1) GS(s2)
		cout << s1 << ' ' << s2 << '\n';
	G(n) while(n--) {
		GS(t) GS(u)
		if(s1 == t) s1 = u; else s2 = u;
		cout << s1 << ' ' << s2 << '\n';
	}
}