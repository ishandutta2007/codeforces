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
int n, h, a[N], id[N];

bool cmp(int x, int y) {
	return a[x] < a[y];
}

int out[N];

int main() {
	scanf("%d%d", &n, &h);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), id[i] = i;
	sort(id + 1, id + 1 + n, cmp);
	int a1 = a[id[n]] + a[id[n - 1]] - a[id[1]] - a[id[2]];
	int a2 = max(a[id[1]] + a[id[n]] + h, a[id[n]] + a[id[n - 1]]) - min(a[id[2]] + a[id[3]], a[id[1]] + a[id[2]] + h);
	for (int i = 1; i <= n; i++) out[i] = 2;
	if (a2 < a1) out[id[1]] = 1;
	printf("%d\n", min(a1, a2));
	for (int i = 1; i <= n; i++) printf("%d ", out[i]); printf("\n");
	return 0;
}