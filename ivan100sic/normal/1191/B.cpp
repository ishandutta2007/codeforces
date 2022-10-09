#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int rek(vector<string> a, int d) {
	if (d > 2)
		return d;
	map<string, int> c;
	for (string s : a)
		c[s]++;

	for (auto [s, y] : c) {
		if (y >= 3)
			return d;		
	}

	for (string s : a) {
		string p = s;
		p[0]++;
		string q = p;
		q[0]++;
		if (c.count(p) && c.count(q))
			return d;
	}

	int sol = 3;
	for (char x : {'m', 's', 'p'})
		for (char y='1'; y<='9'; y++) {
			vector<string> b = a;
			b.push_back(string()+y+x);
			sol = min(sol, rek(b, d+1));
		}
	return sol;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	vector<string> b(3);
	for (string& s : b)
		cin >> s;
	cout << rek(b, 0) << '\n';
}