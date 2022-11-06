#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> h(n);
	for (int i = 0; i < n; ++i) scanf("%d",&h[i]);
	vector<int> minh(n), maxh(n);
	maxh[0] = h[0];
	for (int i = 1; i < n; ++i) maxh[i] = max(maxh[i - 1], h[i]);
	minh[n - 1] = h[n - 1];
	for (int i = n - 2; i >= 0; --i) minh[i] = min(minh[i + 1], h[i]);
	int ans = 1;
	for (int i = 0; i < n - 1; ++i)
		if (maxh[i] <= minh[i + 1]) ++ans;
	printf("%d\n", ans);
}