#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
int A[300003], B[300003], ans[300003];

struct SEG {
	int tree[1200001];

	int init(int lo, int hi, int idx) {
		if (lo==hi) return tree[idx] = A[lo];
		return tree[idx] = max(init(lo, lo+hi>>1, 2*idx), init(1+(lo+hi>>1), hi, 2*idx+1));
	}
	int query(int a, int b, int lo, int hi, int idx) {
		if (b<lo || a>hi) return 0;
		if (a<=lo && hi<=b) return tree[idx];
		return max(query(a, b, lo, lo+hi>>1, 2*idx), query(a, b, 1+(lo+hi>>1), hi, 2*idx+1));
	}
} seg;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N;
	for (int i=1; i<=N; i++) {
		cin >> A[i]; A[N+i] = A[2*N+i] = A[i];
	}

	seg.init(1, 3*N, 1);
	for (int i=1; i<=3*N; i++) B[i] = 2e9;
	for (int i=3*N; i>=1; i--) {
		int lo=1, hi=i;
		while (lo<hi) {
			int mid = lo+hi+1>>1;
			if (seg.query(mid, i, 1, 3*N, 1) > 2*A[i]) lo = mid;
			else hi = mid-1;
		}
		if (seg.query(lo, i, 1, 3*N, 1) > 2*A[i])
			B[lo] = min(B[lo], i);
	}

	int p = 2e9;
	for (int i=3*N; i>0; i--) {
		if (B[i] != 2e9) p = min(p, B[i]);
		if (p == -1) continue;

		ans[i] = p-i;
	}

	for (int i=1; i<=N; i++)
		cout << (ans[i]>3*N ? -1 : ans[i]) << ' ';
}