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
		int n, m, a=0, b=0, c=0, d=0;
		cin >> n;
		while (n--) {
			int x;
			cin >> x;
			(x%2 ? a : b)++;
		}
		cin >> m;
		while (m--) {
			int x;
			cin >> x;
			(x%2 ? c : d)++;
		}
		cout << 1ll*a*c + 1ll*b*d << '\n';
	}
}