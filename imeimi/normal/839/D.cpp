#include <iostream>
#include <algorithm>

using namespace std;
typedef long long llong;

const llong mod = 1e9 + 7;

struct num {
	llong x;
	num() : x(0ll) {}
	num(llong p) : x(p) {}
	num operator+(const num &p) const {
		return (x + p.x) % mod;
	}
	num operator-(const num &p) const {
		return (x - p.x + mod) % mod;
	}
	num operator*(const num &p) const {
		return (x * p.x) % mod;
	}
};

int n;
num nn2[200001];
int cnt[1000001];
int dii[1000001];
num dis[1000001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	int x;
	nn2[0] = 1;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		cnt[x] += 1;
		nn2[i + 1] = nn2[i] * num(2);
	}
	for (int i = 2; i <= 1e6; ++i) {
		for (int j = i; j <= 1e6; j += i) {
			dii[i] = dii[i] + cnt[j];
		}
	}
	num ans = 0ll;
	num tmp;
	for (int i = 1e6; i > 1; --i) {
		if (dii[i] == 0) continue;
		tmp = num(dii[i]) * nn2[dii[i] - 1];
		dis[i] = dis[i] + tmp;
		for (int j = 2; j * j <= i; ++j) {
			if (i % j != 0) continue;
			dis[j] = dis[j] - dis[i];
			if (j * j != i) dis[i / j] = dis[i / j] - dis[i];
		}
		ans = ans + num(i) * dis[i];
	}
	printf("%lld\n", ans.x);
	return 0;
}