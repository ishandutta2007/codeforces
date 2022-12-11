#include <bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define ucin() ios :: sync_with_stdio(0)
typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef double db;

const int N = 2e5 + 10;
const int M = 21;

int n, m, c[M][M], cnt[M], sa[1 << M], sn[1 << M], dp[M][1 << M];
char s[N], ns[N];

int main() {
	ucin();
	cin >> n >> m >> s + 1;
	int nn = 0;
	for(int i = 1; i <= n; i ++) {
		if(i == 1 || s[i] != s[i - 1]) {
			ns[++ nn] = s[i];
		}
	}
	ns[nn + 1] = 0; n = nn; copy(ns + 1, ns + nn + 1, s + 1);
	for(int i = 1; i <= n; i ++) {
		s[i] -= 'a';
		if(i > 1) c[s[i - 1]][s[i]] ++;
	}
	for(int i = 0; i < m; i ++)
		for(int j = 0; j < m; j ++)
			cnt[i] += c[i][j];
	for(int i = 0; i < (1 << m); i ++) {
		int k = -1;
		for(int j = 0; j < m; j ++) if(i >> j & 1) {
			sa[i] += cnt[j]; k = j;
		}
		if(k == -1) sn[i] = 0;
		else {
			sn[i] = sn[i ^ (1 << k)];
			for(int j = 0; j < m; j ++) if(i >> j & 1) {
				if(j != k) {
					sn[i] += c[j][k] + c[k][j];
				}
			}
		}
	}
	for(int i = 0; i < M; i ++) fill(dp[i], dp[i] + (1 << m), 4e8);
	for(int i = 0; i < m; i ++) dp[0][1 << i] = 0;
	int all = (1 << m) - 1;
	for(int i = 1; i < m; i ++) {
		for(int s = 0; s < (1 << m); s ++) if(dp[i - 1][s] < 4e8) {
			for(int j = 0; j < m; j ++) if(!(s >> j & 1)) {
				dp[i][s | (1 << j)] = min(dp[i][s | (1 << j)], dp[i - 1][s] + sa[s] + sa[all ^ s] - sn[s] - sn[all ^ s]);
			}
		}
	}
	printf("%d\n", dp[m - 1][all]);
	return 0;
}