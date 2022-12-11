#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;

int firstpos(const string& a, const string& b) {
	string s = a + "#" + b;
	int n = sz(s);
	vector<int> p(n);
	for (int i = 1; i < n; ++i) {
		int j = p[i - 1];
		while (j && s[i] != s[j]) {
			j = p[j - 1];
		}
		if (s[i] == s[j]) {
			++j;
		}
		p[i] = j;
	}
	for (int i = sz(a); i < sz(s); ++i) {
		if (p[i] == sz(a)) {
			return i - 2 * sz(a);
		}
	}
	return -1;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;

	vector<string> s(n), t(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
	}

	int ff = -1;
	for (int i = 0; i < n; ++i) {
		if (s[i] != t[i]) {
			ff = i;
		}
	}
	swap(s[0], s[ff]);
	swap(t[0], t[ff]);

	vector<int> l(n), r(n);
	for (int i = 0; i < n; ++i) {
		l[i] = 0;
		while (l[i] < sz(s[i]) && s[i][l[i]] == t[i][l[i]]) {
			++l[i];
		}
		r[i] = sz(s[i]) - 1;
		while (r[i] >= 0 && s[i][r[i]] == t[i][r[i]]) {
			--r[i];
		}
	}

	for (int i = 1; i < n; ++i) {
		if (l[i] == sz(s[i])) {
			continue;
		}
		if (s[i].substr(l[i], r[i] - l[i] + 1) != s[0].substr(l[0], r[0] - l[0] + 1)) {
			cout << "NO\n";
			return 0;
		}
	}

	int lf = l[0];
	int rg = sz(s[0]) - r[0] - 1;
	for (int i = 1; i < n; ++i) {
		if (l[i] == sz(s[i])) {
			continue;
		}
		int newL = 0;
		while (newL + 1 <= lf && l[i] - newL - 1 >= 0 && s[i][l[i] - newL - 1] == s[0][l[0] - newL - 1]) {
			++newL;
		}
		int newR = 0;
		while (newR + 1 <= rg && r[i] + newR + 1 < sz(s[i]) && s[i][r[i] + newR + 1] == s[0][r[0] + newR + 1]) {
			++newR;
		}
		lf = min(lf, newL);
		rg = min(rg, newR);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < l[i]; ++j) {
			assert(s[i][j] == t[i][j]);
		}
		assert(l[i] == sz(s[i]) || s[i][l[i]] != t[i][l[i]]);

		for (int j = r[i] + 1; j < sz(s[i]); ++j) {
			assert(s[i][j] == t[i][j]);
		}
		assert(r[i] == -1 || s[i][r[i]] != t[i][r[i]]);
	}

	string res = "";
	for (int i = l[0] - lf; i <= r[0] + rg; ++i) {
		res += s[0][i];
	}
	/*for (int i = 1; i < n; ++i) {
		if (l[i] == sz(s[i])) {
			continue;
		}
		assert(s[i].substr(l[i] - lf, r[i] + rg - (l[i] - lf) + 1) == res);
	}*/

	/*for (int i = 0; i < n; ++i) {
		if (l[i] == sz(s[i])) {
			if (firstpos(res, s[i]) != -1) {
				cout << "NO\n";
				return 0;
			}
		} else if (firstpos(res, s[i]) != l[i] - lf) {
			cout << "NO\n";
			return 0;
		}
	}*/

	string u = "", v = "";
	for (int i = l[0] - lf; i <= r[0] + rg; ++i) {
		u += s[0][i];
	}
	for (int i = l[0] - lf; i <= r[0] + rg; ++i) {
		v += t[0][i];
	}

	for (int i = 0; i < n; ++i) {
		string tmp = s[i];
		int pos = firstpos(u, s[i]);
		if (pos == -1) {
			if (s[i] != t[i]) {
				cout << "NO\n";
				return 0;
			}
			continue;
		}
		for (int j = 0; j < sz(u); ++j) {
			tmp[j + pos] = v[j];
		}
		//cout << i << " " << u << " " << v << " " << s[i] << " " << tmp << " " << t[i] << endl;
		if (tmp != t[i]) {
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";
	cout << u << "\n" << v << "\n";

}