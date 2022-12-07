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

const int N = 1205;
int n, l[N], r[N];
int vis[N], v[N], to[N];
int out[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &l[i], &r[i]);
	memset(vis, 0, sizeof(vis));
	vis[1] = 1;
	for (int i = n; i >= 1; i--) {
		int f = 0;
		for (int j = l[i]; j <= r[i]; j++) {
			if (vis[j] == 1) {
				to[i] = j;
				memset(v, 0, sizeof(v));
				for (int k = j; k < N; k++) if (vis[k]) 
					v[k + 2] = 1;
				v[1] = 1;
				memcpy(vis, v, sizeof(vis));
				f = 1;
				break;
			}
		}
		if (!f) {
			printf("IMPOSSIBLE\n");
			return 0;
		}
	}
	int j = 1;
	memset(out, -1, sizeof(out));
	for (int i = 1; i <= n * 2; i++) {
		if (out[i] == -1) {
			out[i] = 0;
			out[i + to[j++]] = 1;
		}
	}
	for (int i = 1; i <= 2 * n; i++) printf("%c", out[i] ? ')' : '('); printf("\n");
	return 0;
}