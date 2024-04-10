// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		set<set<int>> s0;
		int n;

		auto fe = [](set<set<int>>& s0) {
			map<int, int> f;
			for (auto s : s0)
				for (auto x : s)
					f[x]++;
			vector<int> e;
			for (auto [x, y] : f)
				if (y == 1)
					e.push_back(x);
			return e;
		};

		cin >> n;
		for (int i=1; i<n; i++) {
			int k;
			cin >> k;
			set<int> s;
			while (k--) {
				int x;
				cin >> x;
				s.insert(x-1);
			}
			s0.insert(move(s));
		}

		vector<int> p(n, -1), q(n, -1);

		auto verify = [&](vector<int> p) {
			auto s = s0;
			for (int r=n-1; r>=1; r--) {
				set<int> ss;
				bool ok = false;
				for (int l=r; l>=0; l--) {
					ss.insert(p[l]);
					if (s.count(ss)) {
						s.erase(ss);
						ok = true;
						break;
					}
				}
				if (!ok)
					return;
			}
			q = p;
		};

		auto s1 = s0;

		auto fri = [](set<set<int>>& s, int x) {
			set<int> ss;
			for (auto& v : s)
				if (v.count(x))
					ss = v;
			s.erase(ss);
		};

		for (int i=n-1; i>=1; i--) {
			auto v = fe(s1);
			if (v.size() == 1) {
				// samo nastavi
				p[i] = v[0];
				fri(s1, p[i]);
			} else {
				// granaj se
				for (int x : v) {
					int y = v[0] ^ v[1] ^ x;

					auto s = s1;
					bool ok = true;
					for (int j=i; j>=2; j--) {
						auto v = fe(s);
						auto it = find(begin(v), end(v), y);
						if (it != end(v))
							v.erase(it);
						if (v.size() != 1) {
							ok = false;
							break;
						}
						p[j] = v[0];
						fri(s, p[j]);
					}

					if (ok) {
						p[0] = y;
						p[1] = 0;
						p[1] = n*(n-1)/2 - accumulate(begin(p), end(p), 0);
						verify(p);
					}
				}

				break;
			}
		}

		for (int x : q)
			cout << x+1 << ' ';
		cout << '\n';
	}
}