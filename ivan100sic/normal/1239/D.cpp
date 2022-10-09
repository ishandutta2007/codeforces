#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<int> e[1000005];

int idx[1000005], low[1000005], tt, cc;
bool inst[1000005];
basic_string<int> st;
bool ans[1000005];

void scc(int x) {
	idx[x] = low[x] = ++tt;
	inst[x] = 1;
	st += x;
	for (int y : e[x]) {
		if (idx[y] == 0) {
			scc(y);
			low[x] = min(low[x], low[y]);
		} else if (inst[y]) {
			low[x] = min(low[x], idx[y]);
		}
	}

	if (idx[x] == low[x]) {
		while (1) {
			int z = st.back();
			st.pop_back();
			ans[z] = !cc;
			if (z == x)
				break;
		}
		cc++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;

		for (int i=1; i<=m; i++) {
			int x, y;
			cin >> x >> y;
			if (x != y) {
				e[x] += y;
			}
		}

		for (int i=1; i<=n; i++)
			if (idx[i] == 0)
				scc(i);

		basic_string<int> up, dn;
		for (int i=1; i<=n; i++)
			(ans[i] ? up : dn) += i;

		if ((int)up.size() == n || (int)dn.size() == n) {
			cout << "No\n";
		} else {
			cout << "Yes\n";
			cout << up.size() << ' ' << dn.size() << '\n';
			for (int x : up)
				cout << x << ' ';
			cout << '\n';
			for (int x : dn)
				cout << x << ' ';
			cout << '\n';
		}

		for (int i=1; i<=n; i++) {
			e[i] = {};
			idx[i] = low[i] = ans[i] = inst[i] = 0;
		}
		tt = cc = 0;
		st = {};
	}	
}