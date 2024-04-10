#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int l[1000005], r[1000005], p[1000005], n, k;
int a[1000005];

int L[1000005], R[1000005];

void dfs(int x) {
	L[x] = R[x] = x;
	if (l[x]) {
		dfs(l[x]);
		L[x] = L[l[x]];
	}
	if (r[x]) {
		dfs(r[x]);
		R[x] = R[r[x]];
	}
}

const int MOD = 1'000'000'007;

// this function is piecewise linear, just eval it at sufficiently
// many points
inline int eval_point(int i, int l, int r, int k) {
	int a = max(i-k+1, l+1);
	int b = min(i, r-k);
	return max(0, b-a+1);
}

inline int reduce(int klo, int khi, int kstep, int x) {
	x -= klo;
	x -= x % kstep;
	x += klo;
	return x;
}

inline ll eval_linear(int x1, int x2, int step, int y1, int y2) {
	return ((x2 - x1) / step + 1ll) * (y1 + y2) / 2;
}

ll eval_range(int i, int l, int r, int klo, int khi, int kstep) {
	vector<int> pts, pts2;

	pts = {i-l, r-i, r-l-1, klo, khi};

	for (int x : pts) {
		int y = reduce(klo, khi, kstep, x);
		if (klo <= y && y <= khi)
			pts2.push_back(y);
		if (klo <= y + kstep && y + kstep <= khi)
			pts2.push_back(y + kstep);
		if (klo <= y - kstep && y - kstep <= khi)
			pts2.push_back(y - kstep);
	}

	pts2.push_back(klo);
	pts2.push_back(khi);

	sort(pts2.begin(), pts2.end());
	pts2.resize(unique(pts2.begin(), pts2.end()) - pts2.begin());

	int m = pts2.size();
	
	ll sum = 0;

	if (klo == khi) {
		return eval_point(i, l, r, klo) % MOD;
	}

	for (int ii=0; ii<m-1; ii++) {
		int x1 = pts2[ii];
		int x2 = pts2[ii+1];

		ll y1 = eval_point(i, l, r, x1) % MOD;
		ll y2 = eval_point(i, l, r, x2) % MOD;

		// cerr << i << ' ' << l << ' ' << r << ' ' << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 << '\n';

		sum += eval_linear(x1, x2, kstep, y1, y2);
		if (ii < m-2)
			sum -= y2;

		sum %= MOD;
	}

	if (sum < 0)
		sum += MOD;

	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	a[0] = 1123123123;
	r[0] = 1;

	for (int i=2; i<=n; i++) {
		p[i] = i-1;
		r[i-1] = i;
		l[i] = r[i] = 0;
		while (a[i] > a[p[i]]) {
			// rotiraj
			int ppi = p[p[i]];
			int pi = p[i];
			int li = l[i];
			r[ppi] = i;
			p[pi] = i;
			r[pi] = li;
			p[i] = ppi;
			l[i] = pi;
		}
	}

	ll sum = 0;

	dfs(r[0]);
	for (int i=1; i<=n; i++) {
		L[i]--;
		R[i]++;
		// cerr << i << ' ' << L[i] << ' ' << R[i] << '\n';
	}

	int klo = k;
	int khi = klo;
	while (khi + k - 1 <= n)
		khi += k - 1;

	for (int i=1; i<=n; i++)
		sum += eval_range(i, L[i], R[i], klo, khi, k-1) * a[i] % MOD;

	cout << sum % MOD << '\n';
}