#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;

struct tinyint {
	int x;

	tinyint(int y = 0) : x(y) {}

	tinyint operator+ (const tinyint other) const {
		return {min(x + other.x, 2)};
	}
};

vector<tinyint> p;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	p.assign(m, 0);
	p[0] = 1;

	for (int i=0; i<n; i++) {
		int x;
		cin >> x;

		auto q = p;
		for (int i=0; i<m; i++) {
			q[(i + x) % m] = q[(i + x) % m] + p[i];
		}

		if (q[0].x == 2) {
			cout << "YES\n";
			return 0;
		}

		swap(p, q);
	}

	cout << "NO\n";
}