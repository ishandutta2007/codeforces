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

	void clear() {
		memset(a, 0, sizeof(a));
	}
};

fenwick<int, 10005> drvo;

struct duz {
	int x1, y1, x2, y2;
};

int n, hn, vn;
duz ha[5005], va[5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1 += 5001;
		y1 += 5001;
		x2 += 5001;
		y2 += 5001;
		if (x1 > x2)
			swap(x1, x2);
		if (y1 > y2)
			swap(y1, y2);

		if (y1 == y2)
			ha[hn++] = {x1, y1, x2, y2};
		else
			va[vn++] = {x1, y1, x2, y2};
	}

	sort(va, va+vn, [&](auto u, auto v) {
		return u.x1 < v.x1;
	});

	ll sol = 0;

	for (int i=0; i<vn; i++) {
		int x = va[i].x1;
		int y1 = va[i].y1;
		int y2 = va[i].y2;
		vector<vector<int>> e(10005);
		for (int j=0; j<hn; j++) {
			if (ha[j].x1 <= x && x <= ha[j].x2 &&
				y1 <= ha[j].y1 && ha[j].y1 <= y2)
			{
				e[ha[j].x2].push_back(ha[j].y1);
			}
		}

		int ptr = 10003;
		for (int j=vn-1; j>i; j--) {
			while (ptr > va[j].x1) {
				ptr--;
				for (int y : e[ptr]) {
					drvo.add(y, 1);
				}
			}

			int c = drvo.sum(va[j].y2) - drvo.sum(va[j].y1-1);

			// cerr << i << ' ' << j << ' ' << c << "(";
			// cerr << va[i].x1 << ' ' << va[j].x1 << ")\n";

			sol += c*(c-1);
		}

		drvo.clear();
	}

	cout << sol/2 << '\n';
}