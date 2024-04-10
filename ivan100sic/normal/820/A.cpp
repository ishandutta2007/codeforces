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

	int c, v0, v1, a, l;
	cin >> c >> v0 >> v1 >> a >> l;
	int r = 0, prev = -1, sol = 0;
	while (r < c) {
		if (prev == -1) {
			r = v0;
			prev = v0;
			sol++;
		} else {
			int speed = min(v1, prev + a);
			r += speed - l;
			sol++;
			prev = speed;
		}
	}
	cout << sol << '\n';
}