#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string sd(string s) {
	int z = 0;
	for (char x : s) {
		z += x - '0';
	}
	return to_string(z);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	int z = 0;
	while (s.size() > 1) {
		s = sd(s);
		z++;
	}
	cout << z << '\n';
}