#pragma GCC target("avx2")
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;

#define G(x) ll x; cin>>x;
#define F(i, l, r) for (ll i=l; i<(r); ++i)
#define all(a) begin(a), end(a)
#define K first
#define V second

#define N 100100
ll prime[N];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	for(ll i = 2; i < N; i++) if(!prime[i]){
		prime[i] = i;
		for(ll j = i*i; j < N; j += i) if(!prime[j]) prime[j] = i;
	}
	G(n)
	cout << 1 + (n > 2) << "\n";
	F(i, 2, n+2){
		cout << 1 + (prime[i] != i) << " ";
	}
	cout << "\n";
}