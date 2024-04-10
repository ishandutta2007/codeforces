#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t, st, in, xp;
int main() {
	cin >> t;
	while (t--) {
		cin >> st >> in >> xp;

		if (in+xp-st<0) cout << max(0, xp+1);
		else if ((in+xp-st)%2==0) cout << max(0, xp-(in+xp-st)/2);
		else cout << max(0, xp-(in+xp-st)/2);
		cout << '\n';
	}
}