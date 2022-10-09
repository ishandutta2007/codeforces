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

	string a, b, c;
	map<char, char> m;
	cin >> a >> b >> c;
	for (int i=0; i<26; i++)
		m[a[i]] = b[i];
	for (char x : c) {
		if (islower(x))
			cout << m[x];
		else if (isupper(x))
			cout << (char)toupper(m[tolower(x)]);
		else
			cout << x;
	}
	cout << '\n';
}