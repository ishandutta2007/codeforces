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

	string a, b;
	int n;
	cin >> n >> a >> b;

	int p = 0, s = 0;
	while (a[p] == b[p])
		p++;
	while (a[n-s-1] == b[n-s-1])
		s++;
	s = n-s;

	set<string> sol;
	if (a.substr(p+1, s-p-1) == b.substr(p, s-p-1)) {
		sol.insert(a.substr(0, s) + b.substr(s));
	}
	swap(a, b);
	if (a.substr(p+1, s-p-1) == b.substr(p, s-p-1)) {
		sol.insert(a.substr(0, s) + b.substr(s));
	}
	swap(a, b);
	cout << sol.size() << '\n';
}