#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int n, x;
map<int, int> cnt;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		cnt[x]++;
	}
	if (cnt.begin()->second <= n / 2) {
		puts("Alice");
	} else {
		puts("Bob");
	}
}