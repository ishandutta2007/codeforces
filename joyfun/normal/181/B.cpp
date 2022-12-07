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

const int N = 3005;
int n, x[N], y[N];
int vis[2005][2005];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]), vis[x[i] + 1000][y[i] + 1000] = 1;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int dx = x[i] + x[j];
			int dy = y[i] + y[j];
			if (dx % 2 || dy % 2) continue;
			if (dx / 2 + 1000 > 2000 || dx / 2 + 1000 < 0 || dy / 2 + 1000 < 0 || dy / 2 + 1000 > 2000) continue;
			ans += vis[dx / 2 + 1000][dy / 2 + 1000];
		}
	}
	printf("%d\n", ans);
	return 0;
}