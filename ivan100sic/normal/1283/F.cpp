#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int p[200005], a[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++)
		cin >> a[i];

	fill(p+1, p+n+1, -1);

	int j = 1;
	int curr = 0;
	for (int i=n; i>=1; i--) {
		while (p[i] == -1) {
			int x = a[j++];
			if (p[x] != -1) {
				p[i] = curr;
				curr = x;
			} else if (x == i) {
				p[x] = curr;
				curr = x;
			} else {
				p[x] = curr;
				curr = x;
			}
		}
	}
	cout << a[1] << '\n';
	for (int i=1; i<=n; i++)
		if (i != a[1])
			cout << i << ' ' << p[i] << '\n';
}