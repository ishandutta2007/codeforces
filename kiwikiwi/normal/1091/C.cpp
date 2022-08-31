#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int n;
set<i64> ans;
int main() {
	scanf("%d", &n);
	auto add = [&](int x) {
		ans.insert((i64)x * (1 + n + 1 - n / x) / 2);
	};
	for (int i = 1; i * i <= n; i++)
		if (n % i == 0) add(i), add(n / i);
	for (auto p : ans) {
		printf("%lld ", p);
	}
	puts("");
}