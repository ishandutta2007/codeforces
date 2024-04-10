// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
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

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (int& x : a)
			cin >> x;
		for (int& x : b)
			cin >> x;
		sort(begin(a), end(a));
		sort(begin(b), end(b));
		for (int x : a)
			cout << x << ' ';
		cout << '\n';
		for (int x : b)
			cout << x << ' ';
		cout << '\n';
	}
}

// I will still practice daily...