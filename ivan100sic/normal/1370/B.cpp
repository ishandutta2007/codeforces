// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		basic_string<int> e, o;
		for (int i=1; i<=2*n; i++) {
			int x;
			cin >> x;
			(x % 2 ? o : e) += i;
		}

		int l = n-1;
		for (int i=0; i+1<(int)e.size() && l; i+=2, l--) {
			cout << e[i] << ' ' << e[i+1] << '\n';
		}
		for (int i=0; i+1<(int)o.size() && l; i+=2, l--) {
			cout << o[i] << ' ' << o[i+1] << '\n';
		}
	}
}