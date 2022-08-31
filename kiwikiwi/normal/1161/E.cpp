#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define maxN 123456

int l[maxN], r[maxN], eq[maxN], eq2[maxN], n, col[maxN];

char s[maxN];

vector<int> query(vector<int> a, vector<int> b) {
	int n = a.size();
	if (n == 0) {
		return vector<int>(0);
	}
	printf("Q %d", n);
	for (int i = 0; i < n; i++)
		printf(" %d %d", a[i], b[i]);
	printf("\n");
	fflush(stdout);
	scanf("%s", s);
	vector<int> ans(n, 0);
	for (int i = 0; i < n; i++)
		ans[i] = s[i] - '0';
	return ans;
}

void solve() {
	scanf("%d", &n);
	vector<int> p1;
	vector<int> p2;
	vector<int> p3;
	for (int i = 1; i + 1 <= n; i += 2) {
		p1.push_back(i);
		p2.push_back(i + 1);
	}
	auto ans = query(p1, p2);
	for (int i = 1; i + 1 <= n; i += 2) {
		eq[i] = ans[(i - 1) / 2];
	}
	p1.clear();
	p2.clear();
	for (int i = 2; i + 1 <= n; i += 2) {
		p1.push_back(i);
		p2.push_back(i + 1);
	}
	ans = query(p1, p2);
	for (int i = 2; i + 1 <= n; i += 2) {
		eq[i] = ans[(i - 2) / 2];
	}
	int m = 0;
	for (int i = 1; i <= n; i++) {
		int j = i;
		while (j <= n - 1 && eq[j] == 1)
			j++;
		++m;
		l[m] = i;
		r[m] = j;
		i = j;
	}
	p1.clear();
	p2.clear();
	for (int i = 1; i + 2 <= m; i++) {
		if (i % 4 == 1 || i % 4 == 2) {
			p1.push_back(l[i]);
			p2.push_back(l[i + 2]);
		}
	}
	ans = query(p1, p2);
	int c = 0;
	for (int i = 1; i + 2 <= m; i++) {
		if (i % 4 == 1 || i % 4 == 2) {
			eq2[i] = ans[c++];
		}
	}
	p1.clear();
	p2.clear();
	for (int i = 1; i + 2 <= m; i++) {
		if (i % 4 == 3 || i % 4 == 0) {
			p1.push_back(l[i]);
			p2.push_back(l[i + 2]);
		}
	}
	ans = query(p1, p2);
	c = 0;
	for (int i = 1; i + 2 <= m; i++) {
		if (i % 4 == 3 || i % 4 == 0) {
			eq2[i] = ans[c++];
		}
	}
	col[1] = 0;
	col[2] = 1;
	for (int i = 3; i <= m; i++) {
		if (eq2[i - 2]) {
			col[i] = col[i - 2];
		} else {
			col[i] = 3 - col[i - 1] - col[i - 2];
		}
	}
	p1.clear();
	p2.clear();
	p3.clear();
	for (int i = 1; i <= m; i++) {
		for (int j = l[i]; j <= r[i]; j++) {
			if (col[i] == 0) p1.push_back(j);
			if (col[i] == 1) p2.push_back(j);
			if (col[i] == 2) p3.push_back(j);
		}
	}
	printf("A %d %d %d\n", (int)p1.size(), (int)p2.size(), (int)p3.size());
	for (auto x : p1) printf("%d ", x); printf("\n");
	for (auto x : p2) printf("%d ", x); printf("\n");
	for (auto x : p3) printf("%d ", x); printf("\n");
	fflush(stdout);
}

int main() {
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		solve();
	}
}