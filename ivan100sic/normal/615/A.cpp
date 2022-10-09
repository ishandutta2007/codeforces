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

	set<int> s;
	int n, m;
	cin >> n >> m;
	while (n--) {
		int x;
		cin >> x;
		while (x--) {
			int y;
			cin >> y;
			s.insert(y);
		}
	}
	cout << ((int)s.size() == m ? "YES\n" : "NO\n");
}