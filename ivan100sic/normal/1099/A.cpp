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

	int w, h, u1, d1, u2, d2;
	cin >> w >> h >> u1 >> d1 >> u2 >> d2;
	for (int i=h; i>=0; i--) {
		w += i;
		if (i == d1) {
			w = max(w - u1, 0);
		} else if (i == d2) {
			w = max(w - u2, 0);
		}
	}
	cout << w << '\n';
}