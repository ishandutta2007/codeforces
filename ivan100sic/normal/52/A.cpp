// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int c[4];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		c[x]++;
	}

	cout << c[1] + c[2] + c[3] - *max_element(c+1, c+4) << '\n';
}