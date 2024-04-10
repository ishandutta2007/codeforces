#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

char s[N];
int n, p[N], cnt[N];

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

	vector<int> res;
	for (int i = n; i; i = p[i])
		res.push_back(i);
	reverse(res.begin(), res.end());

	for (int i = n; i; i--)
		cnt[p[i]] += cnt[i];

	cout << res.size() << '\n';
	for (int l : res)
		cout << l << ' ' << cnt[l] << '\n';
}