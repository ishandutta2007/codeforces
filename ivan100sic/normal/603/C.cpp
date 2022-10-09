#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int solve(int x) {
	if (x < 8)
		return "01012020"[x] - '0';
	if (x % 2)
		return 0;
	int b = solve(x/2);
	if (b == 0)
		return 1;
	else return 3 - b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k;
	cin >> n >> k;

	int z = 0;
	while (n--) {
		int x;
		cin >> x;
		if (k & 1) {
			z ^= solve(x);
		} else {
			z ^= x <= 3 ? x % 3 : (x+1) % 2;
		}
	}

	cout << (z ? "Kevin\n" : "Nicky\n");
}