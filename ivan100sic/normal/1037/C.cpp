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

	string a, b;
	int n;
	cin >> n >> a >> b;

	int state = 0, c = 0;
	for (int i=0; i<n; i++) {
		if (a[i] != b[i]) {
			if (state == 0)
				state = 1;
			else if (a[i] != a[i-1]) {
				state = 0;
				c++;
			} else {
				c++;
			}
		} else {
			c += state;
			state = 0;
		}
	}
	cout << c + state << '\n';
}