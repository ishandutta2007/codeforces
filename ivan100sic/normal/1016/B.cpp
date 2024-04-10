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

	vector<int> occ;
	string s, p;
	int n, m, q;
	cin >> n >> m >> q >> s >> p;
	for (int i=0; i+m<=n; i++)
		if (s.substr(i, m) == p)
			occ.push_back(i+1);

	while (q--) {
		int l, r;
		cin >> l >> r;
		r -= m-1;
		cout << count_if(occ.begin(), occ.end(), [&](int x)
			{ return l <= x && x <= r; }) << '\n';
	}
}