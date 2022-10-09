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

	int n, m;
	cin >> n >> m;
	int x = min(n, m);
	cout << x+1 << '\n';
	for (int i=0; i<=x; i++)
		cout << i << ' ' << x-i << '\n';
}