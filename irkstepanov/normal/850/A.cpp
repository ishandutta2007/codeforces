#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int dot(const vector<int>& a, const vector<int>& b, const vector<int>& c) {
	int ans = 0;
	for (int i = 0; i < 5; ++i) {
		ans += (b[i] - a[i]) * (c[i] - a[i]);
	}
	return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

	int n;
	cin >> n;

	vector<vector<int> > x(n, vector<int>(5));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> x[i][j];
		}
	}

	if (n <= 500) {
		vector<int> good;
		for (int i = 0; i < n; ++i) {
			bool ok = true;
			for (int j = 0; j < n; ++j) {
				if (i == j) {
					continue;
				}
				for (int k = 0; k < n; ++k) {
					if (k == i || k == j) {
						continue;
					}
					if (dot(x[i], x[j], x[k]) > 0) {
						ok = false;
						break;
					}
				}
				if (!ok) {
					break;
				}
			}
			if (ok) {
				good.pb(i);
			}
		}
		cout << sz(good) << "\n";
		for (int i = 0; i < sz(good); ++i) {
			cout << good[i] + 1 << "\n";
		}
		return 0;
	}
	cout << "0\n";

}