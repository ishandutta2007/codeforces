#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[500005];
int b[500005];

struct fenwick {
	int n;
	vector<int> f;

	fenwick(int n) : n(n), f(n, 0) {}

	void dodaj(int x, int y) {
		while (x < n) {
			f[x] += y;
			x += x & -x;
		}
	}

	int rd(int x) {
		return x < n ? f[x] : 132123123;
	}

	int trazi(int y) { // trazi internal
		int x = 0;
		for (int i=524288; i>=1; i>>=1) {
			if (rd(x+i) <= y) {
				y -= rd(x+i);
				x += i;
			}
		}
		return x;
	}

	int kec(int y) { // nadji y-tog (1-based) keca
		int t = trazi(y-1) + 1;
		if (t >= n)
			return -1;
		return t;
	}
};

int a2[500005];

int proveri() {
	b[n+1] = n+1;
	basic_string<int> st = {n+1};
	for (int i=n; i>=1; i--) {
		while (b[i] > b[st.back()])
			st.pop_back();
		a2[i] = st.back();
		st += i;
	}
	for (int i=1; i<=n; i++)
		if (a2[i] != a[i])
			return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=1; i<=n; i++) {
			cin >> a[i];
			if (a[i] == -1)
				a[i] = i+1;
		}
		
		fenwick f(n+1);
		for (int i=1; i<=n; i++)
			f.dodaj(i, 1);

		int ok = 1;

		for (int i=1; i<=n && ok; i++) {
			int k = f.kec(a[i] - i);
			if (k == -1) {
				ok = 0;
			} else {
				b[i] = k;
				f.dodaj(k, -1);
			}
		}

		ok *= proveri();

		if (!ok) {
			cout << "-1\n";
		} else {
			for (int i=1; i<=n; i++)
				cout << b[i] << " \n"[i == n];
		}
	}
}