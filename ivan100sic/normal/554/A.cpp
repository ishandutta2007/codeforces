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

	string s;
	cin >> s;
	int n = s.size();
	set<string> b;
	for (int i=0; i<=n; i++) {
		for (char x='a'; x<='z'; x++) {
			string p = s;
			p.insert(p.begin() + i, x);
			b.insert(p);
		}
	}
	cout << b.size() << '\n';
}