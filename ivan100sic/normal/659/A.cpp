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

	int n, a, b;
	cin >> n >> a >> b;
	a--;
	a += b;
	cout << (a % n + n) % n + 1 << '\n';
}