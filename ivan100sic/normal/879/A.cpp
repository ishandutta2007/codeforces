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

	int n;
	cin >> n;
	int x = 0;
	while (n--) {
		x++;
		int s, d;
		cin >> s >> d;
		if (x < s)
			x = s;
		else
			while ((x-s) % d)
				x++;
	}
	cout << x << '\n';
}