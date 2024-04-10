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

	int n; string s;
	cin >> n >> s;
	basic_string<int> a;
	int y = 0;
	for (char x : s) {
		if (x == 'B') {
			y++;
		} else {
			if (y)
				a += y;
			y = 0;
		}
	}
	if (y)
		a += y;
	cout << a.size() << '\n';
	for (int x : a)
		cout << x << '\n';
}