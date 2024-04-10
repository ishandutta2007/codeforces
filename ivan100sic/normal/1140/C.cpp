#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

multiset<int> p, q;
ll sq;
pair<int, int> a[300005];
int n, k;

int curr_b;

void transfer() {
	while ((int)q.size() < k && p.size()) {
		auto it = prev(p.end());
		q.insert(*it);
		sq += *it;
		p.erase(it);
	}
	while ((int)q.size() > k) {
		auto it = q.begin();
		p.insert(*it);
		sq -= *it;
		q.erase(it);
	}
}

void add(int b, int w) {
	curr_b = b;
	if (q.size() == 0) {
		q.insert(w);
		sq += w;
	} else {
		if (w < *q.begin())
			p.insert(w);
		else {
			q.insert(w);
			sq += w;
		}
		transfer();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> a[i].second >> a[i].first;
	}
	ll sol = 0;
	sort(a, a+n, greater<>()); // how does this even work
	for (int i=0; i<n; i++) {
		add(a[i].first, a[i].second);
		sol = max(sol, curr_b * sq);
	}
	cout << sol << '\n';
}