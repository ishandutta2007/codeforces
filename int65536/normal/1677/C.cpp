#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void process() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
	}
	vector<int> b(n);
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		--b[i];
	}
	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		p[a[i]] = b[i];
	}
	vector<int> c(n);
	int num_off_cycles = 0;
	for (int i = 0; i < n; ++i) {
		if (!c[i]) {
			int l = 0;
			for (int j = i; !c[j]; j = p[j]) {
				++l;
				c[j] = 1;
			}
			if (l % 2 == 1) {
				++num_off_cycles;
			}
		}
	}
	assert((n - num_off_cycles) % 2 == 0);
	int m = (n - num_off_cycles) / 2;
	ll ret = 0;
	for (int i = 0; i < m; ++i) {
		ret += (n - 1 - i);
		ret -= i;
	}
	ret *= 2;
	cout << ret << endl;
}

int main()
{
#ifdef _MSC_VER
	freopen("c.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int ncases;
	cin >> ncases;
	for (int case_id = 0; case_id < ncases; ++case_id) {
		process();
	}
	return 0;
}