#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int SITO_MAX = 300000;

int f[SITO_MAX+1];
vector<int> prosti;

struct sito {
	sito() {
		for (int i=2; i<=SITO_MAX; i++) {
			if (f[i] == 0) {
				f[i] = i;
				prosti.push_back(i);
			}
			int j = 0;
			while (j < (int)prosti.size()) {
				if (prosti[j] > f[i]) {
					break;
				}
				int x = i * prosti[j];
				if (x > SITO_MAX) {
					break;
				}
				f[x] = prosti[j];
				j++;
			}
		}
	}
} sito_obj_983431;

int F(int n) {
	int x = 0;
	for (int i=1; i<=n; i++)
		x += n/i-1;
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k;
	cin >> n >> k;

	if (k > F(n)) {
		cout << "No\n";
		return 0;
	}

	int l = 0, r = n, o = n;
	while (l <= r) {
		int m = (l+r) / 2;
		if (F(m) >= k) {
			o = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}

	int fo = F(o), j = 0;
	string skip(o+2, 0);
	vector<pair<int, int>> rm;
	for (int i=2; i<=o; i++)
		if (f[i] == i && o/i <= fo - k)
			fo -= o/i, skip[i] = 1, j++;

	cout << "Yes\n" << o-j << '\n';
	for (int i=1; i<=o; i++)
		if (!skip[i])
			cout << i << ' ';
	cout << '\n';
}