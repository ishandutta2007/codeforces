#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T, int size>
struct fenwick {
	T a[size];

	/* precondition: pos > 0 */
	void add(int pos, const T& val) {
		while (pos < size) {
			a[pos] += val;
			pos += pos & -pos;
		}
	}

	T sum(int pos) {
		T ret = T();
		while (pos > 0) {
			ret += a[pos];
			pos -= pos & -pos;
		}
		return ret;
	}
};

fenwick<int, 100005> drvo, marks;
int seen[100005];

int n;
int a[100005];
basic_string<int> e[100005];

int q, ql[100005], qr[100005], ans[100005];
basic_string<int> qe[100005];

struct job {
	int x, y;
};

basic_string<job> jobs[100005];

void add(int l1, int r1, int l2, int r2) {
	jobs[l2] += {l1, 1};
	jobs[l2] += {r1+1, -1};
	jobs[r2+1] += {l1, -1};
	jobs[r2+1] += {r1+1, 1};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		e[a[i]] += i;
	}
	for (const auto& v : e) {
		if (!v.size())
			continue;
		int j = 0;

		for (int i=0; i<(int)v.size(); i++) {
			if (i && v[i] - v[i-1] != v[j+1] - v[j])
				j = i-1;

			int l2 = v[i];
			int r2 = i+1 == (int)v.size() ? n : v[i+1] - 1;

			int l1 = j == 0 ? 1 : v[j-1] + 1;
			int r1 = v[i];

			add(l1, r1, l2, r2);
		}
	}
	cin >> q;
	for (int i=0; i<q; i++) {
		cin >> ql[i] >> qr[i];
		qe[qr[i]] += i;
	}
	for (int i=1; i<=n; i++) {
		// drvo
		if (seen[a[i]])
			drvo.add(seen[a[i]], -1);
		seen[a[i]] = i;
		drvo.add(i, 1);
		// marks
		for (auto [x, y] : jobs[i])
			marks.add(x, y);

		for (int j : qe[i]) {
			ans[j] = drvo.sum(i) - drvo.sum(ql[j]-1);
			ans[j] += !marks.sum(ql[j]);
		}
	}

	for (int i=0; i<q; i++)
		cout << ans[i] << '\n';
}