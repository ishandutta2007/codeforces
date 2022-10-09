#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


const int SITO_MAX = 2000000;

int f[SITO_MAX+1];
int c[SITO_MAX+1];
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

int n, x;
int a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, x;
	cin >> n >> x;
	for (int i=0; i<n; i++)
		cin >> a[i];

	if (x == 2) {
		cout << "0\n";
		return 0;
	}

	if (count(a, a+n, 1)) {
		cout << "1\n";
		return 0;
	}

	if (x > SITO_MAX) {
		cout << "-1\n";
		return 0;
	}

	int y = 0;
	// treba pokriti sve proste brojeve od 2 do x
	for (int i=0; i<n; i++) {
		int z = a[i];
		if (z < x && z >= 2 && c[z] == 0 && f[z] == z) {
			c[z] = 1;
			y++;
		}
	}
	int yy = 0;
	for (int i=2; i<x; i++) {
		if (f[i] == i)
			yy++;
	}
	if (y != yy) {
		cout << "-1\n";
	} else {
		cout << y << '\n';
	}
}