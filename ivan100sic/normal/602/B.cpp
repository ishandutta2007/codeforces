#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005];

int c[100005], sz;
void add(int x) {
	if (1 == ++c[x])
		++sz;
}
void rem(int x) {
	if (0 == --c[x])
		--sz;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	int r = 0, sol = 0;
	for (int i=1; i<=n; i++) {
		while (r+1 <= n) {
			add(a[r+1]);
			if (sz == 3) {
				rem(a[r+1]);
				break;
			} else {
				r++;
			}
		}
		sol = max(sol, r-i+1);
		rem(a[i]);
	}
	cout << sol << '\n';
}