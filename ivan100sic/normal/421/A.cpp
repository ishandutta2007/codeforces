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

	int n, a, b;
	set<int> u, v;
	cin >> n >> a >> b;
	while (a--) {
		int x;
		cin >> x;
		u.insert(x);
	}
	while (b--) {
		int x;
		cin >> x;
		v.insert(x);
	}
	for (int i=1; i<=n; i++) {
		if (u.count(i))
			cout << "1 ";
		else
			cout << "2 ";
	}
}