// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n, sol = 0, stab = -1;
	ll z = 0;
	map<ll, int> last;

	cin >> n;

	last[0] = 0;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		z += x;
		auto it = last.find(z);
		if (it != last.end()) {
			int l = it->second+1, r = i-1;
			if (l > stab) {
				sol++;
				stab = r;
			}
		}
		last[z] = i;
	}

	cout << sol << '\n';
}