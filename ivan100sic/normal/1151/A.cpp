#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int dist(char x, char y) {
	int d = abs((int)x - y);
	if (d < 13)
		return d;
	return 26-d;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, f=123123123;
	string s;
	cin >> n >> s;
	for (int i=0; i<=n-4; i++) {
		int z = 0;
		for (int j=0; j<4; j++) {
			z += dist("ACTG"[j], s[i+j]);
		}
		f = min(f, z);
	}
	cout << f << '\n';
}