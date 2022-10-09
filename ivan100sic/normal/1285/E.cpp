#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct compressor {
	vector<int*> v;

	void add(int* x) {
		v.push_back(x);
	}

	int run() {
		sort(v.begin(), v.end(), [](int* x, int* y) { return *x < *y; });
		int k = 0, last = -1;
		for (int i=0; i<(int)v.size(); i++) {
			if (i == 0 || *v[i] != last) {
				k++;
			}
			last = *v[i];
			*v[i] = k;
		}
		return k;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pair<int, int>> a(n);
		compressor cr;
		for (auto& [x, y] : a) {
			cin >> x >> y;
			cr.add(&x);
			cr.add(&y);
		}
		cr.run();
		const int m = 6*n+5;
		vector<int> z(m);
		for (auto& [x, y] : a) {
			x = 2*x+1;
			y = 2*y+1;
			z[x]++;
			z[y+1]--;
		}
		for (int i=0; i<m-1; i++)
			z[i+1] += z[i];
		vector<int> f1(m), f2(m);
		for (int i=0; i<m-1; i++) {
			f1[i+1] = f1[i] + (z[i] > 0 && z[i+1] == 0);
			f2[i+1] = f2[i] + (z[i] > 1 && z[i+1] == 1);
		}
		int sol = 0;
		for (auto [x, y] : a) {
			int v = f1[x-1] + (f2[y] - f2[x]) + (f1[m-1] - f1[y+1]);
			v += z[x-1] > 0 && z[x] == 1;
			v += z[y] > 1 && z[y+1] == 0;
			sol = max(sol, v);
		}
		cout << sol << '\n';
	}
}