#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <iomanip>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> f(n);
	for (int i = 0; i < n; i++) {
		cin >> f[i];
		f[i]--;
	}
	vector<int>b = f;
	sort(f.begin(), f.end());
	int m = 1;
	vector<int> h(m);
	vector<int> g(n, -1);
	h[0] = f[0];
	g[f[0]] = 0;
	for (int i = 1; i < n; i++)
		if (f[i] != f[i - 1]) {
			h.push_back(f[i]);
			g[f[i]] = m;
			m++;
		}
	for (int i = 0; i < m; i++) {
		if (h[i] != b[h[i]]) {
			cout << -1;
			return 0;
		}
	}
	cout << m << '\n';
	for (int i = 0; i < n; i++) {
		int a = g[b[i]];
		cout << a + 1 << ' ';
	}
	cout << '\n';
	for (int i : h)
		cout << i + 1 << ' ';
	return 0;
}