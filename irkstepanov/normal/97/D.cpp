#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int nmax = 150;

bitset<nmax> b[nmax];
bitset<nmax> f[nmax];
bitset<nmax> wall[nmax];
bitset<nmax> tmp;
int n, m;

int x_exit, y_exit;

bool finish()
{
	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << b[i][j];
		}
		cout << "\n";
	}
	cout << "\n";*/
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += b[i].count();
		if (sum > 1) {
			return false;
		}
	}
	return (sum == 1 && b[x_exit][y_exit] == 1);
}

bitset<nmax> operator-(const bitset<nmax>& a, const bitset<nmax>& b)
{
	bitset<nmax> tmp = (a & b);
	bitset<nmax> ans = a;
	ans ^= tmp;
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

	int k;
	cin >> n >> m >> k;

	vector<vector<char> > t(n, vector<char>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> t[i][j];
			if (t[i][j] == '#') {
				wall[i][j] = 1;
			} else {
				b[i][j] = 1;
			}
			if (t[i][j] == 'E') {
				x_exit = i, y_exit = j;
			}
		}
	}

	string s;
	cin >> s;

	if (finish()) {
		cout << "0\n";
		return 0;
	}

	for (int p = 0; p < k; ++p) {
		if (s[p] == 'L') {
			for (int i = 0; i < n; ++i) {
				b[i] = (b[i] >> 1);
				tmp = (b[i] & wall[i]);
				b[i] ^= tmp;
				b[i] |= (tmp << 1);
			}
		} else if (s[p] == 'R') {
			for (int i = 0; i < n; ++i) {
				b[i] = (b[i] << 1);
				tmp = (b[i] & wall[i]);
				b[i] ^= tmp;
				b[i] |= (tmp >> 1);
			}
		} else if (s[p] == 'D') {
			for (int i = 0; i < n; ++i) {
				f[i].reset();
				if (i) {
					f[i] |= (b[i - 1] - wall[i]);
				}
				if (i + 1 < n) {
					f[i] |= (b[i] & wall[i + 1]);
				}
			}
			for (int i = 0; i < n; ++i) {
				b[i] = f[i];
			}
		} else {
			for (int i = 0; i < n; ++i) {
				f[i].reset();
				if (i + 1 < n) {
					f[i] |= (b[i + 1] - wall[i]);
				}
				if (i) {
					f[i] |= (b[i] & wall[i - 1]);
				}
			}
			for (int i = 0; i < n; ++i) {
				b[i] = f[i];
			}
		}
		if (finish()) {
			cout << p + 1 << "\n";
			return 0;
		}
	}

	cout << "-1\n";

}