// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n, e=0, o=0, s=0;
		cin >> n;
		while (n--) {
			int x;
			cin >> x;
			(x % 2 ? o : e)++;
			s += x;
		}
		cout << ((e && o) || s % 2 ? "YES\n" : "NO\n");
	}
}