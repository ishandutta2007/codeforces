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
		set<int> s;
		while (n--) {
			int x;
			cin >> x;
			while (x % 2 == 0) {
				s.insert(x);
				x >>= 1;
			}
		}
		cout << s.size() << '\n';
	}
}