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

	int x;
	cin >> x;
	for (int a=5; a<=x; a++) {
		if (x % a)
			continue;
		int b = x/a;
		if (b >= 5) {
			for (int i=0; i<a; i++)
				for (int j=0; j<b; j++)
					cout << "aeiou"[(i+j) % 5];
			cout << '\n';
			return 0;
		}
	}
	cout << "-1\n";
}