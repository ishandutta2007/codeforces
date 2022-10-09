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

	int n, z=0, w=123123123;
	cin >> n;
	for (int i=0; i<7; i++) {
		int y=0;
		for (int j=0; j<n; j++)
			if ((i+j)%7 < 2) y++;
		z = max(z, y);
		w = min(w, y);
	}
	cout << w << ' ' << z << '\n';
}