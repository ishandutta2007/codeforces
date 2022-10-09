#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[200005];
int b[200005];

void mx(int& x, int y) {
	x = max(x, y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i=0; i<n; i++)
			cin >> a[i];
		fill(b+1, b+n+1, 0);
		cin >> m;
		for (int i=0; i<m; i++) {
			int p, s;
			cin >> p >> s;
			mx(b[s], p);
		}
		for (int i=n-1; i>=1; i--)
			mx(b[i], b[i+1]);

		int p = 0, ans = 0;
		while (p != n) {
			int k = 0, h = 0;
			while (p+k < n && max(h, a[p+k]) <= b[k+1])
				mx(h, a[p+k]), k++;
			if (k == 0) {
				ans = -1;
				break;
			} else {
				p += k;
				ans++;
			}
		}

		cout << ans << '\n';
	}	
}