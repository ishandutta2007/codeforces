#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <complex>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int used;
vector<pair<int, int>> sol;

/*
	I couldn't solve this myself so I read the editorial
	Embarrasing
*/

void resi(vector<int> v) {
	if (v.size() == 0) {
		used++;
		return;
	}
	if (v.size() == 1) {
		int l = used + 1;
		int r = used + v[0] + 1;
		for (int i = l; i <= r; i++) {
			for (int j = l; j < i; j++) {
				sol.push_back({ i, j });
			}
		}
		used += v[0] + 1;
		return;
	}

	vector<int> w(v.size() - 2);
	for (int i = 0; i < (int)v.size() - 2; i++) {
		w[i] = v[i + 1] - v[0];
	}
	resi(w);
	used += v[v.size() - 1] - v[v.size() - 2];
	int l = used + 1;
	int r = used + v[0];
	for (int i = l; i <= r; i++) {
		for (int j = 1; j < i; j++) {
			sol.push_back({ i, j });
		}
	}
	used += v[0];
}

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int& x : v) {
		cin >> x;
	}
	resi(v);
	cout << sol.size() << '\n';
	for (auto p : sol) {
		cout << p.first << ' ' << p.second << '\n';
	}

}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}