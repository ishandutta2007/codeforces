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
		int n;
		cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		int f = 1;
		for (int i=n-2; i>=0; i--) {
			if (a[i] == 1) {
				f ^= 1;
			} else {
				f = 1;
			}
		}
		cout << (f ? "First\n" : "Second\n");
	}
}