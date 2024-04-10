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
	int z = 0;
	for (int i=1; i<=n; i++) {
		auto it = s.lower_bound(i);
		if (it == s.end()) {
			break;
		} else {
			s.erase(it);
			z = i;
		}
	}
	cout << z << '\n';
}