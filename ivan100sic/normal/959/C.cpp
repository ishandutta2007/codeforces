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

	int n;
	cin >> n;
	if (n < 6) {
		cout << "-1\n";
	} else {
		for (int i=2; i<=n/2+1; i++)
			cout << "1 " << i << '\n';
		for (int i=n/2+2; i<=n; i++)
			cout << "2 " << i << '\n';
	}

	for (int i=1; i<n; i++)
		cout << i << " " << i+1 << '\n';
}