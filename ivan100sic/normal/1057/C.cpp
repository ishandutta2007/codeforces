#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, s, k;
int a[55];
string c;

int dp[55][2605]; // gde sam, koliko sam pojeo
int r[55];

bool cmp(int i, int j) {
	return a[i] < a[j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s >> k;
	s--;
	for (int i=0; i<n; i++)
		cin >> a[i];
	cin >> c;

	iota(r, r+n, 0);
	sort(r, r+n, cmp);

	memset(dp, 63, sizeof(dp));
	int sol = 123123123;

	for (int i=0; i<n; i++) {
		int x = r[i];
		dp[i][a[x]] = abs(x - s);
		for (int j=0; j<i; j++) {
			int y = r[j];
			if (a[x] == a[y])
				continue;
			if (c[x] == c[y])
				continue;
			for (int t=a[x]; t<=2500; t++)
				dp[i][t] = min(dp[i][t], dp[j][t-a[x]] + abs(x-y));
		}
		for (int t=k; t<=2500; t++)
			sol = min(sol, dp[i][t]);
	}
	if (sol == 123123123)
		sol = -1;
	cout << sol << '\n';
}