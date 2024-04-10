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

fenwick<int, 100005> drvo; 
bool lucky[10000];
int a[100005], n, q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=1; i<5; i++) {
		for (int m=0; m<(1<<i); m++) {
			int z = 0;
			for (int j=0; j<i; j++)
				if (m & (1 << j))
					z = 10*z + 4;
				else
					z = 10*z + 7;
			lucky[z] = true;
		}
	}

	cin >> n >> q;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		if (lucky[a[i]])
			drvo.add(i, 1);
	}

	while (q--) {
		string s;
		cin >> s;
		if (s == "add") {
			int l, r, x;
			cin >> l >> r >> x;
			for (int i=l; i<=r; i++) {
				if (lucky[a[i]])
					drvo.add(i, -1);
				a[i] += x;
				if (lucky[a[i]])
					drvo.add(i, 1);
			}
		} else {
			int l, r;
			cin >> l >> r;
			cout << drvo.sum(r) - drvo.sum(l-1) << '\n';
		}
	}
}