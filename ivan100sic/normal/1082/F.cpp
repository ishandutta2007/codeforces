#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct node {
	int nx[10];
	int cnt, dub;
} pool[505];
int N = 1, K;

//     cvor podstabla 
//          visina gde obecavam pokrivanje
//               broj iskoriscenih
ll dp[505][505][13];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	memset(dp, 32, sizeof(dp));

	int t;
	cin >> t >> K;
	K++;
	for (int i=0; i<t; i++) {
		string s;
		int m;
		cin >> s >> m;

		int j = 1;
		for (char x : s) {
			int y = x - '0';
			// pool[j].cnt += m;
			if (pool[j].nx[y]) {
				j = pool[j].nx[y];
			} else {
				N++;
				pool[j].nx[y] = N;
				j = N;
			}
		}
		pool[j].cnt += m;
	}

	for (int i=N; i>=1; i--) {
		for (int h=0; h<=N; h++) {
			vector<ll> ol(K+1, 1123123123123123123ll);
			vector<ll> nu(K+1, 1123123123123123123ll);
			ol[0] = 0;

			for (int j=0; j<10; j++) {
				int y = pool[i].nx[j];
				if (y == 0)
					continue;

				fill(nu.begin(), nu.end(), 1123123123123123123ll);

				for (int k1=0; k1<=K; k1++) {
					for (int k2=0; k2<=K-k1; k2++) {
						nu[k1 + k2] = min(nu[k1 + k2], ol[k1] + dp[y][h+1][k2]);
						nu[k1 + k2] = min(nu[k1 + k2], ol[k1] + dp[y][0][k2]);
					}
				}

				swap(ol, nu);
			}

			int offs = !h;
			for (int k=0; k<=K-offs; k++)
				dp[i][h][k+offs] = ol[k] + h * pool[i].cnt;
		}
	}

	// for (int i=1; i<=N; i++)
	// 	for (int j=0; j<=N; j++)
	// 		cerr << i << ' ' << j << ' '
	// 			<< dp[i][j][0] << ' '
	// 			<< dp[i][j][1] << ' '
	// 			<< dp[i][j][2] << '\n';

	ll sol = *min_element(dp[1][0], dp[1][0] + K + 1);
	cout << sol << '\n';
}