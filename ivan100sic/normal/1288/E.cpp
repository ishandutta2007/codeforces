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

	T get(int pos) {
		T ret = T();
		while (pos > 0) {
			ret += a[pos];
			pos -= pos & -pos;
		}
		return ret;
	}
};

fenwick<int, 600005> drvo;

int n, m;
int lo[300005], hi[300005], p[300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		p[i] = i+m;
		lo[i] = hi[i] = i;
		drvo.add(i+m, 1);
	}
	int b = m+1;
	for (int i=0; i<m; i++) {
		int x;
		cin >> x;
		lo[x] = min(lo[x], drvo.get(p[x]));
		hi[x] = max(hi[x], drvo.get(p[x]));
		drvo.add(p[x], -1);
		b--;
		p[x] = b;
		drvo.add(p[x], 1);
		lo[x] = min(lo[x], drvo.get(p[x]));
		hi[x] = max(hi[x], drvo.get(p[x]));
	}

	for (int i=1; i<=n; i++) {
		lo[i] = min(lo[i], drvo.get(p[i]));
		hi[i] = max(hi[i], drvo.get(p[i]));
	}

	for (int i=1; i<=n; i++)
		cout << lo[i] << ' ' << hi[i] << '\n';
}