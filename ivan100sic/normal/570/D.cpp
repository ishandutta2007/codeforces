#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct qry {
	int id, h;
};

int n, m;
basic_string<int> e[500005];
int ans[500005], dub[500005], a[500005];
basic_string<qry> q[500005];

void spoji(vector<int>& a, vector<int>& b) {
	if (a.size() < b.size())
		swap(a, b);
	for (int i=0; i<(int)b.size(); i++)
		a[i + a.size() - b.size()] ^= b[i];
}

vector<int> dfs(int x, int d = 1) {
	vector<int> t;
	for (int y : e[x]) {
		auto z = dfs(y, d+1);
		spoji(t, z);
	}
	t.push_back(a[x]);
	for (qry b : q[x]) {
		int r = b.h - d;
		if (r < 0 || r >= (int)t.size())
			continue;
		ans[b.id] = t[(int)t.size() - 1 - r];
	}
	return t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=2; i<=n; i++) {
		int p;
		cin >> p;
		e[p] += i;
	}

	{
		string s;
		cin >> s;
		for (int i=0; i<n; i++) {
			a[i+1] = 1 << (s[i] - 'a');
		}
	}

	for (int i=1; i<=m; i++) {
		int v, h;
		cin >> v >> h;
		q[v] += {i, h};
	}

	dfs(1);

	for (int i=1; i<=m; i++) {
		if ((ans[i] & -ans[i]) == ans[i]) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
}