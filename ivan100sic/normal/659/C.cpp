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

	set<int> s;
	basic_string<int> u;
	int n, k;
	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		s.insert(x);
	}
	int z = 0;
	for (int i=1; i<=2000000; i++) {
		if (i <= k && s.count(i) == 0) {
			k -= i;
			u += i;
			z++;
		}
	}
	cout << z << '\n';
	for (int x : u)
		cout << x << ' ';
	cout << '\n';
}