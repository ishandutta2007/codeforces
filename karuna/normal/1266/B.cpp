#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int T;
ll x;
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> T;
	while (T--) {
		cin >> x;

		if (x<=14) cout << "NO\n";
		else {
			if (x%14 <= 6 && x%14 >= 1) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}