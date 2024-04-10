#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct brojac {
	multiset<int> vals;
	vector<int> a;
	int sum;

	brojac() : a(100005, 0), sum(0) {}

	void add(int x) {
		auto it = vals.find(a[x]);
		if (it != vals.end())
			vals.erase(it);
		a[x]++;
		sum++;
		vals.insert(a[x]);
	}

	int get() const {
		return sum - (!vals.size() ? 0 : *vals.rbegin());
	}

	void remove(int x) {
		vals.erase(vals.find(a[x]));
		a[x]--;
		sum--;
		vals.insert(a[x]);
	}
} br;

int a[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];

	int r = 0, sol = 0;
	for (int i=0; i<n; i++) {
		while (r < n) {
			br.add(a[r++]);
			if (br.get() > k) {
				br.remove(a[--r]);
				break;
			}
		}
		sol = max(sol, r-i-br.get());
		br.remove(a[i]);
	}
	cout << sol << '\n';
}