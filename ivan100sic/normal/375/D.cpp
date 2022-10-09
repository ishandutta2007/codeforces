#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> drvo;

int global_t = 11;

struct indikator {
	map<int, int> freq;
	shared_ptr<drvo> inv;

	indikator() : inv(make_shared<drvo>()) {}

	int size() {
		return freq.size();
	}

	void insert(int x, int y) {
		auto it = freq.find(x);
		if (it != freq.end()) {
			inv->erase(inv->lower_bound(freq[x] * 123123123ll - 11));
			it->second += y;
		} else {
			it = freq.insert({x, y}).first;
		}
		inv->operator[](it->second * 123123123ll + (++global_t));
	}
};

void spoji(indikator& a, indikator& b) {
	if (a.size() < b.size()) {
		swap(a.freq, b.freq);
		swap(a.inv, b.inv);
	}

	for (auto [x, y] : b.freq)
		a.insert(x, y);
}

int n;
basic_string<int> e[100005];
int a[100005], q;
ll sol[100005];
basic_string<pair<int, int>> qrys[100005];

indikator dfs(int x, int p) {
	indikator moj;
	moj.insert(a[x], 1);
	for (int y : e[x]) {
		if (y == p)
			continue;
		indikator tmp = dfs(y, x);
		spoji(moj, tmp);
	}

	sort(qrys[x].begin(), qrys[x].end());
	for (auto [k, i] : qrys[x])
		sol[i] = moj.inv->size() - moj.inv->order_of_key(k * 123123123ll - 11);
	
	return move(moj);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	for (int i=0; i<q; i++) {
		int v, k;
		cin >> v >> k;
		qrys[v] += {k, i};
	}

	dfs(1, 1);
	for (int i=0; i<q; i++)
		cout << sol[i] << "\n";
}