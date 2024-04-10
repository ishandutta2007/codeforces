#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int t[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int a, b, m, r0;
	cin >> a >> b >> m >> r0;
	int r = r0;
	for (int i=1;; i++) {
		if (t[r])
			return cout << i - t[r], 0;
		else
			t[r] = i;
		r = (a*1ll*r + b) % m;
	}
}