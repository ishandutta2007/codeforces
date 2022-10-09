#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int last = 0, v = 0;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		if (x == last) {
			v++;
		} else {
			b += v;
			v = 1;
		}
		last = x;
	}
	b += v;
	int sol = 0;
	for (int i=0; i<(int)b.size()-1; i++) {
		sol = max(sol, min(b[i], b[i+1]));
	}
	cout << sol*2 << '\n';
}