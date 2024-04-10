#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[100005];
vector<int> seen[100005];

struct implicit_fw {
	vector<int> a;

	void add(int x) {
		a.push_back(x);
	}

	void prepare() {
		sort(a.begin(), a.end());
	}

	int count(int x) {
		return upper_bound(a.begin(), a.end(), x) - a.begin();
	}
};

struct drvo {

	implicit_fw a[131072 + 1];

	void add(int l, int r) {
		for (int x=l; x<=131072; x+=x&-x) {
			a[x].add(r);
		}
	}

	int c2(int l, int r) {
		int z = 0;
		for (int x=l; x; x-=x&-x) {
			z += a[x].count(r);
		}
		return z;
	}

	void prepare() {
		for (int i=1; i<=131072; i++) {
			a[i].prepare();
		}
	}

	int count(int l, int r) {
		return c2(131072, r) - c2(l-1, r);
	}

} ds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k;
	cin >> n >> k;

	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	for (int i=1; i<=n; i++) {
		seen[a[i]].push_back(i);
		if ((int)seen[a[i]].size() > k) {
			int l = seen[a[i]][seen[a[i]].size()-k-1];
			int r = seen[a[i]][seen[a[i]].size()-1];

			ds.add(l, r);
		}
	}

	ds.prepare();

	int q, last_ans = 0;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;

		int l = (x + last_ans) % n + 1;
		int r = (y + last_ans) % n + 1;

		if (l > r) {
			swap(l, r);
		}

		// cerr << "q " << l << ' ' << r << '\n';

		last_ans = (r-l+1) - ds.count(l, r);

		cout << last_ans << '\n';
	}
}