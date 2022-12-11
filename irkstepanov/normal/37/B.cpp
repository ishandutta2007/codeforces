#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

struct data {
	int pow, damag;
	int id;
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	int n, hp, reg;
	cin >> n >> hp >> reg;

	vector<data> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].pow >> v[i].damag;
		v[i].id = i;
	}
	vector<char> used(n, false);

	int d = 0;
	int t = 0;
	int curr = hp;
	vector<pii> ans;
	while (true) {
		curr -= d;
		curr = min(curr + reg, hp);
		if (curr <= 0) {
			break;
		}
		int best = -1;
		for (int i = 0; i < n; ++i) {
			if (used[i]) {
				continue;
			}
			if (100 * curr <= v[i].pow * hp) {
				if (best == -1 || v[best].damag < v[i].damag) {
					best = i;
				}
			}
		}
		if (best == -1 && reg - d >= 0) {
			cout << "NO\n";
			return 0;
		}
		if (best != -1) {
			ans.pb({t, best});
			used[best] = true;
			d += v[best].damag;
		}
		++t;
	}

	cout << "YES\n";
	cout << t << " " << sz(ans) << "\n";
	for (int i = 0; i < sz(ans); ++i) {
		cout << ans[i].first << " " << ans[i].second + 1 << "\n";
	}

}