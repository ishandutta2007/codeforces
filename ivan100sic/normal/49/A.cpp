#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool isvowel(char x) {
	return string("aeiouy").find(x) != string::npos;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	getline(cin, s);
	int v = 0;
	for (char x : s) {
		x = tolower(x);
		if (islower(x)) {
			v = isvowel(x);
		}
	}
	cout << (v ? "YES\n" : "NO\n");
}