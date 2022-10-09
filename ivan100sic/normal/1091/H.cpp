#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int SITO_MAX = 200000;

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

int mv[SITO_MAX+1];

vector<int> calc_dp_fast(int HI) {
	vector<int> dp(HI+1, 0);
	bitset<200032> mvmask, prefixor, aold, anu;
	for (int i=0; i<=HI; i++)
		if (mv[i])
			mvmask[i] = 1;

	for (int i=0; i<=HI; i++)
		aold[i] = 1;
	int i = 0;
	while (1) {
		if (aold.count() == 0)
			break;
		for (int j=0; j<=HI; j++) {
			if (aold[j]) {
				// ako ti jesi onda markiraj ove da nisu
				aold &= ~(mvmask << j);
				dp[j] = i;
			}
		}
		prefixor |= aold;
		anu = ~prefixor;
		swap(aold, anu);
		i++;
	}
	return dp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=2; i<=SITO_MAX; i++)
		if (f[i] == i || f[i / f[i]] == i / f[i])
			mv[i] = 1;
	int n, f;
	cin >> n >> f;
	mv[f] = 0;

	auto v = calc_dp_fast(SITO_MAX);
	int w = 0;

	while (n--) {
		int x, y, z;
		cin >> x >> y >> z;
		w ^= v[y-x-1] ^ v[z-y-1];
	}

	if (w)
		cout << "Alice\nBob\n";
	else
		cout << "Bob\nAlice\n";
}