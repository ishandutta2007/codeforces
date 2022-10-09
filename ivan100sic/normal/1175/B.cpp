#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll mul(ll x, ll y) {
	if (x * 1.0 * y > 1e12)
		return 1e12;
	return x*y;
}

ll add(ll x, ll y) {
	if (x + 0.0 + y > 1e12)
		return 1e12;
	return x+y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;

	basic_string<pair<ll, ll>> st = {{1, 0}};

	for (int tc=0; tc<t; tc++) {
		string s;
		cin >> s;
		if (s == "add") {
			st.back().second = add(st.back().second, 1);
		} else if (s == "end") {
			st[st.size()-2].second = add(st[st.size()-2].second,
				mul(st.back().first, st.back().second));
			st.pop_back();
		} else {
			ll x;
			cin >> x;
			st += {x, 0};
		}
	}

	if (st.back().second > (1ll << 32) - 1) {
		cout << "OVERFLOW!!!\n";
		
	} else {
		cout << st.back().second << '\n';
	}
}