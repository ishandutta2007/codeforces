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

	int a=0, b=0, c=0, d=0, n, m;
	cin >> n >> m;
	while (n--) {
		int x;
		cin >> x;
		(x%2?a:b)++;
	}
	while (m--) {
		int x;
		cin >> x;
		(x%2?c:d)++;
	}
	cout << min(a, d) + min(b, c) << '\n';

}