#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int SITO_MAX = 3000000;

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

int n;
int c[3000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<2*n; i++) {
		int x;
		cin >> x;
		c[x]++;
	}

	for (int i=3000000-1; i>=4; i--) {
		if (f[i] != i) {
			while (c[i] > 0) {
				cout << i << ' ';
				c[i]--;
				c[i / f[i]]--;
			}
		}
	}

	for (int i=2; i<3000000; i++) {
		while (c[i] > 0) {
			c[i]--;
			cout << i << ' ';
			c[prosti[i-1]]--;
		}
	}
	cout << '\n';
}