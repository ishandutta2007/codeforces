#include <bits/stdc++.h>

using namespace std;

const int N = 20;

map<long long, int> v[N][N];

int n, m;
int half;
long long k;
long long a[N][N];
long long ans;

void calclf(int x, int y, long long val, int cnt) {
	val ^= a[x][y];
	if (cnt == half) {
		++v[x][y][val];
		return;
	}
	if (x + 1 < n)
		calclf(x + 1, y, val, cnt + 1);
	if (y + 1 < m)
		calclf(x, y + 1, val, cnt + 1);
}

void calcrg(int x, int y, long long val, int cnt) {
	if (cnt == n + m - 2 - half) {
		if (v[x][y].count(k ^ val))
			ans += v[x][y][k ^ val];
		return;
	}
	if (x > 0)
		calcrg(x - 1, y, val ^ a[x][y], cnt + 1);
	if (y > 0)
		calcrg(x, y - 1, val ^ a[x][y], cnt + 1);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> m >> k;
	half = (n + m - 2) / 2;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	
	calclf(0, 0, 0, 0);
	calcrg(n - 1, m - 1, 0, 0);
	
	cout << ans << endl;
	
	return 0;
}