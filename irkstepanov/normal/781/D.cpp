#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int nmax = 510;

typedef vector<bitset<nmax> > matrix;

int n;

matrix glue(const matrix& a, const matrix& b)
{
	matrix ans(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[i][j]) {
				ans[i] |= b[j];
			}
		}
	}
	return ans;
}

const int rmax = 64;
const ll inf = 1e18;

bool bit(ll mask, int pos)
{
	return (mask >> pos) & 1;
}

bitset<nmax> operator*(const matrix& a, const bitset<nmax>& b)
{
	bitset<nmax> ans;
	for (int i = 0; i < n; ++i) {
		if (b[i]) {
			ans |= a[i];
		}
	}
	return ans;
}

int main()
{

	//ifstream cin("strictly-off.in");
	//ofstream cout("strictly-off.out");
	//freopen("input.txt", "r", stdin);
	//freopen("threed.out", "w", stdout);
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int edges;
	cin >> n >> edges;

	matrix odd(n), even(n);
	while (edges--) {
		int u, v, t;
		cin >> u >> v >> t;
		--u, --v;
		if (t == 0) {
			even[u][v] = 1;
		} else {
			odd[u][v] = 1;
		}
	}

	vector<matrix> m(rmax), antim(rmax);
	m[0] = even;
	antim[0] = odd;

	for (int r = 1; r < rmax; ++r) {
		m[r] = glue(m[r - 1], antim[r - 1]);
		antim[r] = glue(antim[r - 1], m[r - 1]);
	}

	/*for (int i = 0; i < n; ++i) {
		cout << m[1][i] << "\n";
	}
	cout << "\n";
	for (int i = 0; i < n; ++i) {
		cout << antim[1][i] << "\n";
	}
	cout << "\n";*/

	ll lf = 0, rg = inf + 2;
	//ll lf = 2, rg = 5;

	while (rg - lf > 1) {
		ll md = (lf + rg) >> 1;
		bitset<nmax> curr;
		curr[0] = 1;
		int f;
		for (int r = rmax - 1; r >= 0; --r) {
			if (bit(md, r)) {
				f = r;
				break;
			}
		}
		bool rev = false;
		for (int r = f; r >= 0; --r) {
			if (bit(md, r)) {
				if (rev) {
					//cout << "ANTI " << r << "\n";
					curr = antim[r] * curr;
				} else {
					//cout << "NORM " << r << "\n";
					curr = m[r] * curr;
				}
				rev ^= 1;
			}
		}
		if (curr.any()) {
			lf = md;
		} else {
			rg = md;
		}
	}

	if (lf == inf + 1) {
		cout << "-1\n";
	} else {
		cout << lf << "\n";
	}

}