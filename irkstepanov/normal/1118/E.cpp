#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	if (ll(k) * (k - 1) < n) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for (int d = 1; ; ++d) {
		for (int i = 1; i <= k; ++i) {
			cout << i << " ";
			int j = i + d;
			if (j > k) {
				j -= k;
			}
			cout << j << "\n";
			--n;
			if (n == 0) {
				return 0;
			}
		}
	}
	
}