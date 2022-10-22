#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, cnt;
ll arr[202020], ans[202020];
pll tree[804040];
ll lazy[804040];

pll cmp(pll a, pll b) {
	if (a.va != b.va) return min(a, b);
	return max(a, b);
}
pll init(int lo, int hi, int idx) {
	if (lo==hi) {
		return tree[idx] = pll(arr[lo], lo);
	}
	return tree[idx] = cmp(init(lo, lo+hi>>1, 2*idx), init(1+(lo+hi>>1), hi, 2*idx+1));
}
void lpush(int lo, int hi, int idx) {
	if (lazy[idx] == 0) return;
	tree[idx].va = tree[idx].va + lazy[idx];
	if (lo==hi) {
		lazy[idx] = 0; return;
	}

	lazy[2*idx] += lazy[idx];
	lazy[2*idx+1] += lazy[idx];
	lazy[idx] = 0;
	return;
}
pll update(int a, int b, ll x, int lo, int hi, int idx) {
	lpush(lo, hi, idx);
	if (b<lo || a>hi) return tree[idx];
	if (a<=lo && hi<=b) {
		lazy[idx] += x;
		lpush(lo, hi, idx);
		return tree[idx];
	}

	return tree[idx] = cmp(update(a, b, x, lo, lo+hi>>1, 2*idx), update(a, b, x, 1+(lo+hi>>1), hi, 2*idx+1));
}
pll query(int a, int b, int lo, int hi, int idx) {
	lpush(lo, hi, idx);
	if (b<lo || a>hi) return pll(9e17, 0);
	if (a<=lo && hi<=b) return tree[idx];

	return cmp(query(a, b, lo, lo+hi>>1, 2*idx), query(a, b, 1+(lo+hi>>1), hi, 2*idx+1));
}

int main() {
	cin >> n;
	for (int i=0; i<n; i++) cin >> arr[i];

	init(0, n-1, 1);

	for (int i=0; i<n; i++) {
		pll tmp = query(0, n-1, 0, n-1, 1);

		ans[tmp.vb] = ++cnt;
		update(tmp.vb+1, n-1, -cnt, 0, n-1, 1);
		update(tmp.vb, tmp.vb, 1LL<<40, 0, n-1, 1);
	}

	for (int i=0; i<n; i++)
		cout << ans[i] << ' ';

}