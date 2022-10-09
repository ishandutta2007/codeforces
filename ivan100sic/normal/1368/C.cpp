// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int x;
	cin >> x;

	cout << 4+3*x << '\n';
	cout << "0 0\n0 1\n1 0\n1 1\n";
	for (int i=0; i<x; i++) {
		cout << 2+i << ' ' << 2+i << '\n';
		cout << 2+i << ' ' << 1+i << '\n';
		cout << 1+i << ' ' << 2+i << '\n';
	}
}