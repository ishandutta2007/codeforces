#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll mod = 998244353;

int N;
int par[1510], sz[1510], esz[1510];
ll dp[1510][1510], tmp[1510];
pii A[3000030];

int Find(int a) {
	if (par[a] == a) return a;
	return par[a] = Find(par[a]);
}
void Union(int a, int b) {
	if (Find(a) == Find(b)) esz[Find(a)]++;
	else {
		int sa = sz[Find(a)], sb = sz[Find(b)];
		for (int i=1; i<=sa+sb; i++) tmp[i] = 0;
		for (int i=1; i<=sa; i++) {
			for (int j=1; j<=sb; j++) {
				tmp[i+j] = (tmp[i+j] + dp[Find(a)][i] * dp[Find(b)][j]%mod)%mod;
			}
		}
		for (int i=1; i<=sa+sb; i++) dp[Find(a)][i] = tmp[i];

		sz[Find(a)] += sz[Find(b)];
		esz[Find(a)] += esz[Find(b)] + 1;
		par[Find(b)] = Find(a);
	}
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			int x; cin >> x;
			if (i < j) A[x] = pii(i, j);
		}
	}

	for (int i=1; i<=N; i++) {
		par[i] = i; sz[i] = 1; dp[i][1] = 1;
	}
	for (int k=1; k<=N*(N-1)/2; k++) {
		int u = A[k].va, v = A[k].vb;
		Union(u, v);
		if (esz[Find(u)] == sz[Find(u)] * (sz[Find(u)] - 1) / 2) dp[Find(u)][1] = 1;
	}

	for (int i=1; i<=N; i++) {
		cout << dp[Find(1)][i] << ' ';
	}
}