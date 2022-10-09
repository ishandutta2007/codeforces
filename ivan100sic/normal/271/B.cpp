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

int n, m;
int a[505][505];
int g[110005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=110000; i>=0; i--) {
		g[i] = g[i+1] + 1;
		if (f[i] == i)
			g[i] = 0;
	}

	cin >> n >> m;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cin >> a[i][j];

	int o = 1123123123;

	for (int i=0; i<n; i++) {
		int z = 0;
		for (int j=0; j<m; j++)
			z += g[a[i][j]];
		o = min(o, z);
	}

	for (int j=0; j<m; j++) {
		int z = 0;
		for (int i=0; i<n; i++)
			z += g[a[i][j]];
		o = min(o, z);
	}

	cout << o << '\n';

}