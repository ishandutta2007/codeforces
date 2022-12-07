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

const int N = 100005;
const int inf = 0x3f3f3f3f;
char a[N], b[N];
int g[30][30];
vi out;

int main() {
	scanf("%s%s", a + 1, b + 1);
	int n;
	scanf("%d\n", &n);
	char x, y;
	int w;
	memset(g, -1, sizeof(g));
	for (int i = 0; i < 26; i++) g[i][i] = 0;
	while (n--) {
		scanf("%c %c %d\n", &x, &y, &w);
		if (g[x - 'a'][y - 'a'] == -1) g[x - 'a'][y - 'a'] = w;
		else g[x - 'a'][y - 'a'] = min(g[x - 'a'][y - 'a'], w);
	}
	if (strlen(a + 1) != strlen(b + 1)) {
		printf("-1\n");
		return 0;
	}
	for (int k = 0; k < 26; k++) {
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < 26; j++) {
				if (g[i][k] == -1 || g[k][j] == -1) continue;
				if (g[i][j] == -1) g[i][j] = g[i][k] + g[k][j];
				else g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	n = strlen(a + 1);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = inf, sb;
		for (int j = 0; j < 26; j++) {
			if (g[a[i] - 'a'][j] == -1 || g[b[i] - 'a'][j] == -1) continue;
			if (tmp > g[a[i] - 'a'][j] + g[b[i] - 'a'][j]) {
				tmp = g[a[i] - 'a'][j] + g[b[i] - 'a'][j];
				sb = j;
			}
		}
		if (tmp == inf) {
			printf("-1\n");
			return 0;
		}
		ans += tmp;
		out.pb(sb);
	}
	printf("%lld\n", ans);
	for (int i = 0; i < sz(out); i++) printf("%c", out[i] + 'a'); printf("\n");
	return 0;
}