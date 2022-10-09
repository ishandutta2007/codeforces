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

	set<string> b;
	string s;
	cin >> s;
	int n = s.size();
	for (int i=0; i<n; i++) {
		rotate(s.begin(), s.begin() + 1, s.end());
		b.insert(s);
	}
	cout << b.size() << '\n';
}