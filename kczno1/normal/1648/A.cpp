#include <bits/stdc++.h>
using namespace std;

typedef long long s64;

const int N = 1e5 + 5;
vector<int> a[N][2];
s64 calc(vector<int> a) {
	sort(a.begin(), a.end());
	s64 ans = 0, sum = 0;
	int c = 0;
	for (auto x: a) {
		ans += (s64)x * c - sum;
		sum += x;
		++c;
	}
	return ans;
}

int main() {
#ifdef kcz
	freopen("1.in", "r", stdin); //freopen("1.out","w",stdout);
#endif
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int c;
			scanf("%d", &c);
			a[c][0].push_back(i);
			a[c][1].push_back(j);
		}
	}
	s64 ans = 0;
	for (int i = 1; i < N; ++i) ans += calc(a[i][0]) + calc(a[i][1]);
	cout << ans << endl;
}