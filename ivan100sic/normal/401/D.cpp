#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int c[10], b[11], m;
ll dp[500000][100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s >> m;
	for (char x : s)
		c[x - '0']++;

	// mesovita baza
	b[0] = 1;
	for (int i=1; i<=10; i++)
		b[i] = b[i-1] * (c[i-1] + 1);

	// dp
	dp[0][0] = 1;
	for (int mask=0; mask<b[10]; mask++) { // maska
		for (int i=0; i<10; i++) { // cifra koju dodajem
			// koliko ih imam sad
			int q = mask / b[i] % (c[i] + 1);
			// smem da dodam?
			if (q == c[i])
				continue;

			// ako nema nista ne smes da dodas nulu
			if (mask == 0 && i == 0)
				continue;

			// dodaj za svaki ostatak
			for (int rem=0; rem<m; rem++) {

				int mask2 = mask + b[i];
				int rem2 = (10*rem + i) % m;

				dp[mask2][rem2] += dp[mask][rem];
			}
		}
	}

	cout << dp[b[10] - 1][0] << '\n';
}