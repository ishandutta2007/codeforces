#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<string, int> ch;

int ask(string s) {
	if (ch.count(s))
		return ch[s];
	cout << s << '\n' << flush;
	cin >> ch[s];
	if (ch[s] == 0)
		exit(0);
	return ch[s];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int x = ask(string(300, 'a'));
	int y = ask(string(300, 'b'));

	int a = 300 - x;
	int b = 300 - y;
	int n = a + b;

	string s = string(a, 'a');
	int p = a;
	while (p > 0 && b > 0) {
		string t = s;
		t.insert(t.begin() + p, 'b');
		if (ask(t) != n - (int)t.size()) {
			p--;
		} else {
			b--;
			s = t;
		}
	}
	while (b--) {
		s.insert(s.begin(), 'b');
	}
	ask(s);
}