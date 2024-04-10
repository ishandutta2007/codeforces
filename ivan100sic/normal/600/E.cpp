#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct summable_set {
	set<int> s;
	ll sum;

	void erase(int x) {
		s.erase(x);
		sum -= x;
	}

	void insert(int x) {
		s.insert(x);
		sum += x;
	}
};

struct indikator {
	map<int, int> freq;
	map<int, summable_set> inv;

	int size() {
		return freq.size();
	}

	void insert(int x, int y) {
		inv[freq[x]].erase(x);
		freq[x] += y;
		inv[freq[x]].insert(x);
	}
};

void spoji(indikator& a, indikator& b) {
	if (a.size() < b.size())
		swap(a, b);

	for (auto [x, y] : b.freq)
		a.insert(x, y);
}

int n;
basic_string<int> e[100005];
int a[100005];
ll sol[100005];

indikator dfs(int x, int p) {
	indikator moj;
	moj.insert(a[x], 1);
	for (int y : e[x]) {
		if (y == p)
			continue;
		indikator tmp = dfs(y, x);
		spoji(moj, tmp);
	}
	sol[x] = moj.inv.rbegin()->second.sum;
	return moj;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}
	dfs(1, 1);
	for (int i=1; i<=n; i++)
		cout << sol[i] << " \n"[i == n];
}