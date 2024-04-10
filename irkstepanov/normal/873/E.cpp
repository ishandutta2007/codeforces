#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int rmax = 15;
const int nmax = 100500;

vector<pii> vals;
vector<vector<pii> > sparse;
int deg[nmax];

pii get(int l, int r) {
	int len = r - l + 1;
	int k = deg[len];
	return max(sparse[l][k], sparse[l + len - (1 << k)][k]);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	int n;
	cin >> n;

	vector<int> x(n);
	vector<pii> a;
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
		a.pb({x[i], i});
	}
	sort(all(a));

	vals.pb({a[0].first, 0});
	for (int i = 1; i < n; ++i) {
		vals.pb({a[i]. first - a[i - 1].first, i});
	}

	sparse = vector<vector<pii> >(n, vector<pii>(rmax));
	for (int i = 0; i < n; ++i) {
		sparse[i][0] = vals[i];
	}
	for (int r = 0; r + 1 < rmax; ++r) {
		for (int i = 0; i < n; ++i) {
			int t = min(i + (1 << r), n - 1);
			sparse[i][r + 1] = max(sparse[i][r], sparse[t][r]);
		}
	}

	deg[0] = -1;
	for (int i = 1; i < nmax; ++i) {
		deg[i] = deg[i - 1];
		if (!(i & (i - 1))) {
			++deg[i];
		}
	}

	int bestx = -1, besty = -1, bestz = -1;
	int besti, bestj, bestk;

	for (int i = n - 1; i >= 0; --i) {
		for (int j = i - 1; j >= 0; --j) {
			int lena = n - 1 - i + 1;
			int lenb = i - 1 - j + 1;
			if (lena > 2 * lenb || lenb > 2 * lena) {
				continue;
			}
			int minlen = max({1, (lena + 1) / 2, (lenb + 1) / 2});
			int maxlen = min({j, 2 * lena, 2 * lenb});
			if (minlen > maxlen) {
				continue;
			}
			pii p = get(j - maxlen, j - minlen);
			/*if (i == n - 1 && j == n - 2) {
				cout << p.first << " " << p.second << "\n";
			}*/
			if ((a[i].first - a[i - 1].first > bestx) || (a[i].first - a[i - 1].first == bestx && 
				(a[j].first - a[j - 1].first > besty || (a[j].first - a[j - 1].first == besty && p.first > bestz)))) {
				bestx = a[i].first - a[i - 1].first;
				besty = a[j].first - a[j - 1].first;
				bestz = p.first;
				besti = i, bestj = j, bestk = p.second;
			}
		}
	}

	vector<int> ans(n);
	for (int i = 0; i < bestk; ++i) {
		ans[a[i].second] = -1;
	}
	for (int i = bestk; i < bestj; ++i) {
		ans[a[i].second] = 3;
	}
	for (int i = bestj; i < besti; ++i) {
		ans[a[i].second] = 2;
	}
	for (int i = besti; i < n; ++i) {
		ans[a[i].second] = 1;
	}

	for (int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";

}