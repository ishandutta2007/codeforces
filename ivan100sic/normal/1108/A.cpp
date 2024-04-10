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

	int q;
	cin >> q;
	while (q--) {
		int x, y, z, t;
		cin >> x >> y >> z >> t;
		for (int a=x; a<=y; a++) {
			for (int b=z; b<=t; b++) {
				if (a != b) {
					cout << a << ' ' << b << '\n';
					a = y+1;
					b = t+1;
					break;
				}
			}
		}
	}
	
}