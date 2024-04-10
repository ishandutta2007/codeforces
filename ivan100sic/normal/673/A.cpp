#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		a[x] = 1;
	}
	int b = 0;
	for (int i=1; i<=90; i++) {
		if (!a[i])
			b++;
		else
			b = 0;
		if (b == 15) {
			cout << i;
			return 0;
		}
	}
	cout << 90;
}