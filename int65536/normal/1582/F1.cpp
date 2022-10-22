#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

const int M = 512;

void solve(const vector<int>& a) {
	vector<int> f(M, M);
	f[0] = -1;
	for (int val : a) {
		vector<int> g = f;
		for (int i = 0; i < M; ++i) {
			if (g[i] < val) {
				f[i ^ val] = min(f[i ^ val], val);
			}
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