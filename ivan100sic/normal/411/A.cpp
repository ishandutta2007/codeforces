// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	string t;
	cin >> t;

	int l=0, s=0, d=0;
	for (char c : t) {
		l += isupper(c);
		s += islower(c);
		d += isdigit(c);
	}

	cout << (t.size() >= 5 && l && s && d ? "Correct\n" : "Too weak\n");
}