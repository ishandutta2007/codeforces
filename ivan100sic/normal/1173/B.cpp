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
	cout << n/2+1 << '\n';
	int x=1, y=1;
	for (int i=0; i<n; i++) {
		cout << x << ' ' << y << '\n';
		if (x == y)
			x++;
		else
			y++;
	}
	
}