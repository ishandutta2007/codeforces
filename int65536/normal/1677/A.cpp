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
	ll ret = 0;
	for (int i = 0; i < n; ++i) {
		vector<int> b(n);
		for (int j = 0; j < i; ++j) {
			++b[a[j]];
		}
		vector<int> c(n);
		for (int i = 1; i < n; ++i) {
			c[i] = c[i - 1] + b[i - 1];
		}
		ll tot = 0;
		for (int j = i + 1; j < n; ++j) {
			if (a[i] > a[j]) {
				ret += tot;
			}
			tot += c[a[j]];
		}
	}
	cout << ret << endl;
}

int main()
{
#ifdef _MSC_VER
	freopen("a.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int ncases;
	cin >> ncases;
	for (int case_id = 0; case_id < ncases; ++case_id) {
		process();
	}
	return 0;
}