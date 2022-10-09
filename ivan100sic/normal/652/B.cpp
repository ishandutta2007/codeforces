// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n;
	cin >> n;
	multiset<int> s;
	while (n--) {
		int x;
		cin >> x;
		s.insert(x);
	}

	int i = 1;
	while (s.size()) {
		int x;
		if (i)
		 	x = *s.begin();
		else
			x = *s.rbegin();
		s.erase(s.find(x));
		i ^= 1;
		cout << x << ' ';
	}
	cout << '\n';
}