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

	string s, t;
	cin >> s >> t;
	string p = s;
	int i = p.size() - 1;
	p[i]++;
	while (p[i] == 'z'+1) {
		p[i] = 'a';
		p[--i]++;
	}
	if (p == t)
		cout << "No such string\n";
	else
		cout << p << '\n';
}