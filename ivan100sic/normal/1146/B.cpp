#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void no() {
	cout << ":(\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	string p;
	for (char x : s) {
		if (x != 'a')
			p += x;
	}
	if (p.size() % 2)
		no();
	int k = p.size() / 2;
	for (int i=0; i<k; i++)
		if (p[i] != p[i+k])
			no();

	string t = s.substr(0, s.size()-k), u;
	for (char x : t) {
		if (x != 'a')
			u += x;
	}
	if (t + u != s)
		no();
	cout << t << '\n';
}