#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> cnt;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	int m = 0;
	for (auto p : cnt) m = max(m, p.second);
	cnt.clear();
	for (int i = 0; i < n; ++i) {
		cnt[a[i]]++;
		if (cnt[a[i]] == m) {
			cout << a[i] << '\n';
			return 0;
		}
	}
	return 1;
}