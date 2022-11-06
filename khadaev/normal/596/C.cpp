#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
void fail() {
	printf("NO\n");
	exit(0);
}
const int N = 200010;
int main() {
	int n, x, y, len[N], w;
	vector<int> ans[N];
	scanf("%d", &n);
	map<int, int> x_now;
	for (int i = 0; i <= N; ++i) x_now[i] = -1;
	for (int i = 0; i <= N; ++i) x_now[-i] = i - 1;
	//cerr << x_now[0] << ' ' << x_now[1] << '\n';
	for (int i = 0; i < N; ++i) len[i] = -1;
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &x, &y);
		len[x] = max(len[x], y);
	}
	//for (int i = 0; i < n; ++i) cerr << len[i] << '\n';
	for (int i = 0; len[i] >= 0; ++i) ans[i].resize(len[i] + 1);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &w);
		//cerr << i << ' ' << w << ' ' << x_now[w] << '\n';
		int x_new = x_now[w] + 1;
		int y_new = x_new + w;
		if (y_new <= len[x_new]) {
			ans[x_new][y_new] = i;
		} else {
			fail();
		}
		//cerr << x_new << ' ' << y_new << ' ' << ans[x_new][y_new] << '\n';
		x_now[w]++;
	}
	for (int i = 0; len[i] >= 0; ++i)
		for (int j = 0; j <= len[i]; ++j) {
			if (j + 1 < ans[i].size() && ans[i][j] > ans[i][j + 1]) fail();
			if (j < ans[i + 1].size() && ans[i][j] > ans[i + 1][j])
				fail();
		}
	printf("YES\n");
	int x_ans[100000], y_ans[100000];
	for (int i = 0; len[i] >= 0; ++i)
		for (int j = 0; j <= len[i]; ++j) {
			x_ans[ans[i][j]] = i;
			y_ans[ans[i][j]] = j;
		}
	for (int i = 0; i < n; ++i) {
		printf("%d %d\n", x_ans[i], y_ans[i]);
	}
}