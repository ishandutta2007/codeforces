#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<string, string> a = {
	{"Power", "purple"},
	{"Time", "green"},
	{"Space", "blue"},
	{"Soul", "orange"},
	{"Reality", "red"},
	{"Mind", "yellow"}
}, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	set<string> c;
	for (auto p : a) {
		b[p.second] = p.first;
		c.insert(p.first);
	}
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		c.erase(b[s]);
	}
	cout << c.size() << '\n';
	for (auto s : c)
		cout << s << '\n';
}