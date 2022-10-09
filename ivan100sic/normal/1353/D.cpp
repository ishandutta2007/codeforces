// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct stvar {
	int l, r;
	template<class T>
	auto operator< (const T& b) const {
		return pair(r-l, -l) > pair(b.r-b.l, -b.l);
	}
};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		set<stvar> q;
		int n;
		cin >> n;
		vector<int> a(n);
		q.insert({0, n-1});
		for (int i=1; i<=n; i++) {
			auto [l, r] = *q.begin();
			q.erase(q.begin());
			int m = (l+r) / 2;
			a[m] = i;
			if (l <= m-1) {
				q.insert({l, m-1});
			}
			if (m+1 <= r) {
				q.insert({m+1, r});
			}
		}
		for (int x : a)
			cout << x << ' ';
		cout << '\n';
	}
}