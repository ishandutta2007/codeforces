#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int nmax = 400;

bitset<nmax> x[nmax][nmax][26];

int main()
{

	//ifstream cin("input.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int r, c;
	cin >> r >> c;
	vector<string> b(r);
	for (int i = 0; i < r; ++i) {
		cin >> b[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int shift = 0; shift < c; ++shift) {
			for (int j = 0; j < m; ++j) {
				x[i][shift][a[i][(j + shift) % m] - 'a'][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		bitset<nmax> ans;
		ans.set();
		for (int p = 0; p < r; ++p) {
			int row = (i + p) % n;
			for (int q = 0; q < c; ++q) {
				if (b[p][q] == '?') {
					continue;
				}
				ans &= x[row][q][b[p][q] - 'a'];
			}
		}
		for (int j = 0; j < m; ++j) {
			cout << ans[j];
		}
		cout << "\n";
	}

}