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

	int last = 0;
	int n, z=0;
	cin >> n;
	string s;
	cin >> s;
	int d = 0;
	for (char x : s) {
		if (x == 'U')
			d++;
		else
			d--;
		if (d * 1ll * last < 0) {
			z++;
			last = d;
		} else if (d != 0) {
			last = d;
		}
	}
	cout << z << '\n';
}