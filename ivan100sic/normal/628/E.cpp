// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class T = int, class F = plus<T>>
struct fenwick {
	vector<T> a;
	T e;
	F f;

	fenwick(int n, T e = T(), F f = F()) : a(n, e), e(e), f(f) {}

	void add(int p, const T& v) {
		for (p++; p <= (int)a.size(); p += p & -p)
			a[p-1] = f(a[p-1], v);
	}

	T operator() (int p) const {
		T v = e;
		for (; p; p -= p & -p)
			v = f(v, a[p-1]);
		return v;
	}
};

int n, m;
string s[3005];

int l[3005][3005];
int r[3005][3005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> s[i];

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			l[i][j] = 1 + (j > 0 ? l[i][j-1] : 0);
			if (s[i][j] != 'z')
				l[i][j] = 0;
		}
	}

	for (int i=0; i<n; i++) {
		for (int j=m-1; j>=0; j--) {
			r[i][j] = 1 + r[i][j+1];
			if (s[i][j] != 'z')
				r[i][j] = 0;
		}
	}

	ll sol = 0;

	for (int ss=n+m; ss>=0; ss--) {
		fenwick f(m+1, 0);
		vector<vector<int>> eraseme(m);
		int streak = 0;
		for (int j=0; j<m; j++) {
			int i = ss-j;
			if (i < 0 || i >= n)
				continue;
			for (int x : eraseme[j])
				f.add(x, -1);
			if (s[i][j] == 'z') {
				streak++;
				f.add(j, 1);
				int w = min(streak, l[i][j]);
				int d = f(j+1) - f(j-w+1);
				sol += d;
				int jj = j + r[i][j];
				if (jj < m)
					eraseme[jj].push_back(j);
			} else {
				streak = 0;
			}
		}
	}

	cout << sol << '\n';
}