#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int a[110][110];

int main () {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	vector <int> ans; ans.resize(10000);
	for (int i = 0; i < n - 1; i++) {
		vector <pii> tmp;
		int sum = 0;
		for (int j = 0; j < m; j++) {
			if (a[j][i] <= a[j][n - 1]) tmp.push_back(mp(-a[j][i] + a[j][n - 1], j));
			sum += a[j][i] - a[j][n - 1];
		}
		sort(tmp.begin(), tmp.end()), reverse(tmp.begin(), tmp.end());
		vector <int> res;
		int now = 0;
		while (now < tmp.size() && sum < 0) {
			res.push_back(tmp[now].se);
			sum += tmp[now].fi, now++;
		}
		sort(res.begin(), res.end());
		if (sum >= 0) {
			if (ans.size() > res.size()) ans = res;
		}
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i] + 1);
	}
	printf("\n");
	return 0;
}
/*
5 3
6 3 4 2 8
3 7 5 6 7
5 2 4 7 9

*/