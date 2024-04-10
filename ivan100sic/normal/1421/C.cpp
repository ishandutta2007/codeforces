// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	string s;
	cin >> s;
	int n = s.size();
	cout << "3\n";
	cout << "R 2\n";
	cout << "L " << n << '\n';
	cout << "L " << n-1 << '\n';
}