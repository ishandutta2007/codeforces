#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int T, N, M;
int A[200020];
pii B[200020];
vector<pii> v;

struct SEG {
	int tree[800080];

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

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i=1; i<=N; i++) cin >> A[i];
		seg.init(1, N, 1);

		cin >> M;
		for (int i=0; i<M; i++) cin >> B[i].va >> B[i].vb;
		sort(B, B+M);

		bool flag = true;
		for (int i=1; i<=N; i++) {
			if (A[i] > B[M-1].va) flag = false;
		}
		if (!flag) {
			cout << "-1\n";
			continue;
		}

		v.clear();
		for (int i=0; i<M; i++) {
			while (!v.empty() && v.back().vb <= B[i].vb) v.pop_back();
			v.push_back(B[i]);
		}

		int ans = 0, p=1;
		while (p<=N) {
			int lo=p, hi=N;
			while (lo<hi) {
				int mid = lo+hi+1>>1;
				int mx = seg.query(p, mid, 1, N, 1);
				int idx = lower_bound(v.begin(), v.end(), pii(mx,0)) - v.begin();

				if (v[idx].vb >= mid-p+1) lo=mid;
				else hi=mid-1;
			}
			++ans; p=lo+1;
		}

		cout << ans << '\n';
	}

}