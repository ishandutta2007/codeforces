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

	int n, a=0, b=0;
	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		a |= x;
	}
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		b |= x;
	}

	cout << a + b << '\n';

}