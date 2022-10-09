#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<ll, char> pic;

vector<pic> compress(vector<pic> a) {
	vector<pic> b;
	for (pic p : a) {
		if (!b.size() || p.second != b.back().second) {
			b.push_back(p);
		} else {
			b.back().first += p.first;
		}
	}
	return b;
}

vector<pic> p, q, b;
int z[400005];
int n, m, k;

pic read() {
	string s;
	cin >> s;
	pic p;
	p.second = s.back();
	s.pop_back();
	s.pop_back();
	p.first = stoi(s);
	return p;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		p.push_back(read());
	for (int i=0; i<m; i++)
		q.push_back(read());

	p = compress(p);
	q = compress(q);

	n = p.size();
	m = q.size();

	if (m == 1) {
		ll sol = 0;
		for (auto e : p) {
			if (e.second == q[0].second)
				sol += max(0ll, e.first - q[0].first + 1);
		}
		cout << sol << '\n';
	} else if (q.size() == 2) {
		ll sol = 0;
		for (int i=0; i<n-1; i++) {
			if (p[i].second != q[0].second)
				continue;
			if (p[i+1].second != q[1].second)
				continue;
			if (p[i].first < q[0].first)
				continue;
			if (p[i+1].first < q[1].first)
				continue;
			sol++;
		}
		cout << sol << '\n';
	} else {
		ll sol = 0;

		for (int i=1; i<m-1; i++)
			b.push_back(q[i]);
		b.push_back({-1, 0});
		copy(p.begin(), p.end(), back_inserter(b));

		k = b.size();
		for (int i=1, l=0, r=0; i<k; i++) {
			if (i < r) {
				z[i] = min(r-i, z[i-l]);
			}
			while (i + z[i] < k && b[z[i]] == b[i + z[i]])
				z[i]++;

			if (i + z[i] > r) {
				l = i;
				r = i + z[i];
			}
		}

		for (int i=0; i+m-1 < n; i++) {
			if (p[i].second != q[0].second)
				continue;
			if (p[i + m - 1].second != q[m-1].second)
				continue;
			if (p[i].first < q[0].first)
				continue;
			if (p[i + m - 1].first < q[m-1].first)
				continue;

			if (z[i + m] != m - 2)
				continue;

			sol++;
		}

		cout << sol << '\n';
	}
}