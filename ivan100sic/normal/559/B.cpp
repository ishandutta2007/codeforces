#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool eq(string a, string b) {
	if (a == b)
		return true;
	int n = a.size();

	if (n % 2 == 0) {
		string a1 = a.substr(0, n/2);
		string a2 = a.substr(n/2);

		string b1 = b.substr(0, n/2);
		string b2 = b.substr(n/2);

		if (rand() % 2)
			swap(a1, a2);
		if (rand() % 2)
			swap(b1, b2);

		return (eq(a1, b1) && eq(a2, b2)) ||
			(eq(a1, b2) && eq(a2, b1));
	} else {
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string a, b;
	cin >> a >> b;
	cout << (eq(a, b) ? "YES\n" : "NO\n");
}