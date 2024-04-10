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
#define N 200010

namespace sgtree {
	typedef pair<pl, pl> T;
	T id = {{LLONG_MAX, 0}, {LLONG_MIN, 0}}, t[2 * N];

	T f(T a, T b) {
		pl p = a.K.K < b.K.K ? a.K : b.K;
		pl q = a.V.K > b.V.K ? a.V : b.V;
		return {p, q};
	}

	void modify(ll p, T v) {
		for(t[p += N] = v; p /= 2;) t[p] = f(t[2 * p], t[2 * p + 1]);
	}

	T query(ll l, ll r) {
		T resl = id, resr = id;
		for(l += N, r += N; l < r; l /= 2, r /= 2) {
			if(l & 1) resl = f(resl, t[l++]);
			if(r & 1) resr = f(t[--r], resr);
		}
		return f(resl, resr);
	}
}

ll p[N];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	G(tc) while(tc--) {
		G(n) G(a) G(b) a--; b--;
		F(i, 0, n) cin >> p[i], sgtree::modify(i, {{i - p[i], i}, {p[i] + i, i}});
		vector<pl> bfs = {{a, 0ll}};
		sgtree::modify(a, sgtree::id);
		F(i, 0, bfs.size()) {
			ll v = bfs[i].K;
			if(v == b) { cout << bfs[i].V << '\n'; break; }
			while(1) {
				pl q = sgtree::query(max(0ll, v - p[v]), v).V;
				if(q.K < v) break;
				bfs.emplace_back(q.V, bfs[i].V + 1);
				sgtree::modify(q.V, sgtree::id);
			}
			while(1) {
				pl q = sgtree::query(v + 1, min(n, v + p[v] + 1)).K;
				if(q.K > v) break;
				bfs.emplace_back(q.V, bfs[i].V + 1);
				sgtree::modify(q.V, sgtree::id);
			}
		}
	}
}