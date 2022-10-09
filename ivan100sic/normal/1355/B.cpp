// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[300005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; i++)
			cin >> a[i];
		sort(a, a+n);
		int c = 0, l = 0;
		while (l < n) {
			int r = l;
			while (r < n && r-l+1 < a[r])
				r++;
			if (r < n) {
				c++;
				l = r+1;
			} else {
				break;
			}
		}
		cout << c << '\n';
	}
}