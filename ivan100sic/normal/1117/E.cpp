#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

basic_string<int> presek(basic_string<int> a, basic_string<int> b) {
	basic_string<int> c(a.size(), 0);
	int n = set_intersection(
		a.begin(), a.end(),
		b.begin(), b.end(),
		c.begin()
	) - c.begin();
	c.resize(n);
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string t;
	cin >> t;
	int n = t.size();

	// prvi upit
	map<int, basic_string<int>> mozda;
	map<int, basic_string<int>> inv_mozda;
	{
		string a;
		for (int i=0; i<n; i++)
			a += (char)('a' + i%26);
		cout << "? " << a << '\n' << flush;
		string b;
		cin >> b;
		map<char, basic_string<int>> mesta;
		for (int i=0; i<n; i++) {
			mesta[b[i]] += i;
		}
		for (int i=0; i<n; i++) {
			mozda[i] = mesta[a[i]];
		}
		for (auto p : mozda) {
			int x = p.first;
			for (int y : p.second) {
				inv_mozda[y] += x;
			}
		}
	}

	// svaki naredni, ciklicno dodeli slova u mesta
	for (int rep=0; rep<2; rep++) {
		string a = t; int br = 0;
		for (auto p : inv_mozda) {
			// int x = p.first;
			for (int y : p.second) {
				a[y] = 'a' + (br++ % 26);
			}
		}

		cout << "? " << a << '\n' << flush;
		string b;
		cin >> b;
		map<char, basic_string<int>> mesta;
		for (int i=0; i<n; i++) {
			mesta[b[i]] += i;
		}

		for (int i=0; i<n; i++) {
			mozda[i] = presek(mozda[i], mesta[a[i]]);
		}

		inv_mozda = {};

		for (auto p : mozda) {
			int x = p.first;
			for (int y : p.second) {
				inv_mozda[y] += x;
			}
		}
	}

	string s = t;
	for (int i=0; i<n; i++)
		s[i] = t[mozda[i][0]];

	cout << "! " << s << '\n' << flush;
}