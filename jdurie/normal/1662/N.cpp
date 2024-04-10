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
#define N 1502

ll posr[N * N], posc[N * N], rct[N], cct[N];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	G(n)
	F(i, 0, n) F(j, 0, n) {
		G(x) posr[x] = i; posc[x] = j;
	}
	ll ans = 0;
	for(ll i = n * n; i; --i) {
		ans += rct[posr[i]] * cct[posc[i]];
		rct[posr[i]]++; cct[posc[i]]++;
	}
	cout << n * n * (n - 1) * (n - 1) / 2 - ans << '\n';
}