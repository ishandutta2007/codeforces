#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 100005;
int n, a[N], pr[N], sf[N], st[N], top, cnt[N], ans[N];

int main() {
	scanf("%d", &n);
	int Max = 0;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		if (!top || a[i] > st[top]) st[pr[i] = ++top] = a[i];
		else st[pr[i] = lower_bound(st + 1, st + 1 + top, a[i]) - st] = a[i];
		Max = max(Max, pr[i]);
	}
	top = 0;
	for (int i = n; i >= 1; i--) {
		a[i] = -a[i];
		if (!top || a[i] > st[top]) st[sf[i] = ++top] = a[i];
		else st[sf[i] = lower_bound(st + 1, st + 1 + top, a[i]) - st] = a[i];
	}
	for (int i = 1; i <= n; i++) {
		ans[i] = 2;
		if (pr[i] + sf[i] - 1 == Max) cnt[pr[i]]++;
		else ans[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (pr[i] + sf[i] - 1 == Max && cnt[pr[i]] == 1) ans[i] = 3;
		printf("%d", ans[i]);
	} printf("\n");
	return 0;
}