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
	int a = n/2;
	int b = n-a;
	cout << a*b << '\n';
	for (int i=1; i<=a; i++) {
		for (int j=a+1; j<=n; j++) {
			cout << i << ' ' << j << '\n';
		}
	}
}