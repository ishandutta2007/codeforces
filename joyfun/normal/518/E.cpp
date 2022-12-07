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
#define lowbit(x) (x&(-x))
int n, k, a[N];
char s[N];
int tmp[N], tn;
int l[N], r[N];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		if (s[0] == '?') a[i] = inf;
		sscanf(s, "%d", &a[i]);
	}
	for (int i = 1; i <= k; i++) {
		int j = i;
		int pr = -2e9, nx;
		while (j <= n) {
			int jj = j;
			int cnt = 0;
			while (j <= n && a[j] == inf) j += k, cnt++;
			if (j > n) nx = 2e9;
			else nx = a[j];
			if (1ll * nx - pr - 1 < cnt) {
				printf("Incorrect sequence\n");
				return 0;
			}
			int md = cnt / 2;
			md = min(md, nx - 1); md = max(md, pr + cnt);
			pr = nx;
			for (int x = j - k; x >= jj; x -= k) {
				a[x] = md;
				md--;
			}
			j += k;
		}
	}
	for (int i = 1; i <= n; i++) printf("%d ", a[i]); printf("\n");
	return 0;
}