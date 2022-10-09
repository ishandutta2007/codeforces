#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int B = 320;
const int H = 320;

int n, m, q;
ll a[100005];
vector<int> s[100005], big;
int bigid[100005];
ll biga[H], bigs[H];
int _[100005];
int presek[100005][H];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> q;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<=m; i++) {
		int k;
		cin >> k;
		s[i].resize(k);
		for (int& x : s[i])
			cin >> x;
		sort(s[i].begin(), s[i].end());
		if (k > B) {
			int id = bigid[i] = big.size();
			big.push_back(i);
			for (int j : s[i])
				biga[id] += a[j];
		} else {
			bigid[i] = -1;
		}
	}

	for (int i=0; i<(int)big.size(); i++) {
		for (int j : s[big[i]])
			_[j]++;

		for (int j=1; j<=n; j++) {
			int x = 0;
			for (int y : s[j])
				x += _[y];
			presek[j][i] = x;
		}

		for (int j : s[big[i]])
			_[j] = 0;
	}

	while (q--) {
		char t;
		cin >> t;
		if (t == '?') {
			int k;
			cin >> k;
			if (bigid[k] == -1) {
				ll z = 0;
				for (int j : s[k])
					z += a[j];
				for (int j=0; j<(int)big.size(); j++)
					z += bigs[j] * 1ll * presek[k][j];
				cout << z << '\n';
			} else {
				cout << biga[bigid[k]] << '\n';
			}

		} else {
			int k, x;
			cin >> k >> x;
			for (int j=0; j<(int)big.size(); j++) {
				biga[j] += x * 1ll * presek[k][j];
			}

			if (bigid[k] == -1) {
				for (int j : s[k]) {
					a[j] += x;
				}
			} else {
				bigs[bigid[k]] += x;
			}
		}
	}
}