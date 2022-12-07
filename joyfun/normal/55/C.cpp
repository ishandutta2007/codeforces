#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 105;
int n, m, k;
int vis[N][N];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (min(min(min(i - 1, j - 1), n - i), m - j) <= 4) vis[i][j] = 1;
		}
	}
	int f = 0;
	while (k--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (vis[x][y]) f = 1;
	}
	printf("%s\n", f ? "YES" : "NO");
	return 0;
}