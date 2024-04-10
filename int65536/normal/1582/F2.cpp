#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

const int M = 8192;

void solve(const vector<int>& a) {
	int n = a.size();
	vector<int> next_eq(n);
	vector<int> next_val(M + 1, n);
	for (int i = n - 1; i >= 0; --i) {
		next_eq[i] = next_val[a[i]];
		next_val[a[i]] = i;
	}
	vector<int> f(M, M);
	vector<vector<int>> events(n);
	auto up = [&](int at, int val) {
		int prev = f[at];
		if (val >= prev) {
			return;
		}
		for (int i = val + 1; i <= prev; ++i) {
			if (next_val[i] < n) {
				events[next_val[i]].push_back(at);
			}
		}
		f[at] = val;
	};
	up(0, 0);
	for (int i = 0; i < n; ++i) {
		int val = a[i];
		next_val[val] = next_eq[i];
		for (int at : events[i]) {
			assert(f[at] < val);
			up(at ^ val, val);
		}
	}
	int count = 0;
	for (int val = 0; val < M; ++val) {
		if (f[val] < M) {
			++count;
		}
	}
	printf("%d\n", count);
	for (int val = 0; val < M; ++val) {
		if (f[val] < M) {
			printf("%d ", val);
		}
	}
	printf("\n");
}
int main()
{
#ifdef _MSC_VER
	freopen("f.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	while (cin >> n) {
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		solve(a);
	}
	return 0;
}