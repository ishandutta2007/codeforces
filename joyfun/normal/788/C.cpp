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

const int N = 2005;
int n, k, a[N], d[N], vis[N], an;
queue<int> Q;

int main() {
	scanf("%d%d", &n, &k);
	while (k--) {
		int x; scanf("%d", &x);
		vis[x - n + 1000] = 1;
	}
	for (int i = 0; i < N; i++) if (vis[i]) a[an++] = i - 1000;
	Q.push(1000);
	memset(d, -1, sizeof(d));
	for (int i = 0; i < an; i++) d[a[i] + 1000] = 1, Q.push(a[i] + 1000);
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		for (int i = 0; i < an; i++) {
			int v = u + a[i];
			if (v < 0 || v > 2000 || d[v] != -1) continue;
			d[v] = d[u] + 1;
			Q.push(v);
		}
	}
	printf("%d\n", d[1000]);
	return 0;
}