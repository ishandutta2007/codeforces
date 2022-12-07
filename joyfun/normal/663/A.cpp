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

char a[105], b[105];
int n, f[105], fn, ans[105];

int main() {
	int bo = 0;
	while (1) {
		if (!bo) {
			bo = 1;
			a[0] = '+';
			scanf("%s", b);
		} else scanf("%s%s", a, b);
		if (a[0] == '=') {
			sscanf(b, "%d", &n);
			break;
		}
		if (a[0] == '+') f[fn++] = 1;
		else f[fn++] = -1;
	}
	ll l = 0, r = 0;
	int tot = 0;
	for (int i = 0; i < fn; i++) {
		if (f[i] == 1) l++, r += n, ans[i] = 1, tot += 1;
		else l -= n, r--, ans[i] = n, tot -= n;
	}
	int nn = n;
	n -= tot;
	if (l <= nn && r >= nn) {
		printf("Possible\n");
		for (int i = 0; i < fn; i++) {
			int use = min((nn - 1), n);
			if (f[i] == 1) ans[i] += use;
			else ans[i] -= use;
			n -= use;
			if (n == 0) break;
		}
		for (int i = 0; i < fn; i++) {
			if (f[i] == 1 && i) printf("+ ");
			else if (f[i] == -1) printf("- ");
			printf("%d ", ans[i]);
		}
		printf("= %d\n", nn);
	} else printf("Impossible\n");
	return 0;
}