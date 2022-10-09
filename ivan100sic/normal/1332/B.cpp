// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


const int SITO_MAX = 100000;

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n), b;
		for (int& x : a) {
			cin >> x;
			x = lower_bound(prosti.begin(), prosti.end(), f[x]) - prosti.begin();
			b.push_back(x);
		}
		sort(begin(b), end(b));
		b.erase(unique(begin(b), end(b)), end(b));
		cout << b.size() << '\n';
		for (int x : a) {
			cout << lower_bound(begin(b), end(b), x) - begin(b) + 1 << ' ';
		}
		cout << '\n';
	}
}

// I will still practice daily...