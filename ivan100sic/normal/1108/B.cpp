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

	int y = *s.rbegin();

	for (int i=1; i<=y; i++) {
		if (y % i == 0) {
			s.erase(s.find(i));
		}
	}

	cout << *s.rbegin() << ' ' << y << '\n';
}