#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

basic_string<int> f[100005];
int n, m;
int ans[100005];
int od[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		f[y] += x;
		od[x]++;
	}

	set<int> q;
	for (int i=1; i<=n; i++)
		if (od[i] == 0)
			q.insert(i);

	int r = n;
	while (q.size()) {
		int x = *prev(q.end());
		q.erase(x);
		ans[x] = r--;
		for (int y : f[x])
			if (od[y]-- == 1)
				q.insert(y);
	}

	for (int i=1; i<=n; i++)
		cout << ans[i] << " \n"[i == n];
}