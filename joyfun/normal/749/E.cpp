#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second

#define lowbit(x) (x&(-x))
const int N = 100005;
int n, a[N];
ll bit[N];

ll get(int x) {
	ll ans = 0;
	while (x) {
		ans += bit[x];
		x -= lowbit(x);
	}
	return ans;
}

ll get(int l, int r) {
	return get(r) - get(l - 1);
}

void add(int x, int w) {
	while (x <= n) {
		bit[x] += w;
		x += lowbit(x);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	double ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += get(a[i] + 1, n);
		add(a[i], 1);
	}
	double sb = 1.0 * n * (n + 1) / 2;
	memset(bit, 0, sizeof(bit));
	for (int i = 1; i <= n; i++) {
		ans -= 1.0 * get(a[i] + 1, n) / sb * (n - i + 1);
		ans += 1.0 * i * (i - 1) / 4 / sb * (n - i + 1);
		add(a[i], i);
	}
	printf("%.16f\n", ans);
	return 0;
}