#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll INF = 9e18;
struct SEG {
	ll tree[1000010], lazy[1000010];

	void lpush(int lo, int hi, int idx) {
		if (lazy[idx] == 0) return;
		tree[idx] += lazy[idx];
		if (lo != hi) {
			lazy[2*idx] += lazy[idx];
			lazy[2*idx+1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
	ll update(int a, int b, ll x, int lo, int hi, int idx) {
		lpush(lo, hi, idx);
		if (b<lo || a>hi) return tree[idx];
		if (a<=lo && hi<=b) {
			lazy[idx] += x; lpush(lo, hi, idx);
			return tree[idx];
		}
		return tree[idx] = min(update(a, b, x, lo, lo+hi>>1, 2*idx), update(a, b, x, 1+(lo+hi>>1), hi, 2*idx+1));
	}
	ll query(int a, int b, int lo, int hi, int idx) {
		lpush(lo, hi, idx);
		if (b<lo || a>hi) return INF;
		if (a<=lo && hi<=b) return tree[idx];
		return min(query(a, b, lo, lo+hi>>1, 2*idx), query(a, b, 1+(lo+hi>>1), hi, 2*idx+1));
	}
} seg;

int N;
int A[200020], pos[200020], C[200020];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i=0; i<N; i++) cin >> A[i], pos[A[i]] = i;
	for (int i=0; i<N; i++) cin >> C[i];

	for (int i=1; i<=N; i++) {
		seg.update(pos[i]+1, N-1, C[pos[i]], 1, N-1, 1);
	}

	ll ans = seg.query(1, N-1, 1, N-1, 1);
	for (int i=1; i<=N; i++) {
		seg.update(pos[i]+1, N-1, -C[pos[i]], 1, N-1, 1);
		seg.update(1, pos[i], C[pos[i]], 1, N-1, 1);
		ans = min(ans, seg.query(1, N-1, 1, N-1, 1));
	}

	cout << ans;
}