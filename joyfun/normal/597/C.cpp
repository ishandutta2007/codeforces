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
ll bit[12][N];
int n, k;

#define lowbit(x) (x&(-x))

void add(int x, ll w, ll *bit) {
	while (x <= n) {
		bit[x] += w;
		x += lowbit(x);
	}
}

ll get(int x, ll *bit) {
	ll ans = 0;
	while (x) {
		ans += bit[x];
		x -= lowbit(x);
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &k); k++;
	int x;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		for (int j = 2; j <= k; j++)
			add(x, get(x - 1, bit[j - 1]), bit[j]);
		add(x, 1, bit[1]);
	}
	printf("%lld\n", get(n, bit[k]));
	return 0;
}