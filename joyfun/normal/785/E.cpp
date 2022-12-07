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

#define lowbit(x) (x&(-x))
const int N = 200005;
const int B = 1000;
int n, q;
int bit[205][N], a[N], id[N];

void add(int x, int w, int *bit) {
	while (x <= n) {
		bit[x] += w;
		x += lowbit(x);
	}
}

int get(int x, int *bit) {
	int ans = 0;
	while (x) {
		ans += bit[x];
		x -= lowbit(x);
	}
	return ans;
}

int get(int l, int r, int *bit) {
	return get(r, bit) - get(l - 1, bit);
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		id[i] = i / B; a[i] = i;
		add(a[i], 1, bit[id[i]]);
	}
	ll ans = 0;
	int l, r;
	while (q--) {
		scanf("%d%d", &l, &r);
		if (l > r) swap(l, r);
		ll s1 = 0, s2 = 0;
		for (int i = id[l] + 1; i <= id[r] - 1; i++) {
			s1 += get(a[l], n, bit[i]); 
			s2 += get(1, a[r], bit[i]);
		}
		for (int i = l; id[i] == id[l] && i <= r; i++) {
			if (a[l] < a[i]) s1++;
			if (a[r] > a[i]) s2++;
		}
		if (id[l] != id[r]) for (int i = r; id[i] == id[r] && i >= l; i--) {
			if (a[l] < a[i]) s1++;
			if (a[r] > a[i]) s2++;
		}
		ans += s1 + s2; if (a[l] < a[r]) ans--;
		ans -= (r - l - s1); ans -= (r - l - s2); if (a[l] > a[r]) ans++;
		printf("%lld\n", ans);
		add(a[l], -1, bit[id[l]]); add(a[r], 1, bit[id[l]]);
		add(a[r], -1, bit[id[r]]); add(a[l], 1, bit[id[r]]);
		swap(a[l], a[r]);
	}
	return 0;
}