#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll HI = 1'000'000'000;
const int SITO_MAX = 100;

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

int a[3000000], n;
unsigned char dp[3000000], sve[3000000];

void rek(ll q, int i) {
	a[n++] = q;
	for (int j=i; j<(int)prosti.size(); j++) {
		if (q * prosti[j] > HI)
			break;
		rek(q * prosti[j], j);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	rek(1, 0);
	sort(a, a+n);
	memset(dp, 0xfe, sizeof dp);
	memset(sve, 0xfe, sizeof sve);
	dp[0] = 0;
	sve[0] = 0;
	for (int i=2; i<=100; i++) {
		for (int j=0, k=0; j<n; j++) {
			while (k < n && a[j]*1ll*i > a[k])
				k++;
			if (k < n && a[k] == a[j]*1ll*i) {
				dp[k] = min(dp[k], (unsigned char)(dp[j] + 1));
			}
		}
		for (int j=0; j<n; j++) {
			int x = dp[j] + i;
			if (x < 256)
				sve[j] = min(sve[j], (unsigned char)x);
		}
	}

	int l, r, p, z=0;
	cin >> l >> r >> p;
	for (int i=0; i<n; i++)
		z += a[i] >= l && a[i] <= r && sve[i] <= p;
	cout << z << '\n';
}