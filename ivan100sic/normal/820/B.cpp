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

	int n, a;
	cin >> n >> a;

	// 180/n do 180/n * (n-2)

	// broj iz [1, n-2] tako da je sto blize 180/n * i, a
	// i ~ an / 180

	int idx = (a*n + 90) / 180;
	if (idx < 1)
		idx = 1;
	else if (idx > n-2)
		idx = n-2;

	cout << n << ' ' << n-1 << ' ' << idx << '\n';
}