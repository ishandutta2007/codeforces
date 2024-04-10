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
int n, m;

struct ST {
	int l, r, c, id;
	ST() {}
	ST(int l, int r, int c, int id) : l(l), r(r), c(c), id(id) {}
	bool operator < (const ST& c) const {
		if (r != c.r) return r < c.r;
		return id < c.id;
	}
} a[N], b[N];

bool cmp(ST a, ST b) {
	return a.l < b.l;
}

int ans[N];

set<ST> S;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].l, &a[i].r), a[i].id = i;;
	sort(a + 1, a + 1 + n, cmp);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) scanf("%d%d%d", &b[i].l, &b[i].r, &b[i].c), b[i].id = i;
	sort(b + 1, b + 1 + m, cmp);
	int j = 1;
	for (int i = 1; i <= n; i++) {
		while (j <= m && b[j].l <= a[i].l) {
			S.insert(b[j]);
			j++;
		}
		set<ST>::iterator it = S.lower_bound(ST(0, a[i].r, 0, 0));
		if (it == S.end()) {
			printf("NO\n");
			return 0;
		}
		ans[a[i].id] = it->id;
		ST tmp = *it; 
		S.erase(it);
		tmp.c--;
		if (tmp.c) S.insert(tmp);
	}
	printf("YES\n");
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}