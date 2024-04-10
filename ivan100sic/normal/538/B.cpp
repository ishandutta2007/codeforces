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
	basic_string<int> z;
	while (n > 0) {
		int f = 0;
		for (int i=1; i<=12312312; i*=10) {
			if (n / i % 10) {
				f += i;
			}
		}
		n -= f;
		z += f;
	}
	cout << z.size() << '\n';
	for (int x : z)
		cout << x << ' ';
	cout << '\n';
}