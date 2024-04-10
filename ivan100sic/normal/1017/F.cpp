#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int ui;

const int SITO_MAX = 20000;

int f[SITO_MAX+1];
vector<int> prosti;

bool sito_buff[8388608];

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

ui n;
ui a, b, c, d;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> a >> b >> c >> d;

	ui sol = 0;

	// resi za male proste
	for (ui p : prosti) {
		ui z = 0, t = n;
		while (t > 0) {
			t /= p;
			z += t;
		}
		sol += (a*p*p*p + b*p*p + c*p + d) * z;
	}

	// resi za velike (javljaju se samo jednom i ima ih malo)
	ui hi = 20000;
	while (hi < n) {
		// hi + 1 ... hi + w
		int w = min(n - hi, 8388608u);

		memset(sito_buff, 0, sizeof(sito_buff));

		for (int p : prosti) {
			int j0 = p - (hi+1) % p;
			if (j0 == p)
				j0 = 0;

			while (j0 < w) {
				sito_buff[j0] = 1;
				j0 += p;
			}
		}

		for (int i=0; i<w; i++) {
			if (!sito_buff[i]) {
				ui p = i + hi + 1;

				sol += (a*p*p*p + b*p*p + c*p + d) * (n / p);
			}
		}

		hi += w;
	}

	cout << sol << '\n';
}