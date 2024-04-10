#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int SITO_MAX = 110000;

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

int a[5][5];

void put(int x, int k, int row) {
	for (int i=k-1; i>=0; i--) {
		a[row][i] = x % 10;
		x /= 10;
	}
}

/*
abcde
pqrst
CR???
?????
?????
*/

int z;
int pow10v[6] = {1, 10, 100, 1000, 10000, 100000};
vector<int>::iterator lbs[110000];

void rek(int k, int h) {
	if (h == k) {
		z++;
		return;
	}

	int vcol = 0;
	for (int i=0; i<k; i++) {
		vcol = 10 * vcol + (i < h ? a[i][h] : 0);
	}
	int vcolhi = vcol + pow10v[k-h];

	auto it = lbs[vcol];
	while (*it < vcolhi) {
		put(*it, k, h);
		rek(k, h+1);
		++it;
	}
}

map<string, int> ans_cache;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;

	for (int i=0; i<SITO_MAX; i++)
		lbs[i] = lower_bound(prosti.begin(), prosti.end(), i);

	while (t--) {
		string s;
		cin >> s;
		int k = s.size();
		int p0 = stoi(s);
		put(p0, k, 0);
		if (ans_cache.count(s)) {
			cout << ans_cache[s] << '\n';
		} else {
			z = 0;
			rek(k, 1);
			cout << z << '\n';
			ans_cache[s] = z;
		}
			
	}
}