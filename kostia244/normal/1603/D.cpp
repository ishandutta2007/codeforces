#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int N = 1e5 + 15,C=18;
ll phi[N],dp[C][N];
vector<int> divs[N];
struct node {
	ll sm, mn;
	node(ll x = 0) : sm(x), mn(x) {}
	friend node operator+(const node &b, node a) {
		a.mn = min(a.mn, a.sm+b.mn);
		a.sm += b.sm;
		return a;
	}
};
struct seg {
	int n;
	vector<node> tree;
	seg(int N) : n(N), tree(2*n) {}
	void upd(int p, ll v) {
		v = tree[p+n].sm+v;
		for(tree[p+=n] = node(v); p/=2;)
			tree[p] = tree[2*p]+tree[2*p+1];
	}
	node get(int l, int r) {
		node x, y;
		for(l+=n,r+=n; l < r; l/=2,r/=2) {
			if(l&1) x = x + tree[l++];
			if(r&1) y = tree[--r] + y;
		}
		return (x+y);
	}
	ll get(ll l) {
		return get(0, l).mn + get(l, n).sm;
	}
};
int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	//multitest([&](){});
	for(int i = 1; i < N; i++) phi[i] = i;
	for(int i = 2; i < N; i++) if(phi[i] == i) {
		for(int j = i; j < N; j+=i)
			phi[j] -= phi[j]/i;
	}
	for(int i = 1; i < N; i++)
		for(int j = i; j < N; j += i)
			divs[j].push_back(i);
	memset(dp, 0x4f, sizeof dp);
	dp[0][0] = 0;
	for(int k = 0; k+1 < C; k++) {
		seg st(N);
		st.upd(N-1, dp[k][N-1]);
		for(int i = N-1; i--;) 
			st.upd(i, dp[k][i] - dp[k][i+1]);
		for(int r = 1; r < N; r++) {
			for(auto d : divs[r])
				st.upd(d-1, phi[r/d]);
			dp[k+1][r] = st.get(r);
		}
	}
	int t, n, k;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		cout << (k>=C?n:dp[k][n]) << '\n';
	}
}