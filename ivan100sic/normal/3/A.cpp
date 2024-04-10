#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string p, q;
	cin >> p >> q;
	vector<string> sol;
	while (p != q) {
		string mv;

		if (p[0] < q[0]) {
			mv += 'R';
			p[0]++;
		} else if (p[0] > q[0]) {
			mv += 'L';
			p[0]--;
		}

		if (p[1] < q[1]) {
			mv += 'U';
			p[1]++;
		} else if (p[1] > q[1]) {
			mv += 'D';
			p[1]--;
		}

		sol.push_back(mv);
	}

	cout << sol.size() << '\n';
	for (auto s : sol)
		cout << s << '\n';
}