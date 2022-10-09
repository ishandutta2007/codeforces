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

	int n, x, y, z=0;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	for (int i=0; i<x; i++) {
		z += (s[i] - '0') != (i == y);
	}
	cout << z << '\n';
}