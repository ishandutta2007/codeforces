// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n;
	cin >> n;

	for (int i=n-1, m=1, x=1; i>=0; x += i * m, i--, m*=-1) {
		cout << x << ' ';
	}
	cout << '\n';
}