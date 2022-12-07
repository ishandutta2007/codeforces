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

const int N = 1000005;
int n, q;
ll a[N * 2], b;
int pr[N * 2], cnt[N * 2];

int gao() {
	int j = 0;
	for (int i = 0; i <= 2 * n; i++) pr[i] = i;
	for (int i = n + 1; i <= 2 * n; i++) {
		while (a[i] - a[j] > b) j++;
		cnt[i] = cnt[j] + 1;
		pr[i] = pr[j];
		if (i - pr[i] >= n) return cnt[i];
	}
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), a[i + n] = a[i];
	for (int i = 1; i <= 2 * n; i++) a[i] += a[i - 1];
	while (q--) {
		scanf("%lld", &b);
		printf("%d\n", gao());
	}
	return 0;
}