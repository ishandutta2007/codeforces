#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
vector<pair<int, int>> a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		a.emplace_back(x, i);
	}
	sort(a.begin(), a.end(), greater<pair<int, int>>());
	vector<int> b;
	b.reserve(2*n);
	b.resize(n, -1);
	vector<pair<int*, int*>> sol;
	for (int i=0; i<n; i++) {
		int x = 2*a[i].second, y = x+1;
		b[i] = x;
		int j = i + a[i].first - 1;
		if (j == (int)b.size() - 1) {
			b.push_back(y);			
		} else {
			sol.emplace_back(&b[j], new int(y));
		}
	}

	for (int i=0; i<(int)b.size()-1; i++)
		sol.emplace_back(&b[i], &b[i+1]);
	for (auto [x, y] : sol)
		cout << *x+1 << ' ' << *y+1 << '\n';
}