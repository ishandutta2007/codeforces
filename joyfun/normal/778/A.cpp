#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N = 200005;
char p[N], t[N];
int a[N], n, vis[N];

bool judge(int mid) {
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= mid; i++) vis[a[i]] = 1;
	int len = strlen(p + 1), j = 1;
	for (int i = 1; i <= len; i++) {
		while (j <= n && (vis[j] || t[j] != p[i])) j++;
		if (j == n + 1) return false;
		j++;
	}
	return true;
}

int main() {
	scanf("%s%s", t + 1, p + 1);
	n = strlen(t + 1);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int l = 1, r = n + 1;
	while (l < r) {
		int mid = (l + r)>>1;
		if (judge(mid)) l = mid + 1;
		else r = mid;
	}
	printf("%d\n", l - 1);
	return 0;
}