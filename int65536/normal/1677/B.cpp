#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void process() {
	int n, m;
	cin >> n >> m;
	int l = n * m;
	string str;
	cin >> str;
	vector<int> a(l);
	for (int i = 0; i < l; ++i) {
		a[i] = str[i] - '0';
	}
	vector<int> s(l + 1);
	for (int i = 0; i < l; ++i) {
		s[i + 1] = s[i] + a[i];
	}
	auto count = [&](int l, int r) {
		l = max(0, l);
		++r;
		r = min(r, (int)s.size() - 1);
		if (l >= r) {
			return 0;
		}
		return s[r] - s[l];
	};
	vector<int> r1(l);
	for (int i = 0; i < l; ++i) {
		if (i >= m) {
			r1[i] += r1[i - m];
		}
		if (count(i - m + 1, i)) {
			++r1[i];
		}
	}
	vector<int> r2(l);
	vector<int> b(m);
	int tot = 0;
	for (int i = 0; i < l; ++i) {
		if (a[i] && !b[i % m]) {
			b[i % m] = 1;
			++tot;
		}
		r2[i] = tot;
	}

	for (int i = 0; i < l; ++i) {
		if (i) {
			printf(" ");
		}
		printf("%d", r1[i] + r2[i]);
	}
	printf("\n");
}

int main()
{
#ifdef _MSC_VER
	freopen("b.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int ncases;
	cin >> ncases;
	for (int case_id = 0; case_id < ncases; ++case_id) {
		process();
	}
	return 0;
}