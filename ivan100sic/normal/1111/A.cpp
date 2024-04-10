#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool vowel(char x) {
	return string("aeiou").find(x) != string::npos;
}

void sredi(string& s) {
	for (char& x : s)
		if (vowel(x))
			x = 'a';
		else
			x = 'z';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string a, b;
	cin >> a >> b;
	sredi(a);
	sredi(b);
	cout << (a == b ? "Yes\n" : "No\n");
}