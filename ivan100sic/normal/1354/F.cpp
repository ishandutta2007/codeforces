// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct minion {
	int a, b, id;

	bool operator< (const minion& b) const {
		return this->b < b.b;
	}
} a[80];

int n, k;
int dp[80][80];
int wut[80][80];

template<class T>
void mx(int& x, int y, T z) {
	if (y > x) {
		x = y;
		z();
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i=0; i<n; i++)
			cin >> a[i].a >> a[i].b, a[i].id = i + 1;
		sort(a, a+n);

		memset(dp, 192, sizeof dp);
		dp[0][0] = 0;

		for (int i=0; i<n; i++) {
			for (int j=0; j<=i; j++) {
				// head?
				mx(dp[i+1][j+1], dp[i][j] + a[i].a + j * a[i].b, [=]() { wut[i+1][j+1] = 1; });
				// non-head
				mx(dp[i+1][j], dp[i][j] + a[i].b * (k-1), [=]() { wut[i+1][j] = 0; });
			}
		}

		int j = k;
		vector<int> sol, heads, nonheads;

		for (int i=n; i>0; i--) {
			if (wut[i][j] == 1) {
				heads.push_back(i-1);
				j -= 1;
			} else {
				nonheads.push_back(i-1);
			}
		}

		for (int i=heads.size()-1; i; i--)
			sol.push_back(a[heads[i]].id);
		int spot = 0;
		for (int x : nonheads) {
			x = a[x].id;
			if (spot == 0) {
				spot = x;
				sol.push_back(x);
			} else {
				sol.push_back(-spot);
				sol.push_back(x);
				spot = x;
			}
		}

		if (spot != 0) {
			sol.push_back(-spot);
		}
		sol.push_back(a[heads[0]].id);

		cout << sol.size() << '\n';
		for (int x : sol)
			cout << x << ' ';
		cout << '\n';
	}
}