#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

mt19937 rr(random_device{}());

const int sigma = 26;

int main()
{

    //ifstream cin("input.txt");
	//ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<pii> v[26];
	int start = 0;
	for (int i = 1; i <= n; ++i) {
		if (i == n || s[i] != s[i - 1]) {
			v[s[i - 1] - 'a'].pb({start, i - 1});
			start = i;
		}
	}

	int q;
	cin >> q;

	while (q--) {
		int k;
		char c;
		cin >> k >> c;
		int x = c - 'a';
		int ans = 0;
		int rg = -1;
		int rem = k;
		int curr = 0;
		if (v[x].empty()) {
			cout << min(k, n) << "\n";
			continue;
		}
		for (int lf = 0; lf < sz(v[x]); ++lf) {
			if (lf) {
				curr -= v[x][lf - 1].second - v[x][lf - 1].first + 1;
				rem += v[x][lf].first - v[x][lf - 1].second - 1;
			}
			if (rg < lf) {
				rg = lf;
				curr = v[x][lf].second - v[x][lf].first + 1;
				rem = k;
			}
			while (rg + 1 < sz(v[x]) && v[x][rg + 1].first - v[x][rg].second - 1 <= rem) {
				rem -= v[x][rg + 1].first - v[x][rg].second - 1;
				++rg;
				curr += v[x][rg].second - v[x][rg].first + 1;
			}
			int res = min(curr + k, n);
			ans = max(ans, res);
		}
		cout << ans << "\n";
	}

}