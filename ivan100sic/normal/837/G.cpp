#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <set>
#include <iterator>
using namespace std;

struct func {
	long long a, b, end;

	bool operator< (const func& other) const {
		return end < other.end;
	}

	long long operator() (long long x) const {
		return a*x + b;
	}

	func() {}

	func(long long a, long long b, long long end) : a(a), b(b), end(end) {}
};

typedef pair<vector<func>, vector<func>> pvf;

void calc_second(pvf& tmp) {
	tmp.second = tmp.first;
	for (int i=1; i<tmp.second.size(); i++) {
		tmp.second[i].a += tmp.second[i-1].a;
		tmp.second[i].b += tmp.second[i-1].b;
	}
}

pvf spoji(const pvf& a, const pvf& b) {
	pvf tmp;
	merge(a.first.begin(), a.first.end(),
		b.first.begin(), b.first.end(), back_inserter(tmp.first));	

	calc_second(tmp);

	return tmp;
}

const int MAXN = 131072;

struct tree {
	pvf a[2*MAXN];

	void init() {
		for (int i=MAXN-1; i>=1; i--) {
			a[i] = spoji(a[2*i], a[2*i+1]);
		}
	}

	long long answer(const pvf& b, long long x) {
		func t;
		t.end = x;
		auto it = lower_bound(b.second.begin(), b.second.end(), t);
		// zbir svih od it do kraja
		long long z = (*b.second.rbegin())(x);
		if (it != b.second.begin()) {
			--it;
			z -= (*it)(x);
		}
		return z;
	}

	long long answer(int l, int r, long long x, int node=1, int nl=1, int nr=MAXN) {

		if (r < nl || nr < l) {
			return 0;
		}
		if (l <= nl && nr <= r) {
			return answer(a[node], x);
		}

		int m = (nl + nr) / 2;
		return answer(l, r, x, 2*node, nl, m) + answer(l, r, x, 2*node+1, m+1, nr);
	}
};

tree drvo;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, q;

	cin >> n;
	for (int i=1; i<=n; i++) {
		long long x1, x2, y1, a, b, y2;
		cin >> x1 >> x2 >> y1 >> a >> b >> y2;

		pvf meh;
		meh.first.push_back(func(0, y1, x1));
		meh.first.push_back(func(-a, -b, x1));
		meh.first.push_back(func(a, b, x2));
		meh.first.push_back(func(0, -y2, x2));
		meh.first.push_back(func(0, y2, 2000000000));

		// sort(meh.first.begin(), meh.first.end());
		calc_second(meh);

		drvo.a[i + MAXN - 1] = meh;
	}

	drvo.init();

	cin >> q;
	long long last = 0;

	while (q--) {
		int l, r, x;
		cin >> l >> r >> x;

		x = (x + last) % 1000000000;

		last = drvo.answer(l, r, x);
		cout << last << '\n';
	}

}