#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, p[N], cnt[N];
char s[N];

signed main() {
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);

	cin >> (s + 1);
	n = strlen(s + 1);

	for (int i = 2; i <= n; i++) {
		int j = p[i - 1];
		while (j && s[j + 1] != s[i])
			j = p[j];
		p[i] = j + (s[j + 1] == s[i]);
	}

	fill(cnt + 1, cnt + n + 1, 1);
	for (int i = n; i; i--)
		cnt[p[i]] += cnt[i];

	int res = p[n];
	while (res && cnt[res] < 3)
		res = p[res];

	if (res) {
		for (int j = 1; j <= res; j++)
			cout << s[j];
	} else {
		cout << "Just a legend";
	}
}