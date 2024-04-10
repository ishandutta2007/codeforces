// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	string a, b, c;
	cin >> a >> b >> c;
	a += b + c;
	b = a;
	reverse(begin(b), end(b));
	cout << (a == b ? "YES\n" : "NO\n");
}