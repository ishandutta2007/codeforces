#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[105], n, t;
basic_string<int> b;

const int W = 100;

const int I = -1012012012;

struct mat {
	vector<vector<int>> a;

	mat() : a(W, vector<int>(W, I)) {
		for (int i=0; i<W; i++)
			a[i][i] = 0;
	}

	mat(double) : a(W, vector<int>(W, I)) {}

	mat(int x) : a(W, vector<int>(W, I)) {
		for (int i=0; i<W; i++)
			a[i][i] = 0;
		for (int i=0; i<=x; i++)
			a[i][x] = 1;
	}

	void sredi() {
		for (int i=0; i<W; i++)
			for (int j=0; j<W; j++)
				if (a[i][j] < 0)
					a[i][j] = I;
	}

	mat operator* (mat b) {
		mat rez(0.0);
		for (int j=0; j<W; j++)
			for (int k=0; k<W; k++)
				if (b.a[j][k] != I)
					for (int i=0; i<W; i++)
						rez.a[i][k] = max(rez.a[i][k], a[i][j] + b.a[j][k]);
		rez.sredi();
		return rez;
	}

	void print() {
		for (int i=0; i<W; i++) {
			for (int j=0; j<W; j++)
				if (a[i][j] == I)
					cerr << ". ";
				else
					cerr << a[i][j] << ' ';
			cerr << '\n';
		}
		cerr << '\n';
	}
};

mat pw(mat u, int n) {
	if (n == 0) {
		return mat();
	} else if (n == 1) {
		return u;
	}
	auto t = pw(u, n >> 1);
	t = t * t;
	if (n & 1)
		t = t * u;
	return t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, t;
	cin >> n >> t;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		b += a[i];
	}
	sort(b.begin(), b.end());
	b.resize(unique(b.begin(), b.end()) - b.begin());
	for (int i=0; i<n; i++)
		a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
	mat w;
	for (int i=0; i<n; i++)
		w = w * mat(a[i]);
	w = pw(w, t);
	int sol = 0;
	for (int i=0; i<W; i++)
		for (int j=0; j<W; j++)
			sol = max(sol, w.a[i][j]);
	cout << sol << '\n';
}