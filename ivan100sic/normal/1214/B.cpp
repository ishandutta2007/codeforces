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

	int b, g, n;
	cin >> b >> g >> n;
	set<int> s;

	for (int x=0; x<=n; x++) {
		for (int y=0; y<=n; y++) {
			if (x+y == n && x <= b && y <= g) {

				s.insert(x);
			}
		}
	}
	cout << s.size() << '\n';
}