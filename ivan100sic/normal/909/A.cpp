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

	string s, p;
	cin >> s >> p;
	string q = s + p;
	for (int i=1; i<=(int)s.size(); i++)
		for (int j=1; j<=(int)p.size(); j++)
			q = min(q, s.substr(0, i) + p.substr(0, j));
	cout << q << '\n';
}