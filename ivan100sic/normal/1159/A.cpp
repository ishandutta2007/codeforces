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
	string s;
	cin >> n >> s;
	int l = 0, z = 0;
	for (char x : s) {
		if (x == '+') {
			z++;
		} else {
			z--;
		}
		l = min(l, z);
	}
	cout << z-l << '\n';
}