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

	int n, a=0, b=0;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		if (x == 1)
			a++;
		else
			b++;
	}
	int g = min(a, b);
	cout << g + (a-g)/3;
}