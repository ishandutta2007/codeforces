#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 200005;
const llint INF = 2000000000000000007LL;

llint n, t;
llint a[MAXN], x[MAXN], p[MAXN], mn[MAXN], mx[MAXN];

int main () {
	cin >> n >> t;
	for (int i=1; i<=n; i++) {
		scanf("%I64d", &a[i]);
		a[i] += t;
		mx[i] = INF;
	}
	for (int i=1; i<=n; i++) {
		scanf("%I64d", &x[i]);
		if (x[i] < i) {
			cout << "No";
			return 0;
		}
		p[i]++;
		p[x[i]]--;
		if (x[i] != n) mx[x[i]] = min(mx[x[i]], a[x[i] + 1] - 1);
	}
	bool ok = 1;
	for (int i=1; i<=n; i++) {
		p[i] += p[i-1];
		if (p[i]) mn[i] = a[i+1]; else mn[i] = a[i];
		if (mn[i] == mn[i-1]) mn[i]++;
		if (mn[i] > mx[i]) ok = 0;
	}
	if (ok == 0) {
		cout << "No";
		return 0;
	}
	cout << "Yes" << endl;
	for (int i=1; i<=n; i++) {
		printf("%I64d ", mn[i]);
	}
	return 0;
}