#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
const int N = 18;
ll n, dp1[1<<N][N], a[N][N];
vector<vector<ll>> f;
template<int inv = 0, int sup = 0>
void sub(vector<ll> &a) {
	for(int b = 0; 1<<b < a.size(); b++)
		for(int i = 0; i < a.size(); i++)
			if(((sup ? ~i : i)>>b)&1) {
				if(!inv)
					a[i] += a[i^(1<<b)];
				else
					a[i] -= a[i^(1<<b)];
			}
}
ll get(vector<ll> &a) {//a[full]
	ll res = 0;
	for(int i = 0; i < 1<<n; i++)
		res += __builtin_popcount(i)%2 ? a[i] : -a[i];
	if((n+1)%2) res *= -1;
	return res;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			char c;cin>>c;
			a[i][j] = c-'0';
		}
	}
	for(int i = 0; i < n; i++)
		dp1[1<<i][i] = 1;
	f.resize(n+1, vector<ll>(1<<n));
	for(int msk = 0; msk < 1<<n; msk++) {
		for(int i = 0; i < n; i++) if((msk>>i)&1) {
			for(int j = 0; j < n; j++) if((~msk>>j)%2 && a[i][j] == 1) {
				dp1[msk|1<<j][j] += dp1[msk][i];
			}
		f[__builtin_popcount(msk)][msk] += dp1[msk][i];
		}	
	}
	for(int i = 0; i <= n; i++)
		sub<0>(f[i]);
	vector<ll> res(1<<(n-1));
	vector<int> vis(1<<(n-1));
	auto solve = [&](vector<int> P) {
		sort(all(P));
		vector<ll> g(1<<n, 1);
		for(auto x : P) {
			for(int i = 0; i < 1<<n; i++)
				g[i] = g[i]*1ll*f[x][i];
		}
		ll r = get(g);
		do {
			ll msk = 0, cur = 1;
			for(auto i : P) {
				while(i-->1) msk += cur, cur *= 2;
				cur *= 2;
			}
			vis[msk] = 1;
			res[msk] = r;
		} while(next_permutation(all(P)));
	};
	for(int i = 0; i < 1<<(n-1); i++) {
		if(vis[i]) continue;
		vector<int> P;
		int cur = 1;
		for(int j = 0; j < (n-1); j++) {
			if((~i>>j)&1)
				P.push_back(cur), cur = 0;
			cur++;
		}
		P.push_back(cur);
		solve(P);
	}
	sub<1, 1>(res);
	for(auto i : res) cout << i << " "; cout << '\n';
}