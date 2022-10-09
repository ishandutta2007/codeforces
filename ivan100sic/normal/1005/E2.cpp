#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int o[200005];
int z[200005];
int a[200005];
int b[200005];
int c[200005];
int ac[200005];

struct tacka {
	int x, y;

	bool operator< (const tacka& other) const {
		return x < other.x;
	}
};

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

fenwick<int, 1888888> drvo;

ll tacke_solver(vector<tacka> v) {
	sort(v.begin(), v.end());

	vector<tacka> pending;
	int lastx = -123123123;

	ll sol = 0;

	for (tacka p : v) {

		// cerr << p.x << ' ' << p.y << '\n';

		if (p.x != lastx) {
			// dodaj;
			for (tacka q : pending)
				drvo.add(q.y + 888888, 1);
			pending.clear();
		}
		sol += drvo.sum(p.y + 888888);

		lastx = p.x;
		pending.push_back(p);
	}

	return sol;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		if (x < m)
			o[i] = -1;
		else if (x > m)
			o[i] = +1;
		else
			o[i] = 0;
	}

	for (int i=1; i<=n; i++) {
		a[i] = a[i-1];
		b[i] = b[i-1];
		c[i] = c[i-1];

		if (o[i] == -1)
			a[i]++;
		if (o[i] == 0)
			b[i]++;
		if (o[i] == +1)
			c[i]++;
	}

	for (int i=1; i<=n; i++)
		ac[i] = a[i] - c[i];

	vector<tacka> v;
	for (int i=0; i<=n; i++)
		v.push_back({b[i] - ac[i], b[i] + ac[i]});
	
	cout << tacke_solver(v);
}