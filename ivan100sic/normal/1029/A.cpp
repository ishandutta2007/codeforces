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

	int n, k;
	string s;
	cin >> n >> k >> s;

	string p = s;

	// nadji sufiks-prefiks
	int sp = -1;
	for (int i=n-1; i>=0; i--) {
		if (s.substr(n-i) == s.substr(0, i)) {
			sp = i;
			break;
		}
	}

	for (int i=1; i<k; i++)
		p += s.substr(sp);

	cout << p;
}