#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int n, q;
int y[200005];

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
		for (int i=0; i<size; i++) {
			a[i] = T();
		}
	}
};

fenwick<int, 200005> drvo;

struct query {
	int xl, yl, xr, yr, id;
	long long sol;
} a[200005];

bool cmp_xl(query a, query b) {
	return a.xl < b.xl;
}

bool cmp_xr(query a, query b) {
	return a.xr < b.xr;
}

long long sols[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=1; i<=n; i++) {
		cin >> y[i];
	}

	for (int i=1; i<=q; i++) {
		cin >> a[i].xl >> a[i].yl >> a[i].xr >> a[i].yr;
		a[i].sol = n * 1ll * (n-1) / 2;
		a[i].id = i;
	}

	{
		sort(a+1, a+q+1, cmp_xl);
		int j = 1;
		for (int i=1; i<=q; i++) {
			while (j < a[i].xl) {
				drvo.add(y[j], 1);
				j++;
			}
			long long num = drvo.sum(a[i].yl - 1);
			a[i].sol += num * (num-1) / 2;

			num = drvo.sum(n) - drvo.sum(a[i].yr);
			a[i].sol += num * (num-1) / 2;
		}
	}

	drvo.clear();

	{
		sort(a+1, a+q+1, cmp_xr);
		int j = n;
		for (int i=q; i>=1; i--) {
			while (j > a[i].xr) {
				drvo.add(y[j], 1);
				j--;
			}
			long long num = drvo.sum(a[i].yl - 1);
			a[i].sol += num * (num-1) / 2;

			num = drvo.sum(n) - drvo.sum(a[i].yr);
			a[i].sol += num * (num-1) / 2;
		}
	}

	for (int i=1; i<=q; i++) {
		a[i].sol -= (a[i].xl - 1) * 1ll * (a[i].xl - 2) / 2;
		a[i].sol -= (a[i].yl - 1) * 1ll * (a[i].yl - 2) / 2;
		a[i].sol -= (n - a[i].xr - 1) * 1ll * (n - a[i].xr) / 2;
		a[i].sol -= (n - a[i].yr - 1) * 1ll * (n - a[i].yr) / 2;

		sols[a[i].id] = a[i].sol;
	}

	for (int i=1; i<=q; i++) {
		cout << sols[i] << '\n';
	}
}