#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<int> > a(n, vector<int>(m));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	int sum = 0, cnt = 0;

	for (int j = 0; j < m; ++j) {
		vector<int> vct;
		for (int i = 0; i < n; ++i) {
			if (!a[i][j]) {
				continue;
			}
			int c = 0;
			for (int z = i; z < n && z - i + 1 <= k; ++z) {
				if (a[z][j]) {
					++c;
				}
			}
			vct.pb(c);
		}
		if (vct.empty()) {
			continue;
		}
		int best = 0;
		for (int z = 0; z < sz(vct); ++z) {
			if (vct[z] > vct[best]) {
				best = z;
			}
		}
		//cout << j << " " << vct[best] << "\n";
		sum += vct[best];
		cnt += best;
	}

	cout << sum << " " << cnt << "\n";

}