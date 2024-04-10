#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int T;
ll x, y;
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> T;
	while (T--) {
		cin >> x >> y;

		if (x==1) {
			if (y==1) cout << "YES\n";
			else cout << "NO\n";
		}
		else if (x<=3) {
			if (y<=3) cout << "YES\n";
			else cout << "NO\n";
		}
		else cout << "YES\n";
	}

}