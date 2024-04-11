#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

long long n;

int ask(long long p, long long val, int len) {
	long long k = 0;
	long long now = val;
	if (p == (1ll << len))
		return val & 1;
	else
		if (p > (1ll << len))
			return ask(p - (1ll << len), val >> 1, len - 1);
		else
			return ask(p, val >> 1, len - 1);
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	long long l, r;
	cin >> n >> l >> r;
	int ans = 0;
	long long now = n;
	int len = 0;
    while (now) {
		len++;
		now >>= 1;
	}
	len--;
	for (long long i = l; i <= r; i++) {
		ans += ask(i, n, len);
	}
	cout << ans;
	return 0;
}