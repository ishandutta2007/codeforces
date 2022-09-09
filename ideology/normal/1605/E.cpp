#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
 
#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll labs(ll x) { return x < 0 ? -x : x; }

const int N = 200010;

int mu[N];
ll a[N], b[N];

struct DS {
	int n;
	ll a[N], sum[N];
	void pre() {
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
	}
	void ins(ll x) { a[++n] = x; }
	ll qry(ll x) {
		int pos = lower_bound(a + 1, a + n + 1, x) - a;
		ll ret = x * (pos - 1) - sum[pos - 1];
		ret += sum[n] - sum[pos - 1] - x * (n - pos + 1);
		return ret;
	}
} X, Y;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n; cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];
	int tmp = b[1];
	for (int i = 1; i <= n; ++i) b[i] -= a[i];
	for (int i = 1; i <= n; ++i)
		for (int j = i + i; j <= n; j += i) b[j] -= b[i];
	mu[1] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = i + i; j <= n; j += i) mu[j] -= mu[i];

	ll sum = 0;
	for (int i = 1; i <= n; ++i)
		if (mu[i] == 0) sum += labs(b[i]);
		else if (mu[i] == 1) X.ins(b[i]);
		else Y.ins(b[i]);

	X.pre(); Y.pre();

	int q; cin >> q;
	while (q--) {
		int x; cin >> x;
		int d = x - tmp;
		cout << (sum + X.qry(-d) + Y.qry(d)) << '\n';
	}

	return 0;
}