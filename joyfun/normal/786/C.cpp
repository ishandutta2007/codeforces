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
int n, a[N];

struct Nd {
	int sum, ls, rs;
} nd[N * 40];
int sz;

void add(int v, int w, int L, int R, int pr, int &x) {
	nd[++sz] = nd[pr]; x = sz; nd[x].sum += w;
	if (L == R) return;
	int mid = (L + R)>>1;
	if (v <= mid) add(v, w, L, mid, nd[pr].ls, nd[x].ls);
	else add(v, w, mid + 1, R, nd[pr].rs, nd[x].rs);
}

int pr[N], rt[N];

int get(int k, int L, int R, int x) {
	if (L == R) return L;
	int mid = (L + R)>>1;
	if (nd[nd[x].ls].sum < k) return get(k - nd[nd[x].ls].sum, mid + 1, R, nd[x].rs);
	return get(k, L, mid, nd[x].ls);
}

int sb[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &sb[i]);
	for (int i = n; i >= 1; i--) {
		int x = sb[i];
		if (!pr[x]) add(i, 1, 1, n + 1, rt[i + 1], rt[i]);
		else {
			add(pr[x], -1, 1, n + 1, rt[i + 1], rt[i]);
			add(i, 1, 1, n + 1, rt[i], rt[i]);
		}
		pr[x] = i;
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		int j = 1;
		while (j <= n) {
			cnt++;
			j = get(i + 1, 1, n + 1, rt[j]);
		}
		printf("%d ", cnt);
	}
	printf("\n");
	return 0;
}