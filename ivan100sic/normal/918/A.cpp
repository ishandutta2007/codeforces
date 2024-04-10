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

	set<int> fib;
	{
		int x = 0, y = 1;
		while (x < 123123) {
			int z = x + y;
			fib.insert(x);
			x = y;
			y = z;
		}
	}

	for (int i=1; i<=n; i++)
		if (fib.count(i))
			cout << 'O';
		else
			cout << 'o';
	cout << '\n';
}