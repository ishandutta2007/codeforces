#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& v : a) cin >> v;
	bool done = false;
	for (int i = 0; i < n; ++i) {
		if (!done && a[i] != i + 1) {
			for (int j = i + 1; j < n; ++j) {
				if (a[j] == i + 1) {
					int ni = j;
					while (j >= i) cout << a[j--] << " ";
					i = ni;
					break;
				}
			}
			done = true;
		}
		else cout << a[i] << " ";
	}
	cout << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}