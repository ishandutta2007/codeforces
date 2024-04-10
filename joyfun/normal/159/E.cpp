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
const ll inf = (1ll<<60);
int n, c[N], s[N], h[N], hn;
vi g[N];
ll Max[N][2];
int Maxv[N][2];

bool cmp(int a, int b) {
	return s[a] > s[b];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &c[i], &s[i]);
		h[hn++] = c[i];
	}
	sort(h, h + hn); hn = unique(h, h + hn) - h;
	for (int i = 1; i <= n; i++) c[i] = lower_bound(h, h + hn, c[i]) - h;
	for (int i = 1; i <= n; i++) g[c[i]].pb(i);
	for (int i = 1; i <= n; i++) Max[i][0] = Max[i][1] = -inf;
	for (int i = 0; i < hn; i++) {
		sort(g[i].begin(), g[i].end(), cmp);
		ll sum = 0;
		for (int j = 0; j < sz(g[i]); j++) {
			sum += s[g[i][j]];
			if (sum > Max[j + 1][0]) {
				Max[j + 1][1] = Max[j + 1][0];
				Maxv[j + 1][1] = Maxv[j + 1][0];
				Max[j + 1][0] = sum;
				Maxv[j + 1][0] = i;
			} else if (sum > Max[j + 1][1]) {
				Max[j + 1][1] = sum;
				Maxv[j + 1][1] = i;
			}
		}
	}
	ll ans = 0;
	int a, b, c, d;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				for (int f = 0; f < 2; f++) {
					if (Maxv[i][j] != Maxv[i + f][k]) {
						if (ans < Max[i][j] + Max[i + f][k]) {
							ans = Max[i][j] + Max[i + f][k];
							a = i; b = i + f;
							c = j; d = k;
						}
					}
				}
			}
		}
	}
	printf("%lld\n", ans);
	int u = Maxv[a][c];
	int v = Maxv[b][d];
	printf("%d\n", a + b);
	for (int i = 0, j = 0, k = 0; i < a + b; i++) {
		if (i % 2 == 0) printf("%d ", g[v][j++]);
		else printf("%d ", g[u][k++]);
	}
	printf("\n");
	return 0;
}