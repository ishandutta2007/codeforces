#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int sm(ll x) {
	return min<ll>(2e9, x);
}

struct opis {
	int pref, suff, sol, len;
	char pc, sc;
	basic_string<int> streaks;
};

opis nadji_opis(string s, string slova) {
	int m = s.size();
	
	opis o;
	o.pref = o.suff = o.sol = 1;
	o.len = m;
	o.pc = s[0];
	o.sc = s[m-1];

	while (o.pref < m && s[o.pref] == s[0])
		o.pref++;
	if (o.pref == m)
		o.suff = m;
	else {
		while (s[m-1-o.suff] == s[m-1]) {
			o.suff++;
		}
	}

	int streak = 0;
	char last = 0;
	for (char x : s) {
		if (x == last) {
			streak++;
		} else {
			streak = 1;
		}
		o.sol = max(o.sol, streak);
		last = x;
	}

	for (char x : slova) {
		streak = 0;
		int z = 0;
		for (char y : s) {
			if (y == x)
				streak++;
			else
				streak = 0;
			z = max(z, streak);
		}
		o.streaks += z;
	}

	return o;
}

string arr[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> arr[i];

	auto p = nadji_opis(arr[n-1], "");

	for (int i=n-2; i>=0; i--) {
		const string& s = arr[i];

		auto q = nadji_opis(s, string() + p.pc + p.sc);
		opis t = p;
		t.len = sm((p.len + 1ll) * q.len + p.len);

		if (p.pref == p.len) {
			t.pref = (p.len + 1) * (q.pc == p.pc ? q.pref : 0) + p.len;
			t.suff = (p.len + 1) * (q.sc == p.pc ? q.suff : 0) + p.len;
			int infix = (p.len + 1) * q.streaks[0] + p.len;
			t.sol = max({t.sol, t.pref, t.suff, infix});
		} else if (p.pc == p.sc) {
			if (q.streaks[0])
				t.sol = max(t.sol, p.suff + 1 + p.pref);
		} else {
			if (q.streaks[0])
				t.sol = max(t.sol, p.pref + 1);
			if (q.streaks[1])
				t.sol = max(t.sol, p.suff + 1);
		}

		p = t;
	}

	cout << p.sol << '\n';
}