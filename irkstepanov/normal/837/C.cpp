#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");
	//freopen("input.txt", "r", stdin);
	//ofstream cout("output.txt");
	
	int n, a, b;
	cin >> n >> a >> b;

	vector<int> x(n), y(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			for (int ii = 0; ii < 2; ++ii) {
				for (int jj = 0; jj < 2; ++jj) {
					int x1 = x[i], y1 = y[i], x2 = x[j], y2 = y[j];
					if (ii) {
						swap(x1, y1);
					}
					if (jj) {
						swap(x2, y2);
					}
					if (max(x1, x2) <= a && y1 + y2 <= b) {
						ans = max(ans, x1 * y1 + x2 * y2);
						continue;
					}	
					if (max(y1, y2) <= b && x1 + x2 <= a) {
						ans = max(ans, x1 * y1 + x2 * y2);
					}
				}
			}
		}
	}

	cout << ans << "\n";
	
}