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

	int n;
	cin >> n;
	multiset<int> s;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		s.insert(x);
	}
	for (int i=1; i<=n+1; i++) {
		auto it = s.lower_bound(i);
		if (it == s.end() /* n.udes() */) {
			cout << i << '\n';
			return 0;
		}
		s.erase(it);
	}
}