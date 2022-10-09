#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct seg {
	int l, r, i;
	bool operator< (const seg& b) const {
		return l < b.l;
	}
};

int n, k;
seg a[200005];
bool u[400005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i].l >> a[i].r, a[i].i = i;
	sort(a, a+n);

	set<pair<int, int>> pq;
	for (int i=0; i<k; i++)
		pq.insert({0, n+i});

	for (int i=0; i<n; i++) {
		auto it = pq.lower_bound({a[i].l, -1});
		if (it == pq.begin()) {
			it = --pq.end();
			if (a[i].r < it->first) {
				u[it->second] = 1;
				pq.erase(it);
				pq.insert({a[i].r, a[i].i});
			} else {
				u[a[i].i] = 1;
			}
		} else {
			--it;
			pq.erase(it);
			pq.insert({a[i].r, a[i].i});
		}

	}

	cout << count(u, u+n, 1) << '\n';
	for (int i=0; i<n; i++)
		if (u[i])
			cout << i+1 << ' ';
	cout << '\n';

}