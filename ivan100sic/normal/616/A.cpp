// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	string a, b;
	cin >> a >> b;
	a = string(1231231 - a.size(), '0') + a;
	b = string(1231231 - b.size(), '0') + b;
	if (a < b) cout << '<';
	else if (a > b) cout << '>';
	else cout << '=';
	cout << '\n';
}