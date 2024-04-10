#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t, a, b, n;
int main() {
	cin >> t;
	while (t--) {
		cin >> a >> b >> n;
		n%=3;

		if (n%3==0) cout << a << '\n';
		if (n%3==1) cout << b << '\n';
		if (n%3==2) cout << (a^b) << '\n';
	}
}